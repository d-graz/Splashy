/**
 * \file LedMatrix.cpp
 * \brief Source code file for the LedMatrix class.
 * \version 2.1
 */

#include "LedMatrix.hpp"

LedMatrix::LedMatrix(): Task(), lc(LED_MATRIX_DATA_PIN, LED_MATRIX_CLK_PIN, LED_MATRIX_CS_PIN, LED_MATRIX_DEVICES_COUNT){
    #ifdef LEDMATRIX_DEBUG
    Serial.println(F("Init LedMatrix class"));
    #endif
    this->file=File();
    for(byte i = 0; i < LED_MATRIX_DEVICES_COUNT; i++){
        this->lc.shutdown(i, false);
        this->lc.clearDisplay(i);
        this->lc.setIntensity(i, DEFAULT_BRIGHTNESS);
    }
    this->frame_count = 0;
    this->current_frame = 0;
}

bool LedMatrix::load_animation(String file_path, byte frame_count){
    this->file.close();
    this->frame_count = frame_count;
    this->current_frame = 0;
    this->file = open_file(file_path, 'r');
    if(!this->file){
        #ifdef DEBUG
        Serial.println(F("Generated error in LedMatrix::load_animation()"));
        Serial.print(F("Error opening file : "));
        Serial.println(file_path);
        #endif
        return false;
    }
    this->status = TaskStatus::READY;
    return true;
}

bool LedMatrix::next_frame(){
    #ifdef LEDMATRIX_DEBUG
    Serial.println(F("Advancing to the next frame"));
    #endif
    if(!this->file.available()){
        this->file.seek(0);
    }
    char string[ANIMATION_LINE_LENGTH];
    bool control;
    for(byte i = 0; i < MATRIX_SIZE; i++){
        control = this->file.read(string, ANIMATION_LINE_LENGTH);
        if(!control){
            #ifdef DEBUG
            Serial.println(F("Generated error in LedMatrix::next_frame()"));
            Serial.println(F("Bad formatting for file"));
            #endif
            return false;
        }
        string[ANIMATION_LINE_LENGTH - 1] = '\0';
        #ifdef LEDMATRIX_DEBUG
        for(byte j = 0; j < ANIMATION_LINE_LENGTH-1; j++){
            Serial.print(string[j]);
        }
        Serial.println();
        #endif
        this->animation[i] = strtol(string + 2, NULL, 2);
        #ifdef LEDMATRIX_DEBUG
        Serial.println(this->animation[i], BIN);
        #endif
    }
    control = read_line(this->file, string, ANIMATION_LINE_LENGTH);
    if (!control){
        #ifdef DEBUG
        Serial.println(F("Generated error in LedMatrix::next_frame()"));
        Serial.println(F("Bad formatting file"));
        #endif
        return false;
    }
    this->sleep_time_millis = strtol(string, NULL, 10);
    #ifdef LEDMATRIX_DEBUG
    Serial.print(F("Sleep time: "));
    Serial.println(this->sleep_time_millis);
    #endif
    return true;
}

void LedMatrix::show_frame(){
    #ifdef LEDMATRIX_DEBUG
    Serial.println(F("Displaing frame"));
    #endif
    for (byte row = 0; row < MATRIX_SIZE; row++) {
        for(byte display = 0; display < LED_MATRIX_DEVICES_COUNT; display++){
            this->lc.setRow(display, row, this->animation[row]);
        }
    }
}

void LedMatrix::show_error(){
    for (byte row = 0; row < MATRIX_SIZE; row++) {
        for(byte display = 0; display < LED_MATRIX_DEVICES_COUNT; display++){
            this->lc.setRow(display, row, this->error_animation[row]);
        }
    }
}

bool LedMatrix::next(){
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
    if(!this->next_frame()){
        #ifdef DEBUG
        Serial.println(F("Error loading next frame of LedMatrix"));
        #endif
        return false;
    }
    this->show_frame();
    this->update_next_execution_millis();
    return true;
}