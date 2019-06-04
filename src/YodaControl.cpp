/*
 * YodaControl.cpp
 *
 *  Created on: Jun 4, 2019
 *      Author: harrington
 */

#include "YodaControl.h"

#if defined(USE_GAME_CONTROL)
YodaControl::YodaControl(StudentsRobot * robot, Accessory * game) {
	// TODO Auto-generated constructor stub
	this->game=game;
	this->robot=robot;
	jaw.attach(JAW_PIN);
	eyepan.attach(PAN_PIN);
	eyetilt.attach(TILT_PIN);
}

YodaControl::~YodaControl() {
	// TODO Auto-generated destructor stub
}
void YodaControl::loop(){
	if(lastTime>millis()-20){
		lastTime=millis();
	}else
		return;
	for (int i = 0; i < WII_VALUES_ARRAY_SIZE; i++) {
		Serial.println(
				"Controller Val " + String(i) + " = "
						+ String((uint8_t) game->values[i]));
	}

}
#endif
