/*
 * YodaControl.h
 *
 *  Created on: Jun 4, 2019
 *      Author: harrington
 */

#ifndef SRC_YODACONTROL_H_
#define SRC_YODACONTROL_H_
#include "../config.h"
#include "../StudentsRobot.h"

#if defined(USE_GAME_CONTROL)
#include <WiiChuck.h>

#define PAN_PIN   STEPPER_STEP
#define TILT_PIN STEPPER_DIRECTION
#define JAW_PIN SERVO_PIN

class YodaControl {
	StudentsRobot * robot;
	Accessory * game;
	Servo jaw;
	Servo eyepan;
	Servo eyetilt;
	long lastTime=0;
public:
	YodaControl(StudentsRobot * robot, Accessory * game);
	virtual ~YodaControl();
	void loop();
};
#endif
#endif /* SRC_YODACONTROL_H_ */
