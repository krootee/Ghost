#include "tca9548.hpp"

namespace Sensor {

  TCA9548::TCA9548() {
    //Default constructor
  }

  TCA9548::TCA9548(int i2caddr) {
    //Constructor
  }

  bool TCA9548::set_channel(int channel) {
    //TODO
    return true;
  }

  int TCA9548::get_channel() {
    //TODO
    return 32;
  }

  bool TCA9548::detect_device() {
    //TODO
    return true;
  }
}