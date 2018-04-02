#include <mgos.h>
#include "carstate.hpp"

//Create a globally available instance
CarState * g_carstate = new CarState();

//Constructor
CarState::CarState() {
  LOG(LL_INFO, ("CarState constructor"));
  
  this->temperature = 0;
  this->startmodule = Sensor::startmodule_state::ready;
  this->desired_speed = 0;
  this->actual_speed = 0;
}