#include <mgos.h>
#include "carstate.hpp"

CarState * g_carstate = new CarState();

CarState::CarState() {
  this->count = 18;
  this->temperature = 32;
  this->startmodule = Sensor::startmodule_state::ready;
  LOG(LL_INFO, ("CarState constructor"));
}