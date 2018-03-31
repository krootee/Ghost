#pragma once

#include "mgos.h"
#include "mgos_i2c.h"

namespace Sensor {
  class TMP102 {
    public:
      TMP102();
      TMP102(int);
      
      bool detect_device();
      float read_temperature();
    private:
      uint16_t i2c_address;
      int read_configuration();
  };
}