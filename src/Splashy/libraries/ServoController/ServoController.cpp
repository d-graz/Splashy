#include "ServoController.hpp"

ServoController::ServoController() {
    #ifdef DEBUG
    Serial.println(F("Init ServoController class"));
    #endif
    this->file = File();
    for(byte i = 0; i< SERVO_COUNT; i++){
        this->servos[i].attach(servo_pins[i]);
        this->final_target_positions[i] = 255;
        this->computed_increment[i] = 255;
    }
    this->frame_count = 0;
    this->current_frame = 0;
    this->animation_steps = 0;
}

bool ServoController::check_servos() {
    for(byte i = 0; i < SERVO_COUNT; i++){
        if(!this->servos[i].attached()){
            #ifdef DEBUG
            Serial.print(F("Servo "));
            Serial.print(i);
            Serial.println(F(" is not attached"));
            #endif
            return false;
        }
    }
    return true;
}

bool ServoController::load_animation(String filename, byte frame_count) {
    this->file.close();
    this->file = open_file(filename, 'r');
    if(!this->file){
        #ifdef DEBUG
        Serial.print(F("Error opening file : "));
        Serial.println(filename);
        #endif
        return false;
    }
    this->frame_count = frame_count;
    this->current_frame = 0;
    this->status = TaskStatus::READY;
    return true;
}

short unsigned int ServoController::set_position(ServoName servo, byte position){
    byte index = static_cast<byte>(servo);
    #ifdef DEBUG
    Serial.print(F("Setting servo "));
    Serial.print(index);
    Serial.print(F(" to position "));
    Serial.println(position);
    #endif
    byte current_position = this->servos[index].read();
    this->servos[index].write(position);
    #ifdef DEBUG
    Serial.print(F("Associated delay: "));
    Serial.println(this->get_required_delay(current_position, position));
    #endif
    return this->get_required_delay(current_position, position);
}

short unsigned int ServoController::get_required_delay(byte current_position, byte target_position){
    byte diff = abs(current_position - target_position);
    short unsigned int time = (short unsigned int) ceil(float(diff) / SERVO_ANGULAR_VELOCITY);
    return time * 1000;
}

bool ServoController::next_frame() {
    for (byte i = 0; i < SERVO_COUNT; i++){
        this->final_target_positions[i] = this->servos[i].read();
    }
    if(!this->file.available()){
        this->file.seek(0);
    }
    char string[ANIMATION_LINE_LENGTH];
    bool control = read_line(this->file, string, ANIMATION_LINE_LENGTH);
    if (!control){
        #ifdef DEBUG
        Serial.println(F("Bad formatting file or file exceeded specified dimensions"));
        #endif
        return false;
    }
    char* token = strtok(string, " ");
    ServoName servo;
    while (token != NULL){
        if (strcmp(token, LEFT_WING_FILE_NAME) == 0){
            servo = ServoName::LEFT_WING;
        } else if (strcmp(token, RIGHT_WING_FILE_NAME) == 0){
            servo = ServoName::RIGHT_WING;
        } else if (strcmp(token, HEAD_FILE_NAME) == 0){
            servo = ServoName::HEAD;
        } else {
            #ifdef DEBUG
            Serial.print(F("Invalid servo name: "));
            Serial.println(token);
            #endif
            return false;
        }
        token = strtok(NULL, " ");
        if (token == NULL){
            #ifdef DEBUG
            Serial.println(F("Missing associated position"));
            #endif
            return false;
        }
        this->final_target_positions[static_cast<byte>(servo)] = atoi(token);
        token = strtok(NULL, " ");
    }
    if (!this->file.available()){
        #ifdef DEBUG
        Serial.println(F("Missing frame duration"));
        #endif
        return false;
    }
    control = read_line(this->file, string, ANIMATION_LINE_LENGTH);
    if (!control){
        #ifdef DEBUG
        Serial.println(F("Bad formatting file"));
        #endif
        return false;
    }
    this->millisecods_to_next_frame = strtol(string, NULL, 10);
    return true;
}

void ServoController::compute_animation_steps(){
    short unsigned int max_delay = 0;
    byte steps_count = 0;
    for(byte i = 0; i < SERVO_COUNT; i++){
        byte position = this->servos[i].read();
        if (position == this->final_target_positions[i]){
            this->computed_increment[i] = 0;
        } else {
            short unsigned int delay = this->get_required_delay(this->servos[i].read(), this->final_target_positions[i]);
            if (delay > max_delay){
                max_delay = delay;
            }
            this->computed_increment[i] = this->final_target_positions[i] - position;
        }
    }
    steps_count = floor((float) max_delay / (float) MAX_EXECUTION_TIME);
    if (steps_count != 0){
        for(byte i = 0; i < SERVO_COUNT; i++){
            if (this->computed_increment[i] != 0){
                this->computed_increment[i] = floor((float) this->computed_increment[i] / steps_count);
            }
        }
    }
    this->animation_steps = steps_count + 1;
}

void ServoController::home(bool first_run){
    if (first_run){
        for(byte i = 0; i < SERVO_COUNT; i++){
            this->servos[i].write(servo_home_positions[i]);
        }
    } else {
        for(byte i = 0; i < SERVO_COUNT; i++){
            this->final_target_positions[i] = servo_home_positions[i];
            this->compute_animation_steps();
            this->status = TaskStatus::READY;
        }
    }
}

void ServoController::execute_animation_step(){
    if(this->animation_steps == 1){
        for(byte i = 0; i < SERVO_COUNT; i++){
            this->servos[i].write(this->final_target_positions[i]);
        }
        this->animation_steps--;
        return;
    }
    for(byte i = 0; i < SERVO_COUNT; i++){
        byte position = this->servos[i].read();
        this->servos[i].write(position + this->computed_increment[i]);
    }
    this->animation_steps--;
}

bool ServoController::next(){
    if(this->status ==  TaskStatus::DEAD or this->status == TaskStatus::WAITING){
        #ifdef DEBUG
        Serial.println(F("Task is dead or waiting"));
        Serial.println("Generated exception in LedMatrix::next()");
        #endif
        return false;
    }
    if(this->frame_count != 0){
        if (this->current_frame == this->frame_count){
            this->status = TaskStatus::HIBERNATED;
            return true;
        } else {
            this->current_frame++;
        }
    }
    if (this->animation_steps == 0){
        if (!this->next_frame()){
            #ifdef DEBUG
            Serial.println(F("Error loading next frame"));
            #endif
            return false;
        }
        this->compute_animation_steps();
        this->execute_animation_step();
        return true;
    }
    this->execute_animation_step();
    if(this->animation_steps == 0){
        this->sleep_time_millis = this->millisecods_to_next_frame;
        this->update_next_execution_millis();
    }
    return true;
}