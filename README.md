## WiFiManager_Portenta_H7_Lite (Light Weight Credentials / WiFi Manager for Portenta_H7 built-in Murata WiFi)

[![arduino-library-badge](https://www.ardu-badge.com/badge/WiFiManager_Portenta_H7_Lite.svg?)](https://www.ardu-badge.com/WiFiManager_Portenta_H7_Lite)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/WiFiManager_Portenta_H7_Lite.svg)](https://github.com/khoih-prog/WiFiManager_Portenta_H7_Lite/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/WiFiManager_Portenta_H7_Lite/blob/main/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/WiFiManager_Portenta_H7_Lite.svg)](http://github.com/khoih-prog/WiFiManager_Portenta_H7_Lite/issues)

<a href="https://www.buymeacoffee.com/khoihprog6" target="_blank"><img src="https://cdn.buymeacoffee.com/buttons/v2/default-yellow.png" alt="Buy Me A Coffee" style="height: 60px !important;width: 217px !important;" ></a>


---
---

## Table of Contents

* [Important Notes for Portenta_H7](#important-notes-for-portenta_h7)
  * [LittleFS](#littlefs)
  * [WiFi.status() bug](#wifistatus-bug)
  * [WiFi.begin() bug](#wifibegin-bug)
* [Why do we need this WiFiManager_Portenta_H7_Lite library](#why-do-we-need-this-WiFiManager_Portenta_H7_Lite-library)
  * [Features](#features)
  * [Currently supported Boards](#currently-supported-boards)
  * [Currently supported WiFi shields/modules](#currently-supported-wifi-shieldsmodules)
* [Changelog](changelog.md) 
* [Prerequisites](#prerequisites)
* [Installation](#installation)
  * [Use Arduino Library Manager](#use-arduino-library-manager)
  * [Manual Install](#manual-install)
  * [VS Code & PlatformIO](#vs-code--platformio)
* [Packages' Patches](#packages-patches)
  * [1. For Portenta_H7 boards using Arduino IDE in Linux](#1-for-portenta_h7-boards-using-arduino-ide-in-linux)
* [How It Works](#how-it-works)
* [How to use](#how-to-use)
  * [ 1. Basic usage](#1-basic-usage)
  * [ 2. Add custom parameters](#2-add-custom-parameters)
  * [ 3. Not using custom parameters](#3-not-using-custom-parameters)
  * [ 4. To open Config Portal](#4-to-open-config-portal)
  * [ 5. To use different AP WiFi Channel](#5-to-use-different-ap-wifi-channel)
  * [ 6. To use different static AP IP from default](#6-to-use-different-static-ap-ip-from-default)
  * [ 7. To use custom DHCP HostName](#7-to-use-custom-dhcp-hostname)
  * [ 8. To use custom HTML Style](#8-to-use-custom-html-style)
  * [ 9. To use custom Head Elements](#9-to-use-custom-head-elements)
  * [10. To use CORS Header](#10-to-use-cors-header)
  * [11. To use and input only one set of WiFi SSID and PWD](#11-to-use-and-input-only-one-set-of-wifi-ssid-and-pwd)
    * [11.1 If you need to use and input only one set of WiFi SSID/PWD](#111-if-you-need-to-use-and-input-only-one-set-of-wifi-ssidpwd)
    * [11.2 If you need to use both sets of WiFi SSID/PWD](#112-if-you-need-to-use-both-sets-of-wifi-ssidpwd)
  * [12. To enable auto-scan of WiFi networks for selection in Configuration Portal](#12-to-enable-auto-scan-of-wifi-networks-for-selection-in-configuration-portal)
    * [12.1 Enable auto-scan of WiFi networks for selection in Configuration Portal](#121-enable-auto-scan-of-wifi-networks-for-selection-in-configuration-portal)
    * [12.2 Disable manually input SSIDs](#122-disable-manually-input-ssids)
    * [12.3 Select maximum number of SSIDs in the list](#123-select-maximum-number-of-ssids-in-the-list)
  * [13. To avoid blocking in loop when WiFi is lost](#13-To-avoid-blocking-in-loop-when-wifi-is-lost)
    * [13.1 Max times to try WiFi per loop](#131-max-times-to-try-wifi-per-loop)
    * [13.2 Interval between reconnection WiFi if lost](#132-interval-between-reconnection-wifi-if-lost) 
* [Examples](#examples)
  * [ 1. Portenta_H7_WiFi](examples/Portenta_H7_WiFi)
  * [ 2. Portenta_H7_WiFi_MQTT](examples/Portenta_H7_WiFi_MQTT)
* [So, how it works?](#so-how-it-works)
  * [1. Without SCAN_WIFI_NETWORKS](#1-without-scan_wifi_networks)
  * [2. With SCAN_WIFI_NETWORKS](#2-with-scan_wifi_networks)
* [Important Notes](#important-notes)
* [How to use default Credentials and have them pre-loaded onto Config Portal](#how-to-use-default-credentials-and-have-them-pre-loaded-onto-config-portal)
  * [1. To always load Default Credentials and override Config Portal data](#1-to-always-load-default-credentials-and-override-config-portal-data)
  * [2. To load Default Credentials when there is no valid Credentials](#2-to-load-default-credentials-when-there-is-no-valid-credentials)
  * [3. Example of Default Credentials](#3-example-of-default-credentials)
* [How to add dynamic parameters from sketch](#how-to-add-dynamic-parameters-from-sketch)
* [Important Notes for using Dynamic Parameters' ids](#important-notes-for-using-dynamic-parameters-ids)
* [Example Portenta_H7_WiFi](#example-Portenta_H7_WiFi)
  * [1. File Portenta_H7_WiFi.ino](#1-file-Portenta_H7_WiFiino)
  * [2. File defines.h](#2-file-definesh)
  * [3. File Credentials.h](#3-file-credentialsh)
  * [4. File dynamicParams.h](#4-file-dynamicparamsh)
* [Debug Terminal Output Samples](#debug-terminal-output-samples)
  * [1. Portenta_H7_WiFi example on Portenta_H7](#1-portenta_h7_wifi-example-on-portenta_h7) 
    * [1.1 Open Config Portal](#11-open-config-portal)
    * [1.2 Got valid Credential from Config Portal, then connected to WiFi](#12-got-valid-credential-from-config-portal-then-connected-to-wifi)
  * [2. Portenta_H7_WiFi_MQTT on Portenta_H7](#2-portenta_h7_wifi_mqtt-on-portenta_h7) 
    * [2.1 Open Config Portal](#21-open-config-portal)
    * [2.2 Got valid Credential from Config Portal, then connected to WiFi and AIO MQTT](#22-got-valid-credential-from-config-portal-then-connected-to-wifi-and-aio-mqtt)
* [Debug](#debug)
* [Troubleshooting](#troubleshooting)
* [Issues](#issues)
* [TO DO](#to-do)
* [DONE](#done)
* [Contributions and Thanks](#contributions-and-thanks)
* [Contributing](#contributing)
* [License](#license)
* [Copyright](#copyright)

---
---

### Important Notes for Portenta_H7

#### LittleFS

The LittleFS of the new **Portenta_H7** board currently tested OK with only **maximum 8 files**. The files, from 9 and up, somehow strangely can't be written and / or read. This is possibly a bug in the [`ArduinoCore-mbed mbed_portenta core`](https://github.com/arduino/ArduinoCore-mbed). The same behaviour is observed from core v2.0.0 up to v2.5.2.

If LittleFS size is reduced to 1024KB, test is OK with only **maximum 4 files**.

Beware and keep checking for updates.

#### WiFi.status() bug

The current `mbed_portenta core v2.6.1` has bug that once WiFi is connected, `WiFi.status()` always reports `WL_CONNECTED` even if WiFi is lost.

The current workaround for this `WiFi.status()` bug is to use it with `WiFi.RSSI()`, such as 

```
bool WiFiConnected()
{
  return ( (WiFi.status() == WL_CONNECTED) && (WiFi.RSSI() != 0) );
}
```

This not-100%-perfect workaround is working only whenever the **WiFi is totally powered down (RSSI == 0)**, but still better than nothing.

Check 

- [WiFi.status() wrongly reports WL_CONNECTED even when WiFi is lost #381](https://github.com/arduino/ArduinoCore-mbed/issues/381)


#### WiFi.begin() bug

The current `mbed_portenta core v2.6.1` has bug that once WiFi is connected and lost, `WiFi.begin()` can't never reconnect even if WiFi is restored.

The current fix for this bug is to use `WiFi.end()` before `WiFi.begin()`, such as 

```
// Must have to reconnect after WiFi lost
WiFi.end();
  
// Now WiFi.begin() can reconnect to WiFi after lost and restored  
status = WiFi.begin(ssid, pass);
```

Check:

- [WiFi.begin() can't reconnect after WiFi lost, then restored #382](https://github.com/arduino/ArduinoCore-mbed/issues/382)

---
---

### Why do we need this [WiFiManager_Portenta_H7_Lite library](https://github.com/khoih-prog/WiFiManager_Portenta_H7_Lite)

#### Features

If you have used the full-fledge WiFiManager such as :

1. [`Tzapu WiFiManager`](https://github.com/tzapu/WiFiManager)
2. [`Ken Taylor WiFiManager`](https://github.com/kentaylor/WiFiManager)
3. [`Khoi Hoang ESP_WiFiManager`](https://github.com/khoih-prog/ESP_WiFiManager)

and have to write **complicated callback functions** to save custom parameters in SPIFFS/LittleFS/EEPROM, you'd appreciate the simplicity of this Light-Weight Credentials / WiFiManager.

This library is a Light Weight Credentials / WiFi Manager for **Portenta_H7** built-in WiFi (Murata) modules/shields, specially designed to support **Portenta_H7 running on M7 core**.

This is a Credentials / WiFi Connection Manager, permitting the addition of custom parameters to be configured in Config Portal. The parameters then will be saved automatically, **without the complicated callback functions** to handle data saving / retrieving.

You can also specify DHCP HostName, static AP and STA IP. Use much less memory compared to full-fledge WiFiManager. Config Portal will be auto-adjusted to match the number of dynamic custom parameters. Credentials are saved in LittleFS, shared with [**DoubleResetDetector_Generic** library](https://github.com/khoih-prog/DoubleResetDetector_Generic).

The web configuration portal, served from the `Generic WiFi modules/shields` is operating as an access point (AP) with configurable static IP address or use default IP Address of 192.168.4.1

New recent features:

- **MultiWiFi** feature for configuring/auto(re)connecting **Portenta WiFi** shields to the available MultiWiFi APs at runtime.
- **DoubleDetectDetector** feature to force Config Portal when double reset is detected within predetermined time, default 10s.
- **Powerful-yet-simple-to-use feature to enable adding dynamic custom parameters** from sketch and input using the same Config Portal. Config Portal will be auto-adjusted to match the number of dynamic parameters.
- Optional default **Credentials as well as Dynamic parameters to be optionally autoloaded into Config Portal** to use or change instead of manually input.
- Dynamic custom parameters to be saved **automatically in non-volatile LittleeFS memory**.
- Configurable **Config Portal Title** to be either BoardName or default undistinguishable names.
- Examples are designed to separate Credentials / Defines / Dynamic Params / Code so that you can change Credentials / Dynamic Params quickly for each device.
- Control Config Portal from software or Virtual Switches
- To permit autoreset after configurable timeout if DRD/MRD or non-persistent forced-CP
- Use new Portenta_H7 LittleFS features
- **Scan WiFi networks** for selection in Configuration Portal

---

#### Currently supported Boards

This [**WiFiManager_Portenta_H7_Lite** library](https://github.com/khoih-prog/WiFiManager_Portenta_H7_Lite) currently supports these following boards:

 1. **Portenta_H7** boards, using [`ArduinoCore-mbed mbed_portenta core`](https://github.com/arduino/ArduinoCore-mbed)

---

#### Currently supported WiFi shields/modules

1. Portenta_H7 built-in Murata WiFi

---
---


## Prerequisites

1. [`Arduino IDE 1.8.19+` for Arduino](https://github.com/arduino/Arduino). [![GitHub release](https://img.shields.io/github/release/arduino/Arduino.svg)](https://github.com/arduino/Arduino/releases/latest)
2. [`ArduinoCore-mbed mbed_portenta core 2.6.1+`](https://github.com/arduino/ArduinoCore-mbed) for Arduino **Portenta_H7** boards, such as **Portenta_H7 Rev2 ABX00042, etc.**. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-mbed.svg)](https://github.com/arduino/ArduinoCore-mbed/releases/latest)


3. [`Functional-Vlpp library v1.0.2+`](https://github.com/khoih-prog/functional-vlpp) to use server's lambda function. To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/Functional-Vlpp.svg?)](https://www.ardu-badge.com/Functional-Vlpp)
4. [`WiFiWebServer library v1.5.5-1+`](https://github.com/khoih-prog/WiFiWebServer). To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/WiFiWebServer.svg?)](https://www.ardu-badge.com/WiFiWebServer)
5. [`LittleFS_Portenta_H7 v1.1.0+`](https://github.com/khoih-prog/LittleFS_Portenta_H7). To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/LittleFS_Portenta_H7.svg?)](https://www.ardu-badge.com/LittleFS_Portenta_H7)
6. [`DoubleResetDetector_Generic v1.8.0+`](https://github.com/khoih-prog/DoubleResetDetector_Generic). To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/DoubleResetDetector_Generic.svg?)](https://www.ardu-badge.com/DoubleResetDetector_Generic)

---

## Installation

### Use Arduino Library Manager

The best and easiest way is to use `Arduino Library Manager`. Search for [**WiFiManager_Portenta_H7_Lite**](https://github.com/khoih-prog/WiFiManager_Portenta_H7_Lite), then select / install the latest version.
You can also use this link [![arduino-library-badge](https://www.ardu-badge.com/badge/WiFiManager_Portenta_H7_Lite.svg?)](https://www.ardu-badge.com/WiFiManager_Portenta_H7_Lite) for more detailed instructions.

### Manual Install

1. Navigate to [**WiFiManager_Portenta_H7_Lite**](https://github.com/khoih-prog/WiFiManager_Portenta_H7_Lite) page.
2. Download the latest release `WiFiManager_Portenta_H7_Lite-main.zip`.
3. Extract the zip file to `WiFiManager_Portenta_H7_Lite-main` directory 
4. Copy the whole 
  - `WiFiManager_Portenta_H7_Lite-main` folder to Arduino libraries' directory such as `~/Arduino/libraries/`.

### VS Code & PlatformIO:

1. Install [VS Code](https://code.visualstudio.com/)
2. Install [PlatformIO](https://platformio.org/platformio-ide)
3. Install [**WiFiManager_Portenta_H7_Lite** library](https://platformio.org/lib/show/12823/WiFiManager_Portenta_H7_Lite) by using [Library Manager](https://platformio.org/lib/show/12823/WiFiManager_Portenta_H7_Lite/installation). Search for **WiFiManager_Portenta_H7_Lite** in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)

---
---

### Packages' Patches

#### 1. For Portenta_H7 boards using Arduino IDE in Linux

  **To be able to upload firmware to Portenta_H7 using Arduino IDE in Linux (Ubuntu, etc.)**, you have to copy the file [portenta_post_install.sh](Packages_Patches/arduino/hardware/mbed_portenta/2.6.1/portenta_post_install.sh) into mbed_portenta directory (~/.arduino15/packages/arduino/hardware/mbed_portenta/2.6.1/portenta_post_install.sh). 
  
  Then run the following command using `sudo`
  
```
$ cd ~/.arduino15/packages/arduino/hardware/mbed_portenta/2.6.1
$ chmod 755 portenta_post_install.sh
$ sudo ./portenta_post_install.sh
```

This will create the file `/etc/udev/rules.d/49-portenta_h7.rules` as follows:

```
# Portenta H7 bootloader mode UDEV rules

SUBSYSTEMS=="usb", ATTRS{idVendor}=="2341", ATTRS{idProduct}=="035b", GROUP="plugdev", MODE="0666"
```

Supposing the ArduinoCore-mbed core version is 2.6.1. Now only one file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/mbed_portenta/2.6.1/portenta_post_install.sh`

Whenever a new version is installed, remember to copy this files into the new version directory. For example, new version is x.yy.zz

This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/mbed_portenta/x.yy.zz/portenta_post_install.sh`


---
---

## How It Works

- The [**Portenta_H7_WiFi**](examples/Portenta_H7_WiFi) example shows how it works and should be used as the basis for a sketch that uses this library.
- The concept of [**Portenta_H7_WiFi**](examples/Portenta_H7_WiFi) is that a new `WiFi module/shield` will start a WiFi configuration portal when powered up, but has no valid stored Credentials or can't connect to WiFi APs after a pre-determined time.
- There are 6 more custom parameters added in the sketch which you can use in your program later. In the example, they are: 2 sets of Blynk Servers and Tokens, Blynk Port and MQTT Server.
- Using any WiFi enabled device with a browser (computer, phone, tablet) connect to the newly created AP and type in the configurable AP IP address (default 192.168.4.1). The Config Portal AP channel (default 10) is also configurable to avoid conflict with other APs.
- The Config Portal is **auto-adjusted** to fix the 4 static parameters (WiFi SSIDs/PWDs) as well as 6 more dynamic custom parameters.
- After the custom data entered, and **Save** button pressed, the configuration data will be saved in host's non-volatile memory, then the board reboots.
- If there is valid stored Credentials, it'll go directly to connect to one of the **MultiWiFi APs** without starting / using the Config Portal.
- `Generic WiFi module/shield` will try to connect. If successful, the dynamic DHCP and/or configured static IP address will be displayed in the configuration portal. 
- The `Generic WiFi module/shield` WiFi Config Portal network and Web Server will shutdown to return control to the sketch code.
- In the operation, if the current WiFi connection is lost because of any reason, the system will **auto(Re)connect** to the remaining WiFi AP.
- **If system can't connect to any of the 2 WiFi APs, the Config Portal will start**, after some pre-determined time, to permit user to update the Credentials.

---

### How to use

#### 1. Basic usage

- Include in your sketch

```cpp
#include <WiFiManager_Portenta_H7_Lite.h>

WiFiManager_Portenta_H7_Lite* WiFiManager_Portenta_H7;
```

#### 2. Add custom parameters

- To add custom parameters, just add

```
#include "defines.h"

// USE_DYNAMIC_PARAMETERS defined in defines.h

/////////////// Start dynamic Credentials ///////////////

//Defined in <WiFiManager_Portenta_H7_Lite.h>
/**************************************
  #define MAX_ID_LEN                5
  #define MAX_DISPLAY_NAME_LEN      16

  typedef struct
  {
  char id             [MAX_ID_LEN + 1];
  char displayName    [MAX_DISPLAY_NAME_LEN + 1];
  char *pdata;
  uint8_t maxlen;
  } MenuItem;
**************************************/

#if USE_DYNAMIC_PARAMETERS

#define MAX_BLYNK_SERVER_LEN      34
#define MAX_BLYNK_TOKEN_LEN       34

char Blynk_Server1 [MAX_BLYNK_SERVER_LEN + 1]  = "account.duckdns.org";
char Blynk_Token1  [MAX_BLYNK_TOKEN_LEN + 1]   = "token1";

char Blynk_Server2 [MAX_BLYNK_SERVER_LEN + 1]  = "account.ddns.net";
char Blynk_Token2  [MAX_BLYNK_TOKEN_LEN + 1]   = "token2";

#define MAX_BLYNK_PORT_LEN        6
char Blynk_Port   [MAX_BLYNK_PORT_LEN + 1]  = "8080";

#define MAX_MQTT_SERVER_LEN      34
char MQTT_Server  [MAX_MQTT_SERVER_LEN + 1]   = "mqtt.duckdns.org";

MenuItem myMenuItems [] =
{
  { "sv1", "Blynk Server1", Blynk_Server1,  MAX_BLYNK_SERVER_LEN },
  { "tk1", "Token1",        Blynk_Token1,   MAX_BLYNK_TOKEN_LEN },
  { "sv2", "Blynk Server2", Blynk_Server2,  MAX_BLYNK_SERVER_LEN },
  { "tk2", "Token2",        Blynk_Token2,   MAX_BLYNK_TOKEN_LEN },
  { "prt", "Port",          Blynk_Port,     MAX_BLYNK_PORT_LEN },
  { "mqt", "MQTT Server",   MQTT_Server,    MAX_MQTT_SERVER_LEN },
};

uint16_t NUM_MENU_ITEMS = sizeof(myMenuItems) / sizeof(MenuItem);  //MenuItemSize;

#else

MenuItem myMenuItems [] = {};

uint16_t NUM_MENU_ITEMS = 0;

#endif    //USE_DYNAMIC_PARAMETERS

```

#### 3. Not using custom parameters

- If you don't need to add dynamic parameters, use the following in sketch

```
#define USE_DYNAMIC_PARAMETERS      false
```

#### 4. To open Config Portal

- When you want to open a config portal, just add

```cpp
WiFiManager_Portenta_H7 = new WiFiManager_Portenta_H7_Lite();
WiFiManager_Portenta_H7->begin();
```

#### 5. To use different AP WiFi Channel

- To not use default AP WiFi Channel 10 to avoid conflict with other WiFi APs : 

```cpp
WiFiManager_Portenta_H7->setConfigPortalChannel(newChannel);
```

- To use random AP WiFi Channel to avoid conflict with other WiFi APs : 

```cpp
WiFiManager_Portenta_H7->setConfigPortalChannel(0);
```

#### 6. To use different static AP IP from default

- To use different static AP IP (not use default `192.168.4.1`), call

```cpp
WiFiManager_Portenta_H7->setConfigPortalIP(IPAddress(xxx,xxx,xxx,xxx));
```

#### 7. To use custom DHCP HostName

- To set custom DHCP HostName :
 
```
// Set customized DHCP HostName
WiFiManager_Portenta_H7->begin("SAMD_ABCDEF");
```
 
or just use the default Hostname, for example "SAMD_XXXXXX" for SAMD

```
//Or use default Hostname "WIFI_GENERIC_XXXXXX"
//WiFiManager_Portenta_H7->begin();
```

#### 8. To use custom HTML Style

```
const char NewCustomsStyle[] /*PROGMEM*/ = "<style>div,input{padding:5px;font-size:1em;}input{width:95%;}body{text-align: center;}\
button{background-color:blue;color:white;line-height:2.4rem;font-size:1.2rem;width:100%;}fieldset{border-radius:0.3rem;margin:0px;}</style>";

...

WiFiManager_Portenta_H7->setCustomsStyle(NewCustomsStyle);
```

#### 9. To use custom Head Elements


```
WiFiManager_Portenta_H7->setCustomsHeadElement("<style>html{filter: invert(10%);}</style>");
```

#### 10. To use CORS Header

```
WiFiManager_Portenta_H7->setCORSHeader("Your Access-Control-Allow-Origin");
```

While in AP mode, connect to it using its `SSID` (WIFI_GENERIC_XXXXXX) / `Password` ("MyWIFI_GENERIC_XXXXXX"), then open a browser to the Portal AP IP, default `192.168.4.1`, configure wifi then click **Save**. The Credentials / WiFi connection information will be saved in non-volatile memory. It will then autoconnect.


Once Credentials / WiFi network information is saved in the host non-volatile memory, it will try to autoconnect to WiFi every time it is started, without requiring any function calls in the sketch.


#### 11. To use and input only one set of WiFi SSID and PWD

#### 11.1 If you need to use and input only one set of WiFi SSID/PWD

```
// Permit input only one set of WiFi SSID/PWD. The other can be "NULL or "blank"
// Default is false (if not defined) => must input 2 sets of SSID/PWD
#define REQUIRE_ONE_SET_SSID_PW       true
```
But it's always advisable to use and input both sets for reliability.
 
#### 11.2 If you need to use both sets of WiFi SSID/PWD

```
// Permit input only one set of WiFi SSID/PWD. The other can be "NULL or "blank"
// Default is false (if not defined) => must input 2 sets of SSID/PWD
#define REQUIRE_ONE_SET_SSID_PW       false
```

#### 12. To enable auto-scan of WiFi networks for selection in Configuration Portal

#### 12.1 Enable auto-scan of WiFi networks for selection in Configuration Portal


```
#define SCAN_WIFI_NETWORKS                  true
```

The manual input of SSIDs is default enabled, so that users can input arbitrary SSID, not only from the scanned list. This is for the sample use-cases in which users can input the known SSIDs of another place, then send the boards to that place. The boards can connect to WiFi without users entering Config Portal to re-configure.

#### 12.2 Disable manually input SSIDs

```
// To disable manually input SSID, only from a scanned SSID lists
#define MANUAL_SSID_INPUT_ALLOWED           false
```

This is for normal use-cases in which users can only select an SSID from a scanned list of SSIDs to avoid typo mistakes and/or security.

#### 12.3 Select maximum number of SSIDs in the list

The maximum number of SSIDs in the list is selectable from 2 to 15 (for ESP8266/ESP32-AT shields, from 2-6). If invalid number of SSIDs is selected, the default number of 10 will be used.


```
// From 2-15
#define MAX_SSID_IN_LIST                    8
```

#### 13. To avoid blocking in loop when WiFi is lost


#### 13.1 Max times to try WiFi per loop

To define max times to try WiFi per loop() iteration. To avoid blocking issue in loop()

Default is 1 if not defined, and minimum is forced to be 1.

To use, uncomment in `defines.h`. 

Check [retries block the main loop #18](https://github.com/khoih-prog/WiFiManager_NINA_Lite/issues/18#issue-1094004380)

```
#define MAX_NUM_WIFI_RECON_TRIES_PER_LOOP     2
```

#### 13.2 Interval between reconnection WiFi if lost

Default is no interval between reconnection WiFi times if lost WiFi. Max permitted interval will be 10mins.

Uncomment to use. Be careful, WiFi reconnection will be delayed if using this method.

Only use whenever urgent tasks in loop() can't be delayed. But if so, it's better you have to rewrite your code, e.g. using higher priority tasks.

Check [retries block the main loop #18](https://github.com/khoih-prog/WiFiManager_NINA_Lite/issues/18#issuecomment-1006197561)

```
#define WIFI_RECON_INTERVAL                   30000     // 30s
```



---
---

### Examples

 1. [Portenta_H7_WiFi](examples/Portenta_H7_WiFi)
 2. [Portenta_H7_WiFi_MQTT](examples/Portenta_H7_WiFi_MQTT)
 
---
---

## So, how it works?

In `Configuration Portal Mode`, it starts an AP called `WIFI_GENERIC_XXXXXX`. Connect to it using the `configurable password` you can define in the code. For example, `MyWIFI_GENERIC_XXXXXX` (see examples):

After you connected, please, go to http://192.168.4.1 or newly configured AP IP, you'll see this `Main` page:

<p align="center">
    <img src="https://github.com/khoih-prog/WiFiManager_Portenta_H7_Lite/blob/main/pics/Main.png">
</p>

Enter your credentials, 

### 1. Without SCAN_WIFI_NETWORKS

<p align="center">
    <img src="https://github.com/khoih-prog/WiFiManager_Portenta_H7_Lite/blob/main/pics/Input.png">
</p>

### 2. With SCAN_WIFI_NETWORKS


<p align="center">
    <img src="https://github.com/khoih-prog/WiFiManager_Portenta_H7_Lite/blob/main/pics/Input_With_Scan.png">
</p>


then click `Save`. 

<p align="center">
    <img src="https://github.com/khoih-prog/WiFiManager_Portenta_H7_Lite/blob/main/pics/Save.png">
</p>

The WiFi Credentials will be saved and the board connect to the selected WiFi AP.

If you're already connected to a listed WiFi AP and don't want to change anything, just select `Exit` from the `Main` page to reboot the board and connect to the previously-stored AP. The WiFi Credentials are still intact.

---

### Important Notes

1. Now you can use special chars such as **~, !, @, #, $, %, ^, &, _, -, space,etc.** thanks to [brondolin](https://github.com/brondolin) to provide the amazing fix in [**Blynk_WM**](https://github.com/khoih-prog/Blynk_WM) to permit input special chars such as **%** and **#** into data fields. See [Issue 3](https://github.com/khoih-prog/Blynk_WM/issues/3).
2. The SSIDs, Passwords must be input (or to make them different from **blank**). Otherwise, the Config Portal will re-open until those fields have been changed. If you don't need any field, just input anything or use duplicated data from similar field.
3. WiFi password max length now is 63 chars according to WPA2 standard.

---

### How to use default Credentials and have them pre-loaded onto Config Portal

See this example and modify as necessary

#### 1. To always load [Default Credentials](examples/Portenta_H7_WiFi/Credentials.h) and override Config Portal data

```
// Used mostly for development and debugging. FORCES default values to be loaded each run.
// Config Portal data input will be ignored and overridden by DEFAULT_CONFIG_DATA
bool LOAD_DEFAULT_CONFIG_DATA = true;
```

#### 2. To load [Default Credentials](examples/Portenta_H7_WiFi/Credentials.h) when there is no valid Credentials.

Config Portal data input will be override DEFAULT_CONFIG_DATA

```
// Used mostly once debugged. Assumes good data already saved in device.
// Config Portal data input will be override DEFAULT_CONFIG_DATA
bool LOAD_DEFAULT_CONFIG_DATA = false;
```

#### 3. Example of [Default Credentials](examples/Portenta_H7_WiFi/Credentials.h)

```cpp
/// Start Default Config Data //////////////////

/*
#define SSID_MAX_LEN      32
//From v1.0.3, WPA2 passwords can be up to 63 characters long.
#define PASS_MAX_LEN      64

typedef struct
{
  char wifi_ssid[SSID_MAX_LEN];
  char wifi_pw  [PASS_MAX_LEN];
}  WiFi_Credentials;

#define NUM_WIFI_CREDENTIALS      2

// Configurable items besides fixed Header, just add board_name 
#define NUM_CONFIGURABLE_ITEMS    ( ( 2 * NUM_WIFI_CREDENTIALS ) + 1 )
////////////////

typedef struct Configuration
{
  char header         [16];
  WiFi_Credentials  WiFi_Creds  [NUM_WIFI_CREDENTIALS];
  char board_name     [24];
  int  checkSum;
} WIFI_GENERIC_Configuration;
*/

#define TO_LOAD_DEFAULT_CONFIG_DATA      false

#if TO_LOAD_DEFAULT_CONFIG_DATA

// This feature is primarily used in development to force a known set of values as Config Data
// It will NOT force the Config Portal to activate. Use DRD or erase Config Data with Blynk.clearConfigData()

// Used mostly for development and debugging. FORCES default values to be loaded each run.
// Config Portal data input will be ignored and overridden by DEFAULT_CONFIG_DATA
//bool LOAD_DEFAULT_CONFIG_DATA = true;

// Used mostly once debugged. Assumes good data already saved in device.
// Config Portal data input will be override DEFAULT_CONFIG_DATA
bool LOAD_DEFAULT_CONFIG_DATA = false;


WIFI_GENERIC_Configuration defaultConfig =
{
  //char header[16], dummy, not used
  "Portenta_WIFI",
  // WiFi_Credentials  WiFi_Creds  [NUM_WIFI_CREDENTIALS];
  // WiFi_Credentials.wifi_ssid and WiFi_Credentials.wifi_pw
  "SSID1",  "password1",
  "SSID2",  "password2",
  //char board_name     [24];
  "Portenta-H7-Control",
  // terminate the list
  //int  checkSum, dummy, not used
  0
  /////////// End Default Config Data /////////////
};

#else

bool LOAD_DEFAULT_CONFIG_DATA = false;

WIFI_GENERIC_Configuration defaultConfig;

#endif    // TO_LOAD_DEFAULT_CONFIG_DATA

/////////// End Default Config Data /////////////
```

### How to add dynamic parameters from sketch

Example of [Default dynamicParams](examples/Portenta_H7_WiFi/dynamicParams.h)

- To add custom parameters, just modify the example below

```
#include "defines.h"

// USE_DYNAMIC_PARAMETERS defined in defines.h

/////////////// Start dynamic Credentials ///////////////

//Defined in <WiFiManager_Portenta_H7_Lite.h>
/**************************************
  #define MAX_ID_LEN                5
  #define MAX_DISPLAY_NAME_LEN      16

  typedef struct
  {
  char id             [MAX_ID_LEN + 1];
  char displayName    [MAX_DISPLAY_NAME_LEN + 1];
  char *pdata;
  uint8_t maxlen;
  } MenuItem;
**************************************/

#if USE_DYNAMIC_PARAMETERS

#define MAX_BLYNK_SERVER_LEN      34
#define MAX_BLYNK_TOKEN_LEN       34

char Blynk_Server1 [MAX_BLYNK_SERVER_LEN + 1]  = "account.duckdns.org";
char Blynk_Token1  [MAX_BLYNK_TOKEN_LEN + 1]   = "token1";

char Blynk_Server2 [MAX_BLYNK_SERVER_LEN + 1]  = "account.ddns.net";
char Blynk_Token2  [MAX_BLYNK_TOKEN_LEN + 1]   = "token2";

#define MAX_BLYNK_PORT_LEN        6
char Blynk_Port   [MAX_BLYNK_PORT_LEN + 1]  = "8080";

#define MAX_MQTT_SERVER_LEN      34
char MQTT_Server  [MAX_MQTT_SERVER_LEN + 1]   = "mqtt.duckdns.org";

MenuItem myMenuItems [] =
{
  { "sv1", "Blynk Server1", Blynk_Server1,  MAX_BLYNK_SERVER_LEN },
  { "tk1", "Token1",        Blynk_Token1,   MAX_BLYNK_TOKEN_LEN },
  { "sv2", "Blynk Server2", Blynk_Server2,  MAX_BLYNK_SERVER_LEN },
  { "tk2", "Token2",        Blynk_Token2,   MAX_BLYNK_TOKEN_LEN },
  { "prt", "Port",          Blynk_Port,     MAX_BLYNK_PORT_LEN },
  { "mqt", "MQTT Server",   MQTT_Server,    MAX_MQTT_SERVER_LEN },
};

uint16_t NUM_MENU_ITEMS = sizeof(myMenuItems) / sizeof(MenuItem);  //MenuItemSize;

#else

MenuItem myMenuItems [] = {};

uint16_t NUM_MENU_ITEMS = 0;

#endif    //USE_DYNAMIC_PARAMETERS

```
- If you don't need to add dynamic parameters, use the following in sketch

```
#define USE_DYNAMIC_PARAMETERS     false
```

or

```
/////////////// Start dynamic Credentials ///////////////

MenuItem myMenuItems [] = {};

uint16_t NUM_MENU_ITEMS = 0;
/////// // End dynamic Credentials ///////////

```
---

### Important Notes for using Dynamic Parameters' ids

1. These ids (such as "mqtt" in example) must be **unique**.

Please be noted that the following **reserved names are already used in library**:

```
"id"    for WiFi SSID
"pw"    for WiFi PW
"id1"   for WiFi1 SSID
"pw1"   for WiFi1 PW
"nm"    for Board Name
```
---
---

### Example [Portenta_H7_WiFi](examples/Portenta_H7_WiFi)

Please take a look at other examples, as well.

#### 1. File [Portenta_H7_WiFi.ino](examples/Portenta_H7_WiFi/Portenta_H7_WiFi.ino)

```cpp
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
```
---

#### 2. File [defines.h](examples/Portenta_H7_WiFi/defines.h)

```cpp
#ifndef defines_h
#define defines_h

/* Comment this out to disable prints and save space */
#define DEBUG_WIFI_WEBSERVER_PORT     Serial
#define WIFI_GENERIC_DEBUG_OUTPUT     Serial

#define _WIFI_GENERIC_LOGLEVEL_       1

#define DRD_GENERIC_DEBUG             true

#if ( ( defined(ARDUINO_PORTENTA_H7_M7) || defined(ARDUINO_PORTENTA_H7_M4) ) && defined(ARDUINO_ARCH_MBED) )
  #warning Use MBED ARDUINO_PORTENTA_H7 and LittleFS
  
  #if defined(BOARD_NAME)
    #undef BOARD_NAME
  #endif

  #if defined(CORE_CM7)
    #warning Using Portenta H7 M7 core
    #define BOARD_NAME              "PORTENTA_H7_M7"
  #else
    #warning Using Portenta H7 M4 core
    #define BOARD_NAME              "PORTENTA_H7_M4"
  #endif
  
#else
  #error This code is intended to run on the MBED ARDUINO_PORTENTA_H7 platform! Please check your Tools->Board setting. 
#endif

/////////////////////////////////////////////

// You have to select true for the first time for any board
#define FORCE_REFORMAT            false

/////////////////////////////////////////////

// To use the default WiFi library here
#define USE_WIFI_NINA         false
#define USE_WIFI_CUSTOM       false
  
/////////////////////////////////////////////

// Add customs headers
#define USING_CUSTOMS_STYLE           true
#define USING_CUSTOMS_HEAD_ELEMENT    true
#define USING_CORS_FEATURE            true

/////////////////////////////////////////////

#define SHIELD_TYPE           "Portenta_H7 WiFi"

#warning Using Portenta WiFi.h Library defined in WiFiWebServer Library.
  
/////////////////////////////////////////////

// Permit running CONFIG_TIMEOUT_RETRYTIMES_BEFORE_RESET times before reset hardware
// to permit user another chance to config. Only if Config Data is valid.
// If Config Data is invalid, this has no effect as Config Portal will persist
#define RESET_IF_CONFIG_TIMEOUT                   true

// Permitted range of user-defined RETRY_TIMES_RECONNECT_WIFI between 2-5 times
#define RETRY_TIMES_RECONNECT_WIFI                3

// Permitted range of user-defined CONFIG_TIMEOUT_RETRYTIMES_BEFORE_RESET between 2-100
#define CONFIG_TIMEOUT_RETRYTIMES_BEFORE_RESET    5

// Config Timeout 120s (default 60s). Applicable only if Config Data is Valid
#define CONFIG_TIMEOUT                      120000L

/////////////////////////////////////////////

// Permit input only one set of WiFi SSID/PWD. The other can be "NULL or "blank"
// Default is false (if not defined) => must input 2 sets of SSID/PWD
#define REQUIRE_ONE_SET_SSID_PW             true    //false

// Max times to try WiFi per loop() iteration. To avoid blocking issue in loop()
// Default 1 if not defined, and minimum 1.
//#define MAX_NUM_WIFI_RECON_TRIES_PER_LOOP     2

// Default no interval between recon WiFi if lost
// Max permitted interval will be 10mins
// Uncomment to use. Be careful, WiFi reconnect will be delayed if using this method
// Only use whenever urgent tasks in loop() can't be delayed. But if so, it's better you have to rewrite your code, e.g. using higher priority tasks.
#define WIFI_RECON_INTERVAL                   30000

/////////////////////////////////////////////

#define USE_DYNAMIC_PARAMETERS        true

/////////////////////////////////////////////

#define SCAN_WIFI_NETWORKS                  true

// To be able to manually input SSID, not from a scanned SSID lists
#define MANUAL_SSID_INPUT_ALLOWED           true

/////////////////////////////////////////////

// From 2-15
#define MAX_SSID_IN_LIST                  8

/////////////////////////////////////////////

#include <WiFiManager_Portenta_H7_Lite.h>

#define HOST_NAME   "Portenta-Controller"

#if defined(LED_BUILTIN)
  #define LED_PIN     LED_BUILTIN
#elif defined(LEDB)
  #define LED_PIN     LEDB
#else
  #define LED_PIN     13
#endif

#endif      //defines_h
```
---

#### 3. File [Credentials.h](examples/Portenta_H7_WiFi/Credentials.h)

```cpp
#ifndef Credentials_h
#define Credentials_h

#include "defines.h"

/// Start Default Config Data //////////////////

/*
  #define SSID_MAX_LEN      32
  //From v1.0.3, WPA2 passwords can be up to 63 characters long.
  #define PASS_MAX_LEN      64

  typedef struct
  {
  char wifi_ssid[SSID_MAX_LEN];
  char wifi_pw  [PASS_MAX_LEN];
  }  WiFi_Credentials;

  #define NUM_WIFI_CREDENTIALS      2

  // Configurable items besides fixed Header, just add board_name
  #define NUM_CONFIGURABLE_ITEMS    ( ( 2 * NUM_WIFI_CREDENTIALS ) + 1 )
  ////////////////

  typedef struct Configuration
  {
  char header         [16];
  WiFi_Credentials  WiFi_Creds  [NUM_WIFI_CREDENTIALS];
  char board_name     [24];
  int  checkSum;
  } WIFI_GENERIC_Configuration;
*/

#define TO_LOAD_DEFAULT_CONFIG_DATA      false

#if TO_LOAD_DEFAULT_CONFIG_DATA

// This feature is primarily used in development to force a known set of values as Config Data
// It will NOT force the Config Portal to activate. Use DRD or erase Config Data with Blynk.clearConfigData()

// Used mostly for development and debugging. FORCES default values to be loaded each run.
// Config Portal data input will be ignored and overridden by DEFAULT_CONFIG_DATA
//bool LOAD_DEFAULT_CONFIG_DATA = true;

// Used mostly once debugged. Assumes good data already saved in device.
// Config Portal data input will be override DEFAULT_CONFIG_DATA
bool LOAD_DEFAULT_CONFIG_DATA = false;


WIFI_GENERIC_Configuration defaultConfig =
{
  //char header[16], dummy, not used
  "Portenta_WIFI",
  // WiFi_Credentials  WiFi_Creds  [NUM_WIFI_CREDENTIALS];
  // WiFi_Credentials.wifi_ssid and WiFi_Credentials.wifi_pw
  "SSID1",  "password1",
  "SSID2",  "password2",
  //char board_name     [24];
  "Portenta-H7-Control",
  // terminate the list
  //int  checkSum, dummy, not used
  0
  /////////// End Default Config Data /////////////
};

#else

bool LOAD_DEFAULT_CONFIG_DATA = false;

WIFI_GENERIC_Configuration defaultConfig;

#endif    // TO_LOAD_DEFAULT_CONFIG_DATA

/////////// End Default Config Data /////////////


#endif    //Credentials_h
```
---

#### 4. File [dynamicParams.h](examples/Portenta_H7_WiFi/dynamicParams.h)

```cpp
#ifndef dynamicParams_h
#define dynamicParams_h

#include "defines.h"

// USE_DYNAMIC_PARAMETERS defined in defined.h

/////////////// Start dynamic Credentials ///////////////

//Defined in <WiFiManager_Portenta_H7_Lite.h>
/**************************************
  #define MAX_ID_LEN                5
  #define MAX_DISPLAY_NAME_LEN      16

  typedef struct
  {
  char id             [MAX_ID_LEN + 1];
  char displayName    [MAX_DISPLAY_NAME_LEN + 1];
  char *pdata;
  uint8_t maxlen;
  } MenuItem;
**************************************/

#if USE_DYNAMIC_PARAMETERS

#define MAX_BLYNK_SERVER_LEN      34
#define MAX_BLYNK_TOKEN_LEN       34

char Blynk_Server1 [MAX_BLYNK_SERVER_LEN + 1]  = "account.duckdns.org";
char Blynk_Token1  [MAX_BLYNK_TOKEN_LEN + 1]   = "token1";

char Blynk_Server2 [MAX_BLYNK_SERVER_LEN + 1]  = "account.ddns.net";
char Blynk_Token2  [MAX_BLYNK_TOKEN_LEN + 1]   = "token2";

#define MAX_BLYNK_PORT_LEN        6
char Blynk_Port   [MAX_BLYNK_PORT_LEN + 1]  = "8080";

#define MAX_MQTT_SERVER_LEN      34
char MQTT_Server  [MAX_MQTT_SERVER_LEN + 1]   = "mqtt.duckdns.org";

MenuItem myMenuItems [] =
{
  { "sv1", "Blynk Server1", Blynk_Server1,  MAX_BLYNK_SERVER_LEN },
  { "tk1", "Token1",        Blynk_Token1,   MAX_BLYNK_TOKEN_LEN },
  { "sv2", "Blynk Server2", Blynk_Server2,  MAX_BLYNK_SERVER_LEN },
  { "tk2", "Token2",        Blynk_Token2,   MAX_BLYNK_TOKEN_LEN },
  { "prt", "Port",          Blynk_Port,     MAX_BLYNK_PORT_LEN },
  { "mqt", "MQTT Server",   MQTT_Server,    MAX_MQTT_SERVER_LEN },
};

uint16_t NUM_MENU_ITEMS = sizeof(myMenuItems) / sizeof(MenuItem);  //MenuItemSize;

#else

MenuItem myMenuItems [] = {};

uint16_t NUM_MENU_ITEMS = 0;

#endif    //USE_DYNAMIC_PARAMETERS


#endif      //dynamicParams_h
```
---
---


### Debug Terminal output Samples

#### 1. Portenta_H7_WiFi example on Portenta_H7

This is the terminal output when running [**Portenta_H7_WiFi**](examples/Portenta_H7_WiFi) example on **Portenta_H7**:

#### 1.1 Open Config Portal

```
Start Portenta_H7_WiFi on PORTENTA_H7_M7 with Portenta_H7 WiFi
WiFiManager_Portenta_H7_Lite v1.5.0
[WG] Hostname=Portenta-Controller
Flash Size: (KB) = 2048.00
FlashIAP Start Address: = 0x80A0000
LittleFS size (KB) = 1280.00
LittleFS Mount Fail
Formatting... 
Loading DRD file failed
Flag read = 0x1060a5b
No doubleResetDetected
Saving DOUBLERESETDETECTOR_FLAG to DRD file : 0xd0d01234
Saving DRD file OK
SetFlag write = 0xd0d01234
[WG] bg: isForcedConfigPortal = false
[WG] bg:Stay forever in CP:No ConfigDat
[WG] clearForcedCP
[WG] SaveCPFile 
[WG] OK
[WG] SaveBkUpCPFile 
[WG] OK
[WG] SSID=WIFI_GENERIC_51F485,PW=MyWIFI_GENERIC_51F485
[WG] IP=192.168.4.1,CH=4
Stop doubleResetDetecting
Saving to DRD file : 0xd0d04321
Saving DRD file OK
LittleFS Flag read = 0xd0d04321
ClearFlag write = 0xd0d04321
F
Your stored Credentials :
Blynk Server1 = account.duckdns.org
Token1 = token1
Blynk Server2 = account.ddns.net
Token2 = token2
Port = 8080
MQTT Server = mqtt.duckdns.org
FFFFFFFFF FFFFF
[WG] h:UpdLittleFS
[WG] h:Rst
```


#### 1.2 Got valid Credential from Config Portal, then connected to WiFi

```
Start Portenta_H7_WiFi on PORTENTA_H7_M7 with Portenta_H7 WiFi
WiFiManager_Portenta_H7_Lite v1.5.0
[WG] Hostname=Portenta-Controller
Flash Size: (KB) = 2048.00
FlashIAP Start Address: = 0x80A0000
LittleFS size (KB) = 1280.00
LittleFS Mount OK
LittleFS Flag read = 0xd0d04321
Flag read = 0xd0d04321
No doubleResetDetected
Saving DOUBLERESETDETECTOR_FLAG to DRD file : 0xd0d01234
Saving DRD file OK
SetFlag write = 0xd0d01234
[WG] CCSum=0x1435,RCSum=0x1435
[WG] CrCCsum=0x163b,CrRCsum=0x163b
[WG] Valid Stored Dynamic Data
[WG] ======= Start Stored Config Data =======
[WG] Hdr=PORTENTA-H7-WIFI,SSID=HueNet1,PW=12345678
[WG] SSID1=HueNet,PW1=12345678
[WG] BName=Portenta_H7
[WG] i=0,id=sv1,data=new.duckdns.org
[WG] i=1,id=tk1,data=token1
[WG] i=2,id=sv2,data=new.ddns.net
[WG] i=3,id=tk2,data=token2
[WG] i=4,id=prt,data=8080
[WG] i=5,id=mqt,data=mqtt.duckdns.org
[WG] con2WF:SSID=HueNet1,PW=12345678
[WG] con2WF:OK
[WG] IP=192.168.2.130
[WG] SSID=HueNet1,RSSI=-32
[WG] IP=192.168.2.130
[WG] b:WOK
Stop doubleResetDetecting
Saving to DRD file : 0xd0d04321
Saving DRD file OK
LittleFS Flag read = 0xd0d04321
ClearFlag write = 0xd0d04321
H
Your stored Credentials :
Blynk Server1 = new.duckdns.org
Token1 = token1
Blynk Server2 = new.ddns.net
Token2 = token2
Port = 8080
MQTT Server = mqtt.duckdns.org
HHHHHHHHHH HHHHHHHHHH HHHHHHHHHH HHHHHHHHHH HHHHHHHHHH HHHHHHHHHH HHHHHHHHHH HHHHHHHHHH
HHHHHHHHHH HHHHHHHHHH HHHHHHHHHH HHHHHHHHHH HHHHHHHHHH HHHHHHHHHH HHHHHHHHHH HHHHHHHHHH
```


---

#### 2. Portenta_H7_WiFi_MQTT on Portenta_H7

This is the terminal output when running [**Portenta_H7_WiFi_MQTT**](examples/Portenta_H7_WiFi_MQTT) example on **Portenta_H7**:

#### 2.1 Open Config Portal

<p align="center">
    <img src="https://github.com/khoih-prog/WiFiManager_Portenta_H7_Lite/blob/main/pics/MQTT.png">
</p>


```
Start Portenta_H7_WiFi_MQTT on PORTENTA_H7_M7 with Portenta_H7 WiFi
WiFiManager_Portenta_H7_Lite v1.5.0
[WG] Hostname=Portenta-MQTT
Flash Size: (KB) = 2048.00
FlashIAP Start Address: = 0x80A0000
LittleFS size (KB) = 1280.00
LittleFS Mount OK
LittleFS Flag read = 0xd0d04321
Flag read = 0xd0d04321
No doubleResetDetected
Saving DOUBLERESETDETECTOR_FLAG to DRD file : 0xd0d01234
Saving DRD file OK
SetFlag write = 0xd0d01234
[WG] Invalid Stored WiFi Config Data
[WG] bg: isForcedConfigPortal = false
[WG] bg:Stay forever in CP:No ConfigDat
[WG] clearForcedCP
[WG] SaveCPFile 
[WG] OK
[WG] SSID=WIFI_GENERIC_51F485,PW=MyWIFI_GENERIC_51F485
[WG] IP=192.168.4.1,CH=9
Stop doubleResetDetecting
Saving to DRD file : 0xd0d04321
Saving DRD file OK
LittleFS Flag read = 0xd0d04321
ClearFlag write = 0xd0d04321
N
Your stored Credentials :
AIO_SERVER = io.adafruit.com
AIO_SERVERPORT = 1883
AIO_USERNAME = private
AIO_KEY = private
AIO_PUB_TOPIC = /feeds/Temperature
AIO_SUB_TOPIC = /feeds/LED_Control
NNNN NNNNN NNNNN NNNNN NNNNN NNNNN NNNNN NN
```

#### 2.2 Got valid Credential from Config Portal, then connected to WiFi and AIO MQTT

<p align="center">
    <img src="https://github.com/khoih-prog/WiFiManager_Portenta_H7_Lite/blob/main/pics/MQTT_Save.png">
</p>

```
Start Portenta_H7_WiFi_MQTT on PORTENTA_H7_M7 with Portenta_H7 WiFi
WiFiManager_Portenta_H7_Lite v1.5.0
[WG] Hostname=Portenta-MQTT
Flash Size: (KB) = 2048.00
FlashIAP Start Address: = 0x80A0000
LittleFS size (KB) = 1280.00
LittleFS Mount OK
LittleFS Flag read = 0xd0d04321
Flag read = 0xd0d04321
No doubleResetDetected
Saving DOUBLERESETDETECTOR_FLAG to DRD file : 0xd0d01234
Saving DRD file OK
SetFlag write = 0xd0d01234
[WG] CCSum=0x160c,RCSum=0x160c
[WG] CrCCsum=0x2236,CrRCsum=0x2236
[WG] Valid Stored Dynamic Data
[WG] ======= Start Stored Config Data =======
[WG] Hdr=PORTENTA-H7-WIFI,SSID=HueNet1,PW=12345678
[WG] SSID1=HueNet2,PW1=12345678
[WG] BName=Portenta_H7_MQTT
[WG] i=0,id=svr,data=io.adafruit.com
[WG] i=1,id=prt,data=1883
[WG] i=2,id=usr,data=user_name
[WG] i=3,id=key,data=aio_key
[WG] i=4,id=pub,data=/feeds/Temperature
[WG] i=5,id=sub,data=/feeds/LED_Control
[WG] con2WF:SSID=HueNet1,PW=12345678
[WG] con2WF:OK
[WG] IP=192.168.2.130
[WG] SSID=HueNet1,RSSI=-44
[WG] IP=192.168.2.130
[WG] b:WOK
Stop doubleResetDetecting
Saving to DRD file : 0xd0d04321
Saving DRD file OK
LittleFS Flag read = 0xd0d04321
ClearFlag write = 0xd0d04321

Creating new WiFi client object OK
Creating new MQTT object OK
AIO_SERVER = io.adafruit.com, AIO_SERVERPORT = 1883
AIO_USERNAME = user_name, AIO_KEY = aio_key
Creating new MQTT_Pub_Topic,  Temperature = user_name/feeds/Temperature
Creating new Temperature object OK
Temperature MQTT_Pub_Topic = user_name/feeds/Temperature
Creating new AIO_SUB_TOPIC, LED_Control = user_name/feeds/LED_Control
Creating new LED_Control object OK
LED_Control AIO_SUB_TOPIC = user_name/feeds/LED_Control

Connecting to WiFi MQTT (3 attempts)...
WiFi MQTT connection successful!
TW
Your stored Credentials :
AIO_SERVER = io.adafruit.com
AIO_SERVERPORT = 1883
AIO_USERNAME = user_name
AIO_KEY = aio_key
AIO_PUB_TOPIC = /feeds/Temperature
AIO_SUB_TOPIC = /feeds/LED_Control
TWTWTWTW TWTWTW
```
  
---
---

#### Debug

Debug is enabled by default on Serial. To disable, add at the beginning of sketch

```cpp
/* Comment this out to disable prints and save space */
#define DEBUG_WIFI_WEBSERVER_PORT     Serial
#define WIFI_GENERIC_DEBUG_OUTPUT     Serial

#define _WIFI_GENERIC_LOGLEVEL_       4

#define DRD_GENERIC_DEBUG             true
```

---

## Troubleshooting

If you get compilation errors, more often than not, you may need to install a newer version of the board's core, or this library version.

Sometimes, the library will only work if you update the `WiFi module/shield` firmware to the newer or older version because some function compatibility.

---
---


### Issues

Submit issues to: [WiFiManager_Portenta_H7_Lite issues](https://github.com/khoih-prog/WiFiManager_Portenta_H7_Lite/issues)

---
---

### TO DO

1. Support more boards, shields and libraries
2. Bug Searching and Killing

---

### DONE

 1. Add support to **Portenta_H7** built-in Murata WiFi using [`ArduinoCore-mbed mbed_portenta core`](https://github.com/arduino/ArduinoCore-mbed)
 2. More flexible to configure reconnection timeout.
 3. For fresh config data, don't need to wait for connecting timeout before entering config portal.
 4. If the config data not entered completely (SSIDs, Passwords, etc.), entering config portal
 5. Add configurable Config Portal IP, SSID and Password
 6. Change Synch XMLHttpRequest to Async
 7. Add configurable Static IP, GW, Subnet Mask and 2 DNS Servers' IP Addresses.
 8. Add checksums
 9. Add MultiWiFi features with auto(re)connect
10. Easy-to-use **Dynamic Parameters** without the necessity to write complicated ArduinoJSon functions
11. Permit to input special chars such as **%** and **#** into data fields.
12. Default Credentials and dynamic parameters
13. **DoubleDetectDetector** to force Config Portal when double reset is detected within predetermined time, default 10s.
14. Configurable Config Portal Title
15. Re-structure all examples to separate Credentials / Defines / Dynamic Params / Code so that you can change Credentials / Dyamic Params quickly for each device.
16. Add Table of Contents and Version String
17. Configurable **Customs HTML Headers**, including Customs Style, Customs Head Elements, CORS Header
18. Add functions to control Config Portal from software or Virtual Switches.
19. Permit optionally inputting one set of WiFi SSID/PWD by using `REQUIRE_ONE_SET_SSID_PW == true`
20. Enforce WiFi Password minimum length of 8 chars
21. Enable **scan of WiFi networks** for selection in Configuration Portal
22. Add `LibraryPatches` for [**Adafruit_MQTT_Library**](https://github.com/adafruit/Adafruit_MQTT_Library) to fix compiler error for Portenta_H7, RP2040-based and many other boards.
23. Fix the blocking issue in loop() with configurable `WIFI_RECON_INTERVAL`
24. Workaround for core WiFi.status() bug, which does not detect WiFi lost.

---
---
 
### Contributions and Thanks

Please help contribute to this project and add your name here.

1. Again thanks to [Michael H. "bizprof"](https://github.com/bizprof) for the impressive feature being usd in this library : 
  - `Enable scan of WiFi networks for selection in Configuration Portal`. Check [PR for v1.3.0 - Enable scan of WiFi networks #10](https://github.com/khoih-prog/WiFiManager_NINA_Lite/pull/10)
2. Thanks to [tomtobback](https://github.com/tomtobback) to report issue [retries block the main loop #18](https://github.com/khoih-prog/WiFiManager_NINA_Lite/issues/18) leading to version v1.5.0 to fix the blocking issue in loop() with `WIFI_RECON_INTERVAL`.

<table>
  <tr>
    <td align="center"><a href="https://github.com/bizprof"><img src="https://github.com/bizprof.png" width="100px;" alt="bizprof"/><br /><sub><b>⭐️⭐️ Michael H. "bizprof"</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/tomtobback"><img src="https://github.com/tomtobback.png" width="100px;" alt="tomtobback"/><br /><sub><b>tomtobback</b></sub></a><br /></td>
  </tr> 
</table>

---

### Contributing

If you want to contribute to this project:

- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library

---

### License

- The library is licensed under [MIT](https://github.com/khoih-prog/WiFiManager_Portenta_H7_Lite/blob/main/LICENSE)

---

### Copyright

Copyright 2021- Khoi Hoang - Michale H.


