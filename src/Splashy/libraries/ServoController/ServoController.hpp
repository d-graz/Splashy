#ifndef __SERVOCONTROLLER__
#define __SERVOCONTROLLER__

#include <Arduino.h>
#include <Servo.h>
#include "../Config/Config.hpp"
#include "../MySD/MySD.hpp"
#include "../TaskManagement/TaskManagement.hpp"

#define SERVO_COUNT 3
#define SERVO_ANGULAR_VELOCITY 57.2957795 // in degrees per second
#define MAX_EXECUTION_TIME 300 // in milliseconds
#define ANIMATION_LINE_LENGTH 30

#define LEFT_WING_HOME_POSITION 90
#define RIGHT_WING_HOME_POSITION 90
#define HEAD_HOME_POSITION 90

#define LEFT_WING_FILE_NAME "LEFT_WING"
#define RIGHT_WING_FILE_NAME "RIGHT_WING"
#define HEAD_FILE_NAME "HEAD"

enum class ServoName {
    LEFT_WING,
    RIGHT_WING,
    HEAD
};

const byte servo_home_positions[SERVO_COUNT] = {LEFT_WING_HOME_POSITION, RIGHT_WING_HOME_POSITION, HEAD_HOME_POSITION};
const byte servo_pins[SERVO_COUNT] = {LEFT_WING_SERVO_PIN, RIGHT_WING_SERVO_PIN, HEAD_SERVO_PIN};

class ServoController : public Task {
    private:
        Servo servos[SERVO_COUNT];
        byte final_target_positions[SERVO_COUNT];
        byte computed_increment[SERVO_COUNT];
        byte animation_steps;
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
        bool check_servos();
        bool load_animation(String filename, byte frame_count);
        void home(bool first_run);
        short unsigned int set_position(ServoName servo, byte position);
        bool next() override;



};

#endif