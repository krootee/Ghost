#pragma once

#include "startmodule.hpp"

class CarState {
  public: 
    //Construcor
    CarState();

    //Variables
    int count;
    int temperature;
    int desired_speed;

    //Methods
    Sensor::startmodule_state startmodule;
    //CarState & getCarState(); //Singleton
  private:
};

extern CarState * g_carstate;