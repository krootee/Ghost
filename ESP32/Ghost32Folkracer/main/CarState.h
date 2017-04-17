/*
 * CarState.h
 *
 *  Created on: Apr 16, 2017
 *      Author: frode
 */

#ifndef MAIN_CARSTATE_H_
#define MAIN_CARSTATE_H_

#include "StartModule.h"

//https://www.codeproject.com/Articles/1921/Singleton-Pattern-its-implementation-with-C

class CarState {
public:

	virtual ~CarState();

	static 	CarState* getInstance();

	void motor_set_speed(int);

	eStartModuleState startmodule_state;

private:

	static bool instanceFlag;
	static CarState* instance;
	CarState(); //The constructor is private


	//CarState(CarState const&) = delete;
	//void operator=(CarState const&) = delete;

	int DesiredSpeed;
	int StartModule;
};

#endif /* MAIN_CARSTATE_H_ */
