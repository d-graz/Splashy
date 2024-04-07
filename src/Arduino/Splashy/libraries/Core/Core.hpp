/**
 * @file Core.hpp
 * @brief Core library for Splashy project.
 * @version 1.1
 *
 * This library provides shared functionalities for the Splashy project for example error handling.
 */

#ifndef __CORE__
#define __CORE__

#include "../Config/Global.hpp"

/**
 * @brief Handles errors in the Splashy project.
 *
 * This function is used throughout the Splashy project to handle errors. It takes an execution status and an error message, and performs appropriate error handling.
 *
 * @param execution_status The status of the execution. A value of true indicates success, and a value of false indicates an error.
 * @param error_message The error message to be used if an error occurred. This defaults to "An error occurred" if no message is provided.
 */
void handle_error(bool execution_status, String error_message = "An error occurred");

/**
 * @brief Maps a number from one range to another.
 * 
 * This function takes a number `x` from the range `in_min` to `in_max` and maps it to a new range `out_min` to `out_max`.
 * It's similar to the Arduino `map` function, but works with floats.
 *
 * @param x The number to map.
 * @param in_min The lower bound of the range `x` is coming from.
 * @param in_max The upper bound of the range `x` is coming from.
 * @param out_min The lower bound of the range `x` is mapped to.
 * @param out_max The upper bound of the range `x` is mapped to.
 * @return The mapped value of `x`.
 */
float map_float(float x, float in_min, float in_max, float out_min, float out_max);

#endif