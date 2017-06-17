#pragma once
#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "fw/src/mgos_app.h"
#include "fw/src/mgos_gpio.h"       
#include "fw/src/mgos_sys_config.h" //Needed for LOG
#include "fw/src/mgos_timers.h"
#include "fw/src/mgos_hal.h"

using namespace std;

#define RC5_BIT_COUNT 14

#define GPIO_PIN_IR 22

#define MGOS_TIMER_FOREVER 1
#define MGOS_TIMER_ONCE 0

class RC5 {
public:
    void start();
    string get_ir_data();
private:
    char data[14];
};