#pragma once

#include "startmodule.hpp"

class CarState {
  public: 
    //Construcor
    CarState();

    //Variables
    float temperature;
    int desired_speed;
    int actual_speed;

    bool sensor_available[8] = {false};
    int sensor_reading[8] = {0};

    //Methods
    Sensor::startmodule_state startmodule;
    //CarState & getCarState(); //Singleton
  private:
};

extern CarState * g_carstate;