/*
 * MEMS
 */

#include "mgos.h"
#include "mgos_i2c.h"
#include "mpu6050.hpp"

#define MPU6050_I2C_ADDRESS 0x68

namespace Sensor {
    int mpu6050::get_data() {

        //Get I2C instance
        struct mgos_i2c *i2c = mgos_i2c_get_global();

        //TODO

        return -1;
    }
}