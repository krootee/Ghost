#include "mpu9250.hpp"

/*
 * Datasheet: https://www.invensense.com/wp-content/uploads/2015/02/PS-MPU-9250A-01-v1.1.pdf
 * Frode Lillerud, april 2018
 */

#define MPU9250_I2C_ADDRESS 0x69

//Registers
#define MPU9250_PWR_MGMT_1    0x6B  // R/W

namespace Sensor {
  MPU9250::MPU9250() {
    this->i2c_address = MPU9250_I2C_ADDRESS; 
  }

  MPU9250::MPU9250(int i2c_adr) {
    this->i2c_address = i2c_adr;
  }

  void MPU9250::enable() {
    
    //Get global I2C reference
    struct mgos_i2c *i2c = mgos_i2c_get_global();

    //Clear the 'sleep' bit to start the sensor.
    mgos_i2c_write_reg_b(i2c, this->i2c_address, MPU9250_PWR_MGMT_1, 0);
  }

  xyz MPU9250::read_compass() {
    xyz data;
    data.x = 1;
    data.y = 2;
    data.z = 3;
    return data;
  }
}