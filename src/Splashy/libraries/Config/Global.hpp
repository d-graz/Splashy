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

// led matrix object
LedMatrix *led_matrix;

// sevo controller
ServoController *servo_controller;

// proximity sensor
ProximitySensor *proximity_sensor;

// ultrasonic sensor
UltrasonicSensor *ultrasonic_sensor;

#endif