#include <Arduino.h>
#include <Servo.h>
#include "../Config/Config.hpp"
#include "../MySD/MySD.hpp"
#include "../TaskManagement/TaskManagement.hpp"

#ifndef __SERVOCONTROLLER__
#define __SERVOCONTROLLER__

#ifdef DEBUG
#define SERVO_DEBUG // Uncomment this line to enable fine grained debugging for the Servo controller operations.
#endif

#define SERVO_ANGULAR_VELOCITY 57.2957795 // in degrees per second
#define MAX_EXECUTION_TIME 300 // in milliseconds
#define ANIMATION_LINE_LENGTH 70

#define LEFT_WING_HOME_POSITION 90
#define RIGHT_WING_HOME_POSITION 90
#define HEAD_HOME_POSITION 90

#define LEFT_WING_FILE_NAME "LEFT_WING"
#define RIGHT_WING_FILE_NAME "RIGHT_WING"
#define HEAD_FILE_NAME "HEAD"

enum class ServoName {
    LEFT_WING,
    RIGHT_WING,
    HEAD,
    SERVO_COUNT
};

struct ServoData {
    const ServoName name;
    Servo servo;
    const byte pin;
    const byte home_position;
    byte target_position;
    short int inter_animation_increment;
};

class ServoController : public Task {
    private:
        ServoData servos[static_cast<byte>(ServoName::SERVO_COUNT)] = {
            {ServoName::LEFT_WING, Servo(), LEFT_WING_SERVO_PIN, LEFT_WING_HOME_POSITION, 255, 255},
            {ServoName::RIGHT_WING, Servo(), RIGHT_WING_SERVO_PIN, RIGHT_WING_HOME_POSITION, 255, 255},
            {ServoName::HEAD, Servo(), HEAD_SERVO_PIN, HEAD_HOME_POSITION, 255, 255}
        };
        byte intra_animation_steps;
        unsigned int millisecods_to_next_frame;
        byte frame_count;
        byte current_frame;
        File file;

        void compute_animation_steps();

        bool next_frame();

        short unsigned int get_required_delay(byte current_position, byte target_position);

        void execute_animation_step();
    public:
        ServoController();
        bool load_animation(String filename, byte frame_count);
        void home(bool first_run);
        short unsigned int set_position(ServoName servo, byte position);
        bool next() override;



};

#endif