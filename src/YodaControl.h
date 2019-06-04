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
#include "GearWrist.h"
#define PAN_PIN   STEPPER_STEP
#define TILT_PIN STEPPER_DIRECTION
#define JAW_PIN SERVO_PIN

class YodaControl {
	PIDMotor * motor1;
	PIDMotor * motor2;
	Accessory * game;
	Servo jaw;
	Servo eyepan;
	Servo eyetilt;
	long lastTime=0;
	GearWrist * wristPtr;
public:
	YodaControl(PIDMotor * motor1,
			PIDMotor * motor2, Accessory * game);
	virtual ~YodaControl();
	void loop();
};
#endif
#endif /* SRC_YODACONTROL_H_ */
