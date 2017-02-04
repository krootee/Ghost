# ESP32 / ESP-WROOM-32

This page contains my notes about programming the ESP-WROOM-32 module.

The primary sourcecode for the Ghost-folkracer car is in the /Folkracer directory.
All code for testing individual parts of the car can be found in the /TestPrograms dir.

Documentation for ESP-IDF can be found at: https://esp-idf.readthedocs.io

## Prerequisites (Ubuntu)

(See link above)

## Flashing

    make app-flash

or

    make flash

## Using OTA

First, make sure the ota.bin firmware has been deployed using USB cable.

    cd ~/esp/esp-idf/examples/system/ota
    make menuconfig
        configure correct SSID, password, IP to webserver, and .bin file to download.
    make flash

Set up a local HTTP webserver in the /build directory of the application to deploy Using

    python2 -m SimpleHTTPServer 8070

Now, rebuild the project we want to deploy, so that the .bin file gets created/updated.
Press Reset button on ESP to make it restart, download new image and reflash itself.

## Connecting serial

Install Minicom

    sudo apt-get install minicom

and to use

    minicom --device /dev/ttyUSB0

## Troubleshooting

#### OTA fails
https://github.com/espressif/esp-idf/issues/231
