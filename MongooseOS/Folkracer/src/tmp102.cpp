#include "tmp102.hpp"
#include <bitset>

  /*
   * Mongoose OS driver for TMP102 temperature sensor
   * 
   * Author:    Frode Lillerud
   * Date:      2018-03-30
   * DataSheet: http://www.ti.com/lit/ds/symlink/tmp102.pdf
   */

#define TMP102_I2C_ADDRESS_GND  0x48
#define TMP102_I2C_ADDRESS_VCC  0x49
#define TMP102_I2C_ADDRESS_SDA  0x50
#define TMP102_I2C_ADDRESS_SCL  0x51

#define TMP102_REGISTER_TEMP    0
#define TMP102_REGISTER_CONFIG  1
#define TMP102_REGISTER_TLOW    2
#define TMP102_REGISTER_THIGH   3

namespace Sensor {

  //Default constructor
  TMP102::TMP102() {
    this->i2c_address = TMP102_I2C_ADDRESS_GND; //Default I2C address
  }

  //Constructor for passing in alternative I2C address
  TMP102::TMP102(int i2caddr) {
    this->i2c_address = i2caddr;
  }

  /*
   * Check to see if I2C device responds
   */
  bool TMP102::detect_device() {
    struct mgos_i2c *i2c = mgos_i2c_get_global();
    return mgos_i2c_read_reg_b(i2c, this->i2c_address, TMP102_REGISTER_TEMP) != -1;
  }

  /*
   * Reads the config from Configuration register
   */
  int TMP102::read_configuration() {
    //Get reference to the global I2C instance
    struct mgos_i2c *i2c = mgos_i2c_get_global();
    //Read two bytes from CONFIG register
    int config = mgos_i2c_read_reg_w(i2c, this->i2c_address, TMP102_REGISTER_CONFIG);
    return config;
  }

  /*
   * Reads data from Config and Temperature registers, and return temp in Celsius.
   */
  float TMP102::read_temperature() {

    //Get reference to the global I2C instance
    struct mgos_i2c *i2c = mgos_i2c_get_global();
    
    //Read config settings
    int config = this->read_configuration();
    std::bitset<16> config_bits(config);

    bool extended_mode = config_bits.test(4); //Fifth bit
    //bool alert = config_bits.test(5);
    //bool shutdown_mode = config_bits.test(8);
    //bool thermostat_mode = config_bits.test(9);
    //bool polarity = config_bits.test(10);

    //Read data from the REG_TMP register
    int register_tmp_value = mgos_i2c_read_reg_w(i2c, this->i2c_address, TMP102_REGISTER_TEMP);

    if (register_tmp_value == -1)
      LOG(LL_ERROR, ("Unable to read REG_TMP from TMP102"));
    else {

      //Isolate the relevant bits from the TMP registy value.
      int twelve_bits = (register_tmp_value >> 4);
      //int thirteen_bits = (register_tmp_value >> 3); //TODO: Use when Extended mode set.
      float resolution = 0.0625;

      bool is_positive = !config_bits.test(11); //Is twelfth bit set?

      //Find and return temperature
      if (is_positive && !extended_mode) {
        //Most common scenario - positive temperature and 'normal' mode.
        return twelve_bits * resolution;
      } else if (!is_positive && !extended_mode) {
        //Negative temperature and 'normal' mode
        //Under freezing temperature (0 celsius)
        //NB - NOT CORRECT BELOW!!!! Needs fixing.
        int twos_complement = -twelve_bits+1; //Notice negative sign.
        return twos_complement * resolution * -1;
      } else {
        //TODO - extended mode
      }
    }

    return 999.99; // Error
  }
}