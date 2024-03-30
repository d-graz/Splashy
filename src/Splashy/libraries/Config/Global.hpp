/**
 * @file Global.hpp
 * @brief Global variables for the Splashy project.
 */
#ifndef __GLOBAL__
#define __GLOBAL__

#include "../LedMatrix/LedMatrix.hpp"
#include "../TaskManagement/TaskManagement.hpp"
#include "../ServoController/ServoController.hpp"

// led matrix object
LedMatrix *led_matrix;

// scheduler
Scheduler *scheduler;

// sevo controller
ServoController *servo_controller;

#endif