#include "tmp102.hpp"

namespace Sensor {

  /*
   * Mongoose OS driver for TMP102 temperature sensor
   * 
   * Author:    Frode Lillerud
   * Date:      2018-03-30
   * DataSheet: http://www.ti.com/lit/ds/symlink/tmp102.pdf
   */

  TMP102::TMP102() {
    this->i2c_address = 0x48; //Default address
  }

  TMP102::TMP102(int i2caddr) {
    this->i2c_address = i2caddr;
  }

  float TMP102::readTemperature() {

    //Get reference to the global I2C instance
    struct mgos_i2c *i2c = mgos_i2c_get_global();

    char data[2];
    //Read data from the REG_TMP register
    int register_tmp = 0;
    int register_tmp_value = mgos_i2c_read_reg_w(i2c, this->i2c_address, (uint8_t*) register_tmp);

    if (register_tmp_value == -1)
      LOG(LL_ERROR, ("Unable to read REG_TMP from TMP102"));

    //TODO, convert the read value to a temperature

    return 99.99;
  }
}