/*
 * ActuatorCommands.h
 *
 *  Created on: Apr 13, 2017
 *      Author: frode
 */

#ifndef MAIN_ACTUATORCOMMANDS_H_
#define MAIN_ACTUATORCOMMANDS_H_

class ActuatorCommands {
public:
	ActuatorCommands();
	virtual ~ActuatorCommands();

	void SetMotorSpeed(int);
	void SetSteeringAngle(int);

private:
	int motor_speed;
	int steering_angle;
};

#endif /* MAIN_ACTUATORCOMMANDS_H_ */
