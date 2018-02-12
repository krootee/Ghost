/*
 * The GP2Y0E02B IR Sensor
 * Range: 4-50cm
 */

#include "mgos.h"
#include "mgos_i2c.h"
#include "gp2y0e02b.hpp"
#include <math.h>

#define I2C_ADDRESS     0x40
#define SHIFT_REG       0x35
#define DISTANCE_REG    0x5E

namespace Sensor {
    int GP2Y0E02B::getDistance() {

        //Get reference to the global I2C instance
        struct mgos_i2c *i2c = mgos_i2c_get_global();

        //Point to SHIFT registry
        //short data[2] = {SHIFT_REG, 1};
        //mgos_i2c_write(i2c, I2C_ADDRESS, data, 2, true);

        //Read one byte from SHIFT register
        int shift = mgos_i2c_read_reg_b(i2c, I2C_ADDRESS, SHIFT_REG);
        if (shift == -1) {
            LOG(LL_ERROR, ("Unable to read value from SHIFT register"));
        } else {
            LOG(LL_INFO, ("Success, got data from SHIFT register: %d", shift));
        }

        //Point to DISTANCE register
        
        //Read two bytes from DISTANCE register
        int value = mgos_i2c_read_reg_w(i2c, I2C_ADDRESS, DISTANCE_REG);
        LOG(LL_INFO, ("Distance = %d", value));
        //return value;
        //Calculate distance
        //short high = data[0], low = data[1];
        //short high = value 
        //int distance_in_cm = (high * 16 + low)/16/(int)pow(2,shift);

        return -1;
    }
}