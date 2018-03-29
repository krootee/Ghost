#pragma once
#include "mgos_i2c.h"

namespace Sensor {
  class TMP102 {
    public:
      TMP102();
      TMP102(int);
      
      float readTemperature();
    private:
  };
}