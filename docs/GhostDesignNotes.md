# Ghost Design Notes

*These design notes are scribbled down as I'm doing research for my autonomous Folkrace cars.*

*I'm trying out several different options for the software, so there are code for both Arduino, FreeRTOS and Mongoose OS. The last one is my main focus now.



## Sensors

* Either up to 8 or up to 16 distance sensors. Hopefully 8 will be enough.
* Compass
* Accelerometer/Gyro
* Wheel encoder

___
## Logic

The math in the car will use Vectors as the main means of calculations. 
Each distance sensor is one vector where the direction is constant (set by how it is mounted on the car), and a variable amplitude (the distance measured). 

By combining two vectors pointing to the same side wall, the angle of the car vs the wall can be calculated using vector math.

In addition, I'll use a vector to describe the desired forward motion. The vector will indicate the direction and speed the car should go.

The speed of the car will be affected by the steering angle. When going straight forward the car will move at a higher speed, than when turning. A sharp turn should be done at a very low speed.

The minimal speed the car can go must be identified.

Using a sensor to measure the rotation of the driveshaft, Odometry can be used.

### Car and sensorssetup

Each sensor will have a constant offset from a common point of the car, describing how far in the X and Y direction the sensor is from the zero-point.

The Zero-point is in the middle between the two rear tires.

The Tread-size is the distance between the two rear wheels, and the Wheelbase is the distance between the rear and front wheels. [1]

Overall car state:

```
{
  env: {
    leftwalll: 32,
    rightwall: 29,
    incline: 3
  },
  pose: {
    velocity: 180,
    direction: 230,
    steering: 76,
    motorspeed: 102,
    odometer: 79
  },
  sensors: {
    irsensor1: true,
    irsensor2: true,
    irsensor3: true,
    irsensor4: false,
    irsensor5: true,
    odometer: true,
    compass: true,
    startmodule: true,
    accelerometer: true
  }
}
```

The modes can be: 'waiting', 'driving', 'stopped'.

Heading is degrees in [0-360].

Speed is in centimeters pr second. It is the actual speed, not the desired speed.
___

## Sensor Fusion

## Math
For Matrix math - http://arma.sourceforge.net. Remains to figure out how to use it from ESP32.

https://www.sciencedirect.com/science/article/pii/S1877050917301473

# Sources
[1] https://www.youtube.com/watch?v=i6uBwudwA5o