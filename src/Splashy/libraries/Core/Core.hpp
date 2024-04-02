/**
 * @file Core.hpp
 * @brief Core library for Splashy project.
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

#endif