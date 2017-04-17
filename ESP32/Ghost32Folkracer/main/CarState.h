/*
 * CarState.h
 *
 *  Created on: Apr 16, 2017
 *      Author: frode
 */

#ifndef MAIN_CARSTATE_H_
#define MAIN_CARSTATE_H_

class CarState {
public:
	CarState();
	virtual ~CarState();

	static 	CarState& getInstance();

	void motor_set_speed(int);

private:

	//CarState() {}

	CarState(CarState const&) = delete;
	void operator=(CarState const&) = delete;

	int DesiredSpeed;
	int StartModule;
};

#endif /* MAIN_CARSTATE_H_ */
