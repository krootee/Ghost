/*
 * The GP2Y0E02B IR Sensor
 * Datasheet:         http://www.sharp-world.com/products/device/lineup/data/pdf/datasheet/gp2y0e02b_e.pdf
 * Application note:  http://www.sharp-world.com/products/device/lineup/data/pdf/datasheet/gp2y0e02_03_appl_e.pdf
 * Range:             4-50cm
 * Author:            Frode Lillerud
 * Date:              April 2018
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

    //Get the value from the Shift-register
    struct mgos_i2c *i2c = mgos_i2c_get_global();
    this->shift = mgos_i2c_read_reg_b(i2c, this->i2c_address, GP2Y0E02B_REGISTER_SHIFT);
//    if (this->shift == -1)
//     LOG(LL_ERROR, ("Unable to read from SHIFT register"));
  }

  bool GP2Y0E02B::detect_device() {
    struct mgos_i2c *i2c = mgos_i2c_get_global();

    return mgos_i2c_read_reg_b(i2c, this->i2c_address, GP2Y0E02B_REGISTER_DISTANCE) != -1;
  }

  //Get distance in Centimeters
  int GP2Y0E02B::get_distance() {

      //Get reference to the global I2C instance
      struct mgos_i2c *i2c = mgos_i2c_get_global();

      //Read two bytes from DISTANCE register
      int data = mgos_i2c_read_reg_w(i2c, GP2Y0E02B_I2C_ADDRESS, GP2Y0E02B_REGISTER_DISTANCE);

      //Calculate distance
      short low = data & 0xFF;
      short high = (data >> 8);
      int distance_in_cm = (high * 16 + low)/16/(int)pow(2,shift);

      return distance_in_cm;
  }
}