#include "tca9548.hpp"

/*
 * Mongoose OS driver for TCA9548 I2C multiplexer chip
 * Chip has eight I2C channels.
 * It has only one, implicit, I2C register.
 * Author:    Frode Lillerud
 * Date:      2018-03-31
 */

#define TCA9548_I2C_ADDR  0x70
#define I2C_READ_ERROR    -1

namespace Sensor {

  //Default constructor
  TCA9548::TCA9548() {
    this->i2c_address = TCA9548_I2C_ADDR;
  }

  //Constructor
  TCA9548::TCA9548(int i2caddr) {
    this->i2c_address = i2caddr;
  }

  /*
   * Check if the device is found on the I2C bus.
   */
  bool TCA9548::detect_device() {
    return this->get_channel() != I2C_READ_ERROR;
  }

  /*
   * Get the active channel number.
   * Returns a number between 0 and 7 if successful.
   * Returns -1 if unable to talk to I2C device.
   */
  int TCA9548::get_channel() {

    //Get global I2C reference
    struct mgos_i2c *i2c = mgos_i2c_get_global();

    //Read the currently set channel
    uint8_t data;
    if (mgos_i2c_read(i2c, this->i2c_address, &data, sizeof(data), true)) {
      return data;
    } else {
      return I2C_READ_ERROR;
    }
  }

  /*
   * Set the active channel
   * Returns true if successful write, or false if unable to write.
   */
  bool TCA9548::set_channel(uint8_t channel) {

    //Only channels between 0 and 7 allowed.
    if (channel < 0 || channel > 7)
      return false;

    //Get global I2C reference
    struct mgos_i2c *i2c = mgos_i2c_get_global();

    //Write the channelnumber to the device, and return true if success.
    return mgos_i2c_write(i2c, this->i2c_address, (void*) &channel, sizeof(channel), true);
  }
}