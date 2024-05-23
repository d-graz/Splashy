/**
 * @file Config.hpp
 * @brief Pinout configuration for the Splashy project.
 */

#ifndef __CONFIG__
#define __CONFIG__

/// @defgroup sd_card_configuration SD Card Configuration
/// @{
#define SD_CSPIN 7 ///< Configuration for the SD card's Chip Select pin.
// other sd pin not configurable
// MISO 50
// MOSI 51
// SCK 52
/// @}


/// @defgroup led_matrix_configuration LED Matrix Configuration
/// @{
#define LED_MATRIX_DATA_PIN 2 ///< Data pin for the LED matrix.
#define LED_MATRIX_CLK_PIN 4  ///< Clock pin for the LED matrix.
#define LED_MATRIX_CS_PIN 3   ///< Chip Select pin for the LED matrix.
/// @}

/// @defgroup servo_motors_pins Servo Motors Pins
/// @{
#define LEFT_WING_SERVO_PIN 13  ///< Pin for the left wing servo motor.
#define RIGHT_WING_SERVO_PIN 12 ///< Pin for the right wing servo motor.
#define HEAD_SERVO_PIN 11       ///< Pin for the head servo motor.
/// @}

/// @defgroup proximity_sensor_pin Proximity Sensor Pin
/// @{
#define PROXIMITY_SENSOR_PIN 25 ///< Pin for the proximity sensor.
/// @}

/// @defgroup ultrasonic_sensor_pins Ultrasonic Sensor Pins
/// @{
#define ULTRASONIC_SENSOR_TRIGGER_PIN 26 ///< Trigger pin for the ultrasonic sensor.
#define ULTRASONIC_SENSOR_ECHO_PIN 27    ///< Echo pin for the ultrasonic sensor.
/// @}

/// @defgroup flow_sensor_pin Flow Sensor Pin
/// @{
#define FLOW_SENSOR_PIN 19 ///< Pin for the flow sensor.
/// @}

/// @defgroup potentiometer_pin Potentiometer Pin
/// @{
#define POTENTIOMETER_PIN A3 ///< Pin for the potentiometer.
/// @}

/// @defgroup pump_pin Pump Pin
/// @{
#define PUMP_PIN 29 ///< Pin for the pump.
/// @}

/// @defgroup touch_sensor_pins Touch Sensor Pins
/// @{
#define TOUCH_SENSOR_PIN_SEND 30 ///< Digital pin for sending touch sensor data.
#define TOUCH_SENSOR_PIN_RECIVE 9 ///< PWM pin for receiving touch sensor data.
/// @}

#endif