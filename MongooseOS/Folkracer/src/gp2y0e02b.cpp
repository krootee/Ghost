/*
 * The GP2Y0E02B IR Sensor
 * Datasheet: http://www.sharp-world.com/products/device/lineup/data/pdf/datasheet/gp2y0e02b_e.pdf
 * Range: 4-50cm
 */

#include "mgos.h"
#include "mgos_i2c.h"
#include "gp2y0e02b.hpp"
#include <math.h>

#define GP2Y0E02B_I2C_ADDRESS       0x40

#define GP2Y0E02B_REGISTER_SHIFT    0x35
#define GP2Y0E02B_REGISTER_DISTANCE 0x5E

namespace Sensor {

  GP2Y0E02B::GP2Y0E02B() {
    this->i2c_address = GP2Y0E02B_I2C_ADDRESS;
  }

  bool GP2Y0E02B::detect_device() {
    struct mgos_i2c *i2c = mgos_i2c_get_global();

    return mgos_i2c_read_reg_b(i2c, this->i2c_address, GP2Y0E02B_REGISTER_DISTANCE) != -1;
  }

  int GP2Y0E02B::getDistance() {

      //Get reference to the global I2C instance
      struct mgos_i2c *i2c = mgos_i2c_get_global();

      uint8_t buffer[2];
      if (mgos_i2c_read_reg_n(i2c, this->i2c_address, GP2Y0E02B_REGISTER_DISTANCE, sizeof(buffer), buffer)) {
        //LOG(LL_INFO, ("SUCCESS"));
      } else {
        LOG(LL_ERROR, ("ERROR reading sensor"));
      }

/*
      int shift = mgos_i2c_read_reg_b(i2c, this->i2c_address, GP2Y0E02B_REGISTER_SHIFT);
      if (shift == -1) {
          LOG(LL_ERROR, ("Unable to read value from SHIFT register"));
      } else {
          LOG(LL_INFO, ("Success, got data from SHIFT register: %d", shift));
      }
*/
      //Read two bytes from DISTANCE register
      int value = mgos_i2c_read_reg_w(i2c, GP2Y0E02B_I2C_ADDRESS, GP2Y0E02B_REGISTER_DISTANCE);
      //LOG(LL_INFO, ("Distance = %d", value));
      //return value;
      //Calculate distance
      //short high = data[0], low = data[1];
      //short high = value 
      //int distance_in_cm = (high * 16 + low)/16/(int)pow(2,shift);

      return value;
  }
}