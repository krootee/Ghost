#pragma once

#include "mgos.h"
#include "mgos_i2c.h"
#include "xyz.hpp"

namespace Sensor {
  class MPU9250 {
    public:
      MPU9250();
      MPU9250(int);
      
      bool detect_device();
      float read_temperature();

      void enable();

      xyz read_compass();
      xyz read_gyroscope();
      xyz read_accelerometer();

    private:
      uint16_t i2c_address;
      //int read_configuration();
  };
}