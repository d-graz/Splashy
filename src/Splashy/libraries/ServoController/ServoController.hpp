/**
 * @file ServoController.hpp
 * @brief Header file for the ServoController class.
 * @version 2.4
 */
//TODO: [LOW] Add a struct to include path of the animation file for the servo controller class

#include <Arduino.h>
#include <Servo.h>
#include "../Config/Config.hpp"
#include "../MySD/MySD.hpp"
#include "../TaskManagement/TaskManagement.hpp"

#ifndef __SERVOCONTROLLER__
#define __SERVOCONTROLLER__

#ifdef DEBUG
//#define SERVO_DEBUG ///< Enable fine grained debugging for the Servo controller operations.
#endif

#define SERVO_ANGULAR_VELOCITY 15.13 ///< Servo angular velocity in degrees per second.
#define MAX_EXECUTION_TIME 300 ///< Maximum execution time in milliseconds.
#define ANIMATION_LINE_LENGTH 70 ///< Length of animation line.

#define LEFT_WING_HOME_POSITION 90 ///< Home position for the left wing.
#define RIGHT_WING_HOME_POSITION 90 ///< Home position for the right wing.
#define HEAD_HOME_POSITION 90 ///< Home position for the head.

#define LEFT_WING_FILE_NAME "LEFT_WING" ///< File name for the left wing.
#define RIGHT_WING_FILE_NAME "RIGHT_WING" ///< File name for the right wing.
#define HEAD_FILE_NAME "HEAD" ///< File name for the head.

/**
 * @enum ServoName
 * @brief Enum for naming the servos.
 */
enum class ServoName {
    LEFT_WING, ///< Left wing servo.
    RIGHT_WING, ///< Right wing servo.
    HEAD, ///< Head servo.
    SERVO_COUNT ///< Total count of servos.
};

/**
 * @struct ServoData
 * @brief Struct for storing servo data.
 */
struct ServoData {
    const ServoName name; ///< Name of the servo.
    Servo servo; ///< Servo object.
    const byte pin; ///< Pin connected to the servo.
    const byte home_position; ///< Home position of the servo.
    byte target_position; ///< Target position of the servo.
};

/**
 * @class ServoController
 * @brief Class for controlling servos.
 */
class ServoController : public Task {
    private:
        ServoData servos[static_cast<byte>(ServoName::SERVO_COUNT)] = {
            {ServoName::LEFT_WING, Servo(), LEFT_WING_SERVO_PIN, LEFT_WING_HOME_POSITION, LEFT_WING_HOME_POSITION},
            {ServoName::RIGHT_WING, Servo(), RIGHT_WING_SERVO_PIN, RIGHT_WING_HOME_POSITION, RIGHT_WING_HOME_POSITION},
            {ServoName::HEAD, Servo(), HEAD_SERVO_PIN, HEAD_HOME_POSITION, HEAD_HOME_POSITION}
        }; ///< Array of servos.
        byte frame_count; ///< Count of frames.
        byte current_frame; ///< Current frame.
        File file; ///< File object.

        /**
         * @brief Compute the minimum delay.
         * @param lower_bound Lower bound for the delay.
         */
        void compute_minimum_delay(short unsigned int lower_bound);

        /**
         * @brief Get the next frame.
         * @return True if successful, false otherwise.
         */
        bool next_frame();

        /**
         * @brief Get the required delay to reach the target position from the current position.
         * @param current_position Current position of the servo.
         * @param target_position Target position of the servo.
         * @return Required delay in milliseconds.
         */
        short unsigned int get_required_delay(byte current_position, byte target_position);

        /**
         * @brief Execute the animation step.
         */
        void execute_animation_step();
    public:
        /**
         * @brief Constructor for ServoController class.
         *
         * Initializes a new instance of the ServoController class with a given name.
         *
         * @param name The name of the task. This is passed to the base Task class.
         */
        ServoController(const char* name);

        /**
         * @brief Load an animation from a file.
         * @param filename Name of the file.
         * @param frame_count Count of frames in the animation.
         * @return True if successful, false otherwise.
         */
        bool load_animation(String filename, byte frame_count);

        /**
         * @brief Move the servos to their home positions.
         * @param first_run True if this function is executed in the setup, false otherwise.
         */
        void home(bool first_run);

        /**
         * @brief Set the position of a servo.
         * @param servo Name of the servo.
         * @param position Target position.
         * @return Required delay in milliseconds to reach the target position.
         */
        short unsigned int set_position(ServoName servo, byte position);

        /**
         * @brief Get the next task.
         * @return True if successful, false otherwise.
         */
        bool next() override;
};

#endif