## WiFiManager_Portenta_H7_Lite (Light Weight Credentials / WiFi Manager for Generic WiFi (WiFiNINA, WiFi101, WiFiEsp, etc.)  modules/shields)

[![arduino-library-badge](https://www.ardu-badge.com/badge/WiFiManager_Portenta_H7_Lite.svg?)](https://www.ardu-badge.com/WiFiManager_Portenta_H7_Lite)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/WiFiManager_Portenta_H7_Lite.svg)](https://github.com/khoih-prog/WiFiManager_Portenta_H7_Lite/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/WiFiManager_Portenta_H7_Lite/blob/main/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/WiFiManager_Portenta_H7_Lite.svg)](http://github.com/khoih-prog/WiFiManager_Portenta_H7_Lite/issues)

---
---

## Table of Contents

* [Changelog](#changelog)
  * [Release v1.6.0](#release-v160)
  * [Release v1.5.1](#release-v151)
  * [Release v1.5.0](#release-v150)
  * [Release v1.4.1](#release-v141)
  * [Initial Release v1.4.0](#initial-release-v140)

---
---

## Changelog

### Release v1.6.0

1. Use [WiFiMulti_Generic](https://github.com/khoih-prog/WiFiMulti_Generic) library to connect to the best of **multi-WiFi APs**, with **auto-checking / auto-reconnecting** features when WiFi connection is lost
2. Rewrite for new mbed_portenta core v3.0.1+
3. Add `lib_ldf_mode = chain+` in `platformio.ini`
4. Update `Packages' Patches`

### Release v1.5.1

1. Optional Board_Name in Menu
2. Optimize code by using passing by reference

### Release v1.5.0

1. Workaround for core WiFi.status() bug, which does not detect WiFi lost.
2. Fix the blocking issue in loop(). Check [retries block the main loop #18](https://github.com/khoih-prog/WiFiManager_NINA_Lite/issues/18)
3. Configurable `WIFI_RECON_INTERVAL`. Check [retries block the main loop #18](https://github.com/khoih-prog/WiFiManager_NINA_Lite/issues/18#issuecomment-1006197561)
4. Update `Packages' Patches`


### Release v1.4.1

1. Update `platform.ini` and `library.json` to use original `khoih-prog` instead of `khoih.prog` after PIO fix
2. Update `Packages' Patches`

### Initial Release v1.4.0

1. Add support to Portenta_H7 boards, using [`ArduinoCore-mbed mbed_portenta core`](https://github.com/arduino/ArduinoCore-mbed)
2. Update `Packages' Patches`
3. Add `LibraryPatches` for [**Adafruit_MQTT_Library**](https://github.com/adafruit/Adafruit_MQTT_Library) to fix compiler error for Portenta_H7 and many other boards.
4. Bump version to v1.4.0 to sync with [WiFiManager_Generic_Lite library](https://github.com/khoih-prog/WiFiManager_Generic_Lite)


