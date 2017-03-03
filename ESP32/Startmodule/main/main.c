// #include <stdio.h>
#include "freertos/FreeRTOS.h"
// #include "freertos/task.h"
// #include "esp_system.h"
// #include "driver/gpio.h"
// #include <esp_log.h>
// #include "sdkconfig.h"
#include "StartModule.c"

/*
 * Testprogram for using a Startmodule (http://startmodule.com/) from an ESP32.
 * Startmodule connected to pins 23 (start), 21 (for vcc) and GND.
 * Using GPIO 21 to supply power to the Startmodule, which means we can powercycle via software and reset button.
 * Frode Lillerud, NorBot, febuary 2017
 */


void app_main()
{
  xTaskCreate(&startmodule_task, "Startmodule", 2048, NULL, 5, NULL);
}
