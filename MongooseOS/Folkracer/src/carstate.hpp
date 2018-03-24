#pragma once

#include "startmodule.hpp"

class CarState {
  public: 
    CarState();
    int count;
    int temperature;
    Sensor::startmodule_state startmodule;
    CarState & getCarState(); //Singleton
  private:
};

extern CarState * g_carstate;