#include <mgos.h>
#include "carstate.hpp"

//Create a globally available instance
CarState * g_carstate = new CarState();

//Constructor
CarState::CarState() {
  LOG(LL_INFO, ("CarState constructor"));
  
  this->count = 18;
  this->temperature = 32.5;
  this->startmodule = Sensor::startmodule_state::ready;
}