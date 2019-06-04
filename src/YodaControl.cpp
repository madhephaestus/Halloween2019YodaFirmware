/*
 * YodaControl.cpp
 *
 *  Created on: Jun 4, 2019
 *      Author: harrington
 */

#include "YodaControl.h"

#if defined(USE_GAME_CONTROL)
static float mapf(float x, float in_min, float in_max, float out_min, float out_max) {
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
YodaControl::YodaControl(PIDMotor * motor1, PIDMotor * motor2,
		Accessory * game) {
	this->motor1 = motor1;
	this->motor2 = motor2;
	this->game = game;
	jaw.attach(JAW_PIN);
	eyepan.attach(PAN_PIN);
	eyetilt.attach(TILT_PIN);
	// Create a module to deal with the demo wrist bevel gears
	wristPtr = new GearWrist(motor1, //right motor
		motor2, // left motor
			16.0 * // Encoder CPR
					50.0 * // Motor Gear box ratio
					2.5347 * // Wrist gear stage ratio
					(1.0 / 360.0) * // degrees per revolution
					2, // full quadrature, 4 ticks be encoder count, half is 2 and single mode is one
			0.8932); // ratio of second stage to first stage
}

YodaControl::~YodaControl() {
	// TODO Auto-generated destructor stub
}
void YodaControl::loop() {
	if (lastTime > millis() - 20) {
		lastTime = millis();
	} else
		return;
	for (int i = 0; i < WII_VALUES_ARRAY_SIZE; i++) {
		Serial.println(
				"Controller Val " + String(i) + " = "
						+ String((uint8_t) game->values[i]));
	}
	float Servo1Val = mapf((float) game->values[1], 0.0, 255.0, -15.0, 15.0);
	float Servo3Val = mapf((float) game->values[0], 0.0, 255.0, -60.0, 60.0); // z button
	int panVal = map(game->values[2], 0, 255, 35, 148);
	int jawVal = map(game->values[5] > 0 ? 0 : // Upper button pressed
			(game->values[18] > 0 ? 255 : // Lower button pressed
					128) //neither pressed
			, 0, 255, 80, 140);
	int tiltVal = map(game->values[3], 0, 255, 24, 120); // z button
	eyepan.write(panVal);
	eyetilt.write(tiltVal);
	jaw.write(jawVal);
	wristPtr->setTarget(Servo1Val, Servo3Val);
}
#endif
