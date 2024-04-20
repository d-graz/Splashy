/**
 * @file Config.hpp
 * @brief Pinout configuration for the Splashy project.
 */

#ifndef __CONFIG__
#define __CONFIG__

// configuration for the SD card
#define SD_CSPIN 7

// configuration for the LED matrix
#define LED_MATRIX_DATA_PIN 2
#define LED_MATRIX_CLK_PIN 4
#define LED_MATRIX_CS_PIN 3

// servo motors pins
#define LEFT_WING_SERVO_PIN 13
#define RIGHT_WING_SERVO_PIN 12
#define HEAD_SERVO_PIN 11

// proximity sensor pins
#define PROXIMITY_SENSOR_PIN 25

// ultrasonic sensor pins
#define ULTRASONIC_SENSOR_TRIGGER_PIN 26
#define ULTRASONIC_SENSOR_ECHO_PIN 27

// flow sensor pins
#define FLOW_SENSOR_PIN 28

// potentiometer pin
#define POTENTIOMETER_PIN A3

// pump pin
#define PUMP_PIN 29

// touch sensor pin
#define TOUCH_SENSOR_PIN_SEND 30 // digital pin
#define TOUCH_SENSOR_PIN_RECIVE 31 // PWM pin

#endif