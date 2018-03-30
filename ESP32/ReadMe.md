# ESP32 / ESP-WROOM-32

This page contains my notes about programming the ESP-WROOM-32 module.

The primary sourcecode for the Ghost-folkracer car is in the /Folkracer directory.
All code for testing individual parts of the car can be found in the /TestPrograms dir.

## Using Arduino IDE

To program the board using the Arduino IDE first follow the installation instructions at https://github.com/espressif/arduino-esp32.

In Arduino IDE choose the board called 'ESP32 Dev Module'.
The blinky-led is on pin 23.


## Using C++ and ESP-IDF

Documentation and installation guide for ESP-IDF can be found at: https://esp-idf.readthedocs.io

### Prerequisites (Ubuntu/Linux Mint)

Perform installation Step 0 to Step 2 from the documentation link above.

In addition, add this to ~/.bashrc as well (from Step 4):

    export IDF_PATH=~/esp/esp-idf

### Flashing

Go to the /Ghost/ESP32/Folkracer directory, and run

    make flash (flashes app, bootloader and partition table)

or

    make app-flash (flashes just the app)

or

    make all flash monitor (builds everything, flashes and starts the monitor with one command)

To close the 'monitor' use keys Ctrl+] (which is Ctrl+AltGr+9 on Norwegian keyboards).


### Performance

    make -j5 (performs the build with parallell threads)

### Configuring Eclipse

When starting Eclipse, set ~/GIT/Ghost/ESP32 as the workspace folder.

On properties for the project, go to "C/C++ Build", and uncheck "Use default build command".
Go to Environment, and add IDF_PATH = ~/esp/esp-idf
Go to "C/C++ General"->"Paths and Symbols", select "GNU C", click Add..., and add these:

    ${IDF_PATH}/components/esp32/include
    ${IDF_PATH}/components/newlib/include
    ${IDF_PATH}/components/freertos/include
    ${IDF_PATH}/components/nvs_flash/include
    ${IDF_PATH}/components/driver/include
    ${IDF_PATH}/components/log/include

and lastly

    /myapp/build/include (with the "Is a workspace path" checkbox ticked, and correct appname)

### Using OTA

First, make sure the ota.bin firmware has been deployed using USB cable.

    cd ~/esp/esp-idf/examples/system/ota
    make menuconfig
        configure correct SSID, password, IP to webserver, and .bin file to download.
    make flash

Set up a local HTTP webserver in the /build directory of the application to deploy Using

    python2 -m SimpleHTTPServer 8070

Now, rebuild the project we want to deploy, so that the .bin file gets created/updated.
Press Reset button on ESP to make it restart, download new image and reflash itself.

### Connecting serial

Install Minicom

    sudo apt-get install minicom

and to use

    minicom --device /dev/ttyUSB0

or you can use

    make monitor

Quit it using Ctrl+] (which is Ctrl+AltGr+9)

### Troubleshooting

##### Unable to flash via USB - permission denied

When running "make app-flash" or similar you get error saying permission denied to the USB device.

This can be fixed by adding the current Linux-user to the 'dialout' group.

    sudo usermod -a -G dialout $USER

Reboot the machine afterwards.


##### OTA fails
https://github.com/espressif/esp-idf/issues/231


##### TODO

- separate task_actuators into task_motor and task_steering, and write to two separate queues from task_drivecomputer.
