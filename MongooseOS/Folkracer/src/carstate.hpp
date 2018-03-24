#pragma once

class CarState {
  public: 
    CarState();
    int count;
    CarState & getCarState(); //Singleton
  private:
};

extern CarState g_carstate;