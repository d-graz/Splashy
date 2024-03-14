/**
 * \file Animations.cpp
 * \brief Source code file for the Animations class.
 */

#include "Animations.hpp"

Animations::Animations(){
    #ifdef DEBUG
    Serial.println("Init animation class");
    #endif
    this->file = File();
    pixel_t off_pixel;
    off_pixel.r = 0;
    off_pixel.g = 0;
    off_pixel.b = 0;
    for(int i=0; i< MATRIX_SIZE; i++){
        for(int j=0; j< MATRIX_SIZE; j++){
            this->matrix[i][j] = off_pixel;
        }
    }
    #ifdef DEBUG
    Serial.println("Animation class created");
    #endif
}

bool Animations::open_animation(String file_path){
    bool sd_status;
    #ifdef DEBUG
    Serial.println("Opening animation");
    #endif
    #ifdef CSPIN
    sd_status = SD.begin(CSPIN);
    #else
    sd_status = SD.begin();
    #endif
    if(!sd_status){
        #ifdef DEBUG
        Serial.println("SD card failed to initialize");
        #endif
        return false;
    }
    if (SD.exists(file_path)){
        this->file = SD.open(file_path, FILE_READ);
        if(!this->file){
            #ifdef DEBUG
            Serial.println("Failed to open file");
            #endif
            return false;
        }
        #ifdef DEBUG
        Serial.println("File correclty opened");
        #endif
        return true;
    } else {
        #ifdef DEBUG
        Serial.println("File does not exist");
        #endif
        return false;
    }

}

bool Animations::next(){
    #ifdef DEBUG
    Serial.println("Advancing to next frame");
    #endif
    if(!this->file.available()){
        #ifdef DEBUG
        Serial.println("Rewinding file");
        #endif
        this->file.seek(0);
    }
    
}