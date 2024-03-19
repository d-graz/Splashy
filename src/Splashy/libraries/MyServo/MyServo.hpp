/**
 * @file MyServo.hpp
 * @brief Header file for the ServoMotor class.
 */

#include<Servo.h>
#include "../Config/Config.hpp"

#ifndef __MYSERVO__
#define __MYSERVO__

typedef struct Command {
    ServoMotor* servo;
    short unsigned int final_position;
    //short unsigned int 
}Command_t;

/**
 * @class ServoMotor
 * @brief Class to control a servo motor.
 */
class ServoMotor {
    private:
        Servo servo; ///< Servo object to control the servo motor.
        static short unsigned int initial_position; ///< Initial position of the servo motor.

    public:
        /**
         * @brief Constructor for the ServoMotor class.
         * @param pin The pin number where the servo motor is connected.
         * @param initial_position The initial position of the servo motor.
         */
        ServoMotor(short unsigned int pin, short unsigned int initial_position);

        /**
         * @brief Writes an angle to the servo motor.
         * @param angle The angle to write to the servo motor.
         */
        void write(short unsigned int angle);

        /**
         * @brief Reads the current angle of the servo motor.
         * @return The current angle of the servo motor.
         */
        short unsigned int read();

        /**
         * @brief Checks if the servo motor is attached.
         * @return True if the servo motor is attached, false otherwise.
         */
        bool attached();
};


#endif