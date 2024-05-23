/**
 * @file Global.hpp
 * @brief Global sensor variables for the Splashy project.
 */
#ifndef __GLOBAL__
#define __GLOBAL__

#include "../LedMatrix/LedMatrix.hpp"
#include "../TaskManagement/TaskManagement.hpp"
#include "../ServoController/ServoController.hpp"
#include "../ProximitySensor/ProximitySensor.hpp"
#include "../UltrasonicSensor/UltrasonicSensor.hpp"
#include "../Pump/Pump.hpp"
#include "../TouchSensor/TouchSensor.hpp"

/// @brief LED matrix object.
LedMatrix *led_matrix;

/// @brief Servo controller object.
ServoController *servo_controller;

/// @brief Proximity sensor object.
ProximitySensor *proximity_sensor;

/// @brief Ultrasonic sensor object.
UltrasonicSensor *ultrasonic_sensor;

/// @brief Pump object.
Pump *pump;

/// @brief Touch sensor object.
TouchSensor *touch_sensor;

#endif