/*
 * WebSocketServer.h
 *
 *  Created on: May 11, 2017
 *      Author: frode
 */

#ifndef MAIN_WEBSOCKETSERVER_H_
#define MAIN_WEBSOCKETSERVER_H_

#include "lwip/api.h"
#include "freertos/FreeRTOS.h"


namespace Sensors {

class WebSocketServer {
public:
	WebSocketServer(int port);
	virtual ~WebSocketServer();

};

} /* namespace Sensors */

#endif /* MAIN_WEBSOCKETSERVER_H_ */
