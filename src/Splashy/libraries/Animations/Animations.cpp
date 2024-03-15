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
    char buffer[ANIMATION_LINE_SIZE];
    #ifdef DEBUG
    Serial.println("Advancing to next frame");
    #endif
    if(!this->file.available()){
        #ifdef DEBUG
        Serial.println("Rewinding file");
        #endif
        this->file.seek(0);
    }
    for(int i=0; i< MATRIX_SIZE; i++){
        this->file.read(buffer, ANIMATION_LINE_SIZE);
        short unsigned int items_scanned = sscanf(buffer, "%hhu,%hhu,%hhu  %hhu,%hhu,%hhu  %hhu,%hhu,%hhu  %hhu,%hhu,%hhu  %hhu,%hhu,%hhu  %hhu,%hhu,%hhu  %hhu,%hhu,%hhu  %hhu,%hhu,%hhu", this->matrix[i][0].r, this->matrix[i][0].g, this->matrix[i][0].b, this->matrix[i][1].r, this->matrix[i][1].g, this->matrix[i][1].b, this->matrix[i][2].r, this->matrix[i][2].g, this->matrix[i][2].b, this->matrix[i][3].r, this->matrix[i][3].g, this->matrix[i][3].b, this->matrix[i][4].r, this->matrix[i][4].g, this->matrix[i][4].b, this->matrix[i][5].r, this->matrix[i][5].g, this->matrix[i][5].b, this->matrix[i][6].r, this->matrix[i][6].g, this->matrix[i][6].b, this->matrix[i][7].r, this->matrix[i][7].g, this->matrix[i][7].b);
        if(items_scanned != DATA_PER_LINE){
            #ifdef DEBUG
            Serial.println("Failed to read line");
            #endif
            return false;
        }
    }
    this->file.read(buffer, 2);
    #ifdef DEBUG
    Serial.println("Animation loaded correctly");
    #endif
    return true;
}

pixel_t* Animations::get_matrix(){
    #ifdef DEBUG
    Serial.println("Returning matrix pointer");
    #endif
    return &(this->matrix[0][0]);
}

void Animations::error(){
    pixel_t off_pixel, red_pixel;
    off_pixel.r = 0;
    off_pixel.g = 0;
    off_pixel.b = 0;
    red_pixel.r = 255;
    red_pixel.g = 0;
    red_pixel.b = 0;
    for(int i=0; i< MATRIX_SIZE; i++){
        for(int j=0; j< MATRIX_SIZE; j++){
            if (i>=4 && i<=5){
                this->matrix[i][j] = red_pixel;
            } else {
                this->matrix[i][j] = off_pixel;
            }
        }
    }
}
    