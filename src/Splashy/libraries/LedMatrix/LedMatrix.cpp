/**
 * \file LedMatrix.cpp
 * \brief Source code file for the LedMatrix class.
 */

#include "LedMatrix.hpp"

LedMatrix::LedMatrix(): lc(LED_MATRIX_DATA_PIN, LED_MATRIX_CLK_PIN, LED_MATRIX_CS_PIN, LED_MATRIX_DEVICES_COUNT){
    #ifdef DEBUG
    Serial.println(F("Init LedMatrix class"));
    #endif
    this->file=File();
    for(byte i = 0; i < LED_MATRIX_DEVICES_COUNT; i++){
        this->lc.shutdown(i, false);
        this->lc.clearDisplay(i);
        this->lc.setIntensity(i, DEFAULT_BRIGHTNESS);
    }
}

bool LedMatrix::load_animation(String file_path){
    this->file = open_file(file_path, 'r');
    if(!this->file){
        #ifdef DEBUG
        Serial.print(F("Error opening file : "));
        Serial.println(file_path);
        #endif
        return false;
    }
    return true;
}

bool LedMatrix::next_frame(){
    #ifdef DEBUG
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
            Serial.println(F("Bad formatting for file"));
            #endif
            return false;
        }
        string[ANIMATION_LINE_LENGTH - 1] = '\0';
        #ifdef DEBUG
        for(byte j = 0; j < ANIMATION_LINE_LENGTH-1; j++){
            Serial.print(string[j]);
        }
        Serial.println();
        #endif
        this->animation[i] = strtol(string + 2, NULL, 2);
        #ifdef DEBUG
        Serial.println(this->animation[i], BIN);
        #endif
    }
    this->file.read(string,1);
    return true;
}

void LedMatrix::show_frame(){
    #ifdef DEBUG
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