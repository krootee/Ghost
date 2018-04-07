/*
 *
 */

#include "mgos_i2c.h"

namespace Sensor {
  class GP2Y0E02B {
    public:
      GP2Y0E02B();
      //GP2Y0E02B(int);

      int get_distance();
      bool detect_device();
    private:
      int i2c_address;
      int shift;
  };
}