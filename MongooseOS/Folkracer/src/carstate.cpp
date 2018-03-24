#include <mgos.h>
#include "carstate.hpp"

CarState * g_carstate = new CarState();

CarState::CarState() {
  this->count = 18;
  LOG(LL_INFO, ("CarState constructor"));
}