#include "ServoController.hpp"

ServoController::ServoController() {
    #ifdef SERVO_DEBUG
    Serial.println(F("Init ServoController class"));
    #endif
    for(byte i = 0; i < static_cast<byte>(ServoName::SERVO_COUNT); i++){
        this->servos[i].servo.attach(this->servos[i].pin);
    }
    #ifdef SERVO_DEBUG
    Serial.println(F("Checking if servos are attached"));
    for(byte i = 0; i < static_cast<byte>(ServoName::SERVO_COUNT); i++){
        if(!this->servos[i].servo.attached()){
            Serial.print(F("Servo "));
            Serial.print(i);
            Serial.println(F(" is not attached!!!!"));
        }
    }
    #endif
    this->file = File();
    this->frame_count = 0;
    this->current_frame = 0;
    this->intra_animation_steps = 0;
}

bool ServoController::load_animation(String filename, byte frame_count) {
    this->file.close();
    this->file = open_file(filename, 'r');
    if(!this->file){
        #ifdef DEBUG
        Serial.println(F("Generated error in ServoController::load_animation()"));
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
    #ifdef SERVO_DEBUG
    Serial.print(F("Setting servo "));
    Serial.print(index);
    Serial.print(F(" to position "));
    Serial.println(position);
    #endif
    byte current_position = this->servos[index].servo.read();
    this->servos[index].servo.write(position);
    #ifdef SERVO_DEBUG
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
    #ifdef SERVO_DEBUG
    Serial.println(F("Advancing to the next frame"));
    #endif
    for (byte i = 0; i < static_cast<byte>(ServoName::SERVO_COUNT); i++){
        this->servos[i].target_position = this->servos[i].servo.read();
        #ifdef SERVO_DEBUG
        Serial.print(F("Servo "));
        Serial.print(i);
        Serial.print(F(" target position: "));
        Serial.println(this->servos[i].target_position);
        #endif
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
        this->servos[static_cast<byte>(servo)].target_position = atoi(token);
        #ifdef SERVO_DEBUG
        Serial.print(F("Servo "));
        Serial.print(static_cast<byte>(servo));
        Serial.print(F(" target position: "));
        Serial.println(this->servos[static_cast<byte>(servo)].target_position);
        #endif
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
    #ifdef SERVO_DEBUG
    Serial.print(F("Sleep time loaded from animation: "));
    Serial.println(this->millisecods_to_next_frame);
    Serial.println(F("Setting up animation steps"));
    #endif
    this->compute_animation_steps();
    #ifdef SERVO_DEBUG
    Serial.println(F("Animation steps computed"));
    #endif
    return true;
}

void ServoController::compute_animation_steps(){
    short unsigned int max_delay = 0;
    byte steps_count = 0;
    for(byte i = 0; i < static_cast<byte>(ServoName::SERVO_COUNT); i++){
        byte position = this->servos[i].servo.read();
        if (position == this->servos[i].target_position){
            this->servos[i].inter_animation_increment = 0;
        } else {
            short unsigned int delay = this->get_required_delay(position, this->servos[i].target_position);
            if (delay > max_delay){
                max_delay = delay;
            }
            this->servos[i].inter_animation_increment = static_cast<short int>(this->servos[i].target_position) - static_cast<short int>(position);
        }
    }
    steps_count = floor((float) max_delay / (float) MAX_EXECUTION_TIME);
    if (steps_count != 0){
        for(byte i = 0; i < static_cast<byte>(ServoName::SERVO_COUNT); i++){
            if (this->servos[i].inter_animation_increment != 0){
                this->servos[i].inter_animation_increment = floor((float) this->servos[i].inter_animation_increment / steps_count);
            }
        }
    }
    this->intra_animation_steps = steps_count + 1;
    #ifdef SERVO_DEBUG
    Serial.print(F("Intra animation steps: "));
    Serial.println(this->intra_animation_steps);
    for(byte i = 0; i < static_cast<byte>(ServoName::SERVO_COUNT); i++){
        Serial.print(F("Servo "));
        Serial.print(i);
        Serial.print(F(" increment: "));
        Serial.println(this->servos[i].inter_animation_increment);
    }
    #endif
}

//FIXME: [HIGH] when calling home(false) there is a bug
void ServoController::home(bool first_run){
    if (first_run){
        for(byte i = 0; i < static_cast<byte>(ServoName::SERVO_COUNT); i++){
            delay(this->set_position(static_cast<ServoName>(i), this->servos[i].home_position));
        }
    } else {
        for(byte i = 0; i < static_cast<byte>(ServoName::SERVO_COUNT); i++){
            this->servos[i].target_position = this->servos[i].home_position;
            this->compute_animation_steps();
            this->status = TaskStatus::READY;
        }
    }
}

void ServoController::execute_animation_step(){
    for(byte i = 0; i < static_cast<byte>(ServoName::SERVO_COUNT); i++){
        byte position = this->servos[i].servo.read();
        if(this->intra_animation_steps == 1){
            if(this->servos[i].target_position != position){
                this->set_position(static_cast<ServoName>(i), this->servos[i].target_position);
            } 
        } else {
            short int final_position = this->servos[i].inter_animation_increment + static_cast<short int>(position);
            if(final_position > 180){
                this->set_position(static_cast<ServoName>(i), 180);
            } else if(final_position < 0){
                this->set_position(static_cast<ServoName>(i), 0);
            } else {
                this->set_position(static_cast<ServoName>(i), static_cast<byte>(final_position));
            }
        }
    }
    this->intra_animation_steps--;
}

bool ServoController::next(){
    if(this->status ==  TaskStatus::DEAD or this->status == TaskStatus::WAITING){
        #ifdef DEBUG
        Serial.println(F("Task is dead or waiting"));
        Serial.println("Generated exception in ServoController::next()");
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
    #ifdef SERVO_DEBUG
    else
    {
        Serial.println(F("Skipping check on frame count since it's runnig in loop mode"));
    }
    #endif
    if (this->intra_animation_steps == 0){
        #ifdef SERVO_DEBUG
        Serial.println(F("Loading next frame"));
        #endif
        if (!this->next_frame()){
            #ifdef DEBUG
            Serial.println(F("Generated error in ServoController::next()"));
            Serial.println(F("Error loading next frame"));
            #endif
            return false;
        }
    }
    #ifdef SERVO_DEBUG
    Serial.println(F("Executing animation step"));
    #endif
    this->execute_animation_step();
    #ifdef SERVO_DEBUG
    Serial.println(F("Successfully executed animation step"));
    #endif
    if(this->intra_animation_steps == 0){
        this->sleep_time_millis = this->millisecods_to_next_frame;
    } else{
        this->sleep_time_millis = 0;
    }
    #ifdef SERVO_DEBUG
    Serial.print(F("Sleep time: "));
    Serial.println(this->sleep_time_millis);
    #endif
    this->update_next_execution_millis();
    return true;
}