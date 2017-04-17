/*
 * StartModule.cpp
 *
 *  Created on: Apr 17, 2017
 *      Author: frode
 */

#include "StartModule.h"

StartModule::StartModule(int pin) {
	//TODO, add interrupt code here.

}

StartModule::~StartModule() {
}

eStartModuleState StartModule::getCurrentState() {
	return this->state;
}

void StartModule::GoToNextState() {
	if (this->state == eStartModuleState::WAITING)
		this->state = eStartModuleState::RUNNING;
	else if (this->state == eStartModuleState::RUNNING)
		this->state = eStartModuleState::STOPPED;
}
