/****************************************************************************************************************************
  FlashIAPLimits.h - Filesystem wrapper for LittleFS on the Mbed Portenta_H7
  
  For Portenta_H7 boards using built-in

  WiFiManager_Portenta_H7_Lite is a library for the Portenta_H7 boards 
  (https://github.com/khoih-prog/WiFiManager_Portenta_H7_Lite) to enable store Credentials in LittleFS for easy 
  configuration/reconfiguration and autoconnect/autoreconnect of WiFi and other services without Hardcoding.

  Built by Khoi Hoang https://github.com/khoih-prog/WiFiManager_Portenta_H7_Lite
  Licensed under MIT license
  Version: 1.5.0

  Version Modified By   Date        Comments
  ------- -----------  ----------   -----------
  1.4.0   K Hoang      11/09/2021  Add support to Portenta_H7 using Arduino mbed_portenta core
  1.4.1   K Hoang      12/10/2021  Update `platform.ini` and `library.json`
  1.5.0   K Hoang      08/01/2022  Workaround for core WiFi.status() bug. Fix the blocking issue in loop().
*****************************************************************************************************************************/

#pragma once

#ifndef _FlashIAPLimits_h_
#define _FlashIAPLimits_h_

#include <Arduino.h>
#include <FlashIAP.h>
#include <FlashIAPBlockDevice.h>

using namespace mbed;

// A helper struct for FlashIAP limits
struct FlashIAPLimits 
{
  size_t flash_size;
  uint32_t start_address;
  uint32_t available_size;
};

// Get the actual start address and available size for the FlashIAP Block Device
// considering the space already occupied by the sketch (firmware).
FlashIAPLimits getFlashIAPLimits()
{
  // Alignment lambdas
  auto align_down = [](uint64_t val, uint64_t size) 
  {
    return (((val) / size)) * size;
  };
  
  auto align_up = [](uint32_t val, uint32_t size) 
  {
    return (((val - 1) / size) + 1) * size;
  };

  FlashIAPLimits flashIAPLimits;
  
  uint32_t  flash_start_address;
  
  FlashIAP  flash;

  auto result = flash.init();
  
  if (result != 0)
    return { };

  // Find the start of first sector after text area
  int sector_size     = flash.get_sector_size(FLASHIAP_APP_ROM_END_ADDR);

  flash_start_address           = flash.get_flash_start();
  flashIAPLimits.start_address  = align_up(FLASHIAP_APP_ROM_END_ADDR, sector_size);
  flashIAPLimits.flash_size     = flash.get_flash_size();

  result = flash.deinit();

  flashIAPLimits.available_size = flash_start_address + flashIAPLimits.flash_size - flashIAPLimits.start_address;
  
  if (flashIAPLimits.available_size % (sector_size * 2)) 
  {
    flashIAPLimits.available_size = align_down(flashIAPLimits.available_size, sector_size * 2);
  }

  return flashIAPLimits;
}
#endif    // _FlashIAPLimits_h_
