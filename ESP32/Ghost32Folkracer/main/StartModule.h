/*
 * StartModule.h
 *
 *  Created on: Apr 17, 2017
 *      Author: frode
 */

#ifndef MAIN_STARTMODULE_H_
#define MAIN_STARTMODULE_H_

enum eStartModuleState : int {
  WAITING = 0,
  RUNNING = 1,
  STOPPED = 2
};


class StartModule {
public:
	StartModule(int);
	virtual ~StartModule();

	eStartModuleState getCurrentState();
	void GoToNextState();
private:
	eStartModuleState state;
};


#endif /* MAIN_STARTMODULE_H_ */
