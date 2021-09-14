/****************************************************************************************************************************
  Portenta_H7_WiFi.ino
  
  For Portenta_H7 boards using built-in

  WiFiManager_Portenta_H7_Lite is a library for the Portenta_H7 boards 
  (https://github.com/khoih-prog/WiFiManager_Portenta_H7_Lite) to enable store Credentials in LittleFS for easy 
  configuration/reconfiguration and autoconnect/autoreconnect of WiFi and other services without Hardcoding.

  Built by Khoi Hoang https://github.com/khoih-prog/WiFiManager_Portenta_H7_Lite
  Licensed under MIT license
  Version: 1.4.0

  Version Modified By   Date        Comments
  ------- -----------  ----------   -----------
  1.4.0   K Hoang      11/09/2021  Add support to Portenta_H7 using Arduino mbed_portenta core
  *****************************************************************************************************************************/

#ifdef CORE_CM7

#include "defines.h"
#include "Credentials.h"
#include "dynamicParams.h"

WiFiManager_Portenta_H7_Lite* WiFiManager_Portenta_H7;

void heartBeatPrint()
{
  static int num = 1;

  if (WiFi.status() == WL_CONNECTED)
    Serial.print(F("H"));        // H means connected to WiFi
  else
    Serial.print(F("F"));        // F means not connected to WiFi

  if (num == 80)
  {
    Serial.println();
    num = 1;
  }
  else if (num++ % 10 == 0)
  {
    Serial.print(F(" "));
  }
}

void check_status()
{
  static unsigned long checkstatus_timeout = 0;

  //KH
#define HEARTBEAT_INTERVAL    20000L
  // Print hearbeat every HEARTBEAT_INTERVAL (20) seconds.
  if ((millis() > checkstatus_timeout) || (checkstatus_timeout == 0))
  {
    heartBeatPrint();
    checkstatus_timeout = millis() + HEARTBEAT_INTERVAL;
  }
}

#if USING_CUSTOMS_STYLE
const char NewCustomsStyle[] /*PROGMEM*/ = "<style>div,input{padding:5px;font-size:1em;}input{width:95%;}body{text-align: center;}\
button{background-color:blue;color:white;line-height:2.4rem;font-size:1.2rem;width:100%;}fieldset{border-radius:0.3rem;margin:0px;}</style>";
#endif

void setup()
{
  // Debug console
  Serial.begin(115200);
  while (!Serial);

  delay(200);

  Serial.print(F("\nStart Portenta_H7_WiFi on ")); Serial.print(BOARD_NAME);
  Serial.print(F(" with ")); Serial.println(SHIELD_TYPE);
  Serial.println(WIFI_MANAGER_PORTENTA_H7_LITE_VERSION);

  WiFiManager_Portenta_H7 = new WiFiManager_Portenta_H7_Lite();

  // Optional to change default AP IP(192.168.4.1) and channel(10)
  //WiFiManager_Portenta_H7->setConfigPortalIP(IPAddress(192, 168, 120, 1));
  WiFiManager_Portenta_H7->setConfigPortalChannel(0);

#if USING_CUSTOMS_STYLE
  WiFiManager_Portenta_H7->setCustomsStyle(NewCustomsStyle);
#endif

#if USING_CUSTOMS_HEAD_ELEMENT
  WiFiManager_Portenta_H7->setCustomsHeadElement("<style>html{filter: invert(10%);}</style>");
#endif

#if USING_CORS_FEATURE  
  WiFiManager_Portenta_H7->setCORSHeader("Your Access-Control-Allow-Origin");
#endif

  // Set customized DHCP HostName
  WiFiManager_Portenta_H7->begin(HOST_NAME);
  //Or use default Hostname "-WIFI-XXXXXX"
  //WiFiManager_Portenta_H7->begin();
}

#if USE_DYNAMIC_PARAMETERS
void displayCredentials()
{
  Serial.println(F("\nYour stored Credentials :"));

  for (uint16_t i = 0; i < NUM_MENU_ITEMS; i++)
  {
    Serial.print(myMenuItems[i].displayName);
    Serial.print(F(" = "));
    Serial.println(myMenuItems[i].pdata);
  }
}

void displayCredentialsInLoop()
{
  static bool displayedCredentials = false;

  if (!displayedCredentials)
  {
    for (int i = 0; i < NUM_MENU_ITEMS; i++)
    {
      if (!strlen(myMenuItems[i].pdata))
      {
        break;
      }

      if ( i == (NUM_MENU_ITEMS - 1) )
      {
        displayedCredentials = true;
        displayCredentials();
      }
    }
  }
}

#endif

void loop()
{
  WiFiManager_Portenta_H7->run();
  check_status();

#if USE_DYNAMIC_PARAMETERS
  displayCredentialsInLoop();
#endif  
}

#endif
