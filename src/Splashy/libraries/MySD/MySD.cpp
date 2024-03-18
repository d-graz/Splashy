#include "MySD.hpp"

bool init_sd(){
    bool sd_status;
    #ifdef DEBUG
    Serial.println(F("Initializing SD card"));
    #endif
    #ifdef SD_CSPIN
    sd_status = SD.begin(SD_CSPIN);
    #else
    sd_status = SD.begin();
    #endif
    if(!sd_status){
        #ifdef DEBUG
        Serial.println(F("SD card failed to initialize"));
        #endif
        return false;
    }
    #ifdef DEBUG
        Serial.println(F("SD card initialized successfully"));
    #endif
    return true;

}

File open_file(String file_path, char mode){
    File file;
    #ifdef DEBUG
    Serial.print(F("Opening file: "));
    Serial.println(file_path);
    #endif
    if (!SD.exists(file_path)){
        #ifdef DEBUG
        Serial.print(F("File does not exist: "));
        Serial.println(file_path);
        #endif
        return file;
    }
    if (mode == 'r'){
        file = SD.open(file_path, FILE_READ);
    } else if (mode == 'w'){
        file = SD.open(file_path, FILE_WRITE);
    } else {
        #ifdef DEBUG
        Serial.print(F("Invalid mode when tryng to open file: "));
        Serial.println(file_path);
        #endif
        return file;
    }
    #ifdef DEBUG
    Serial.println(F("File opened successfully"));
    Serial.println(file_path);
    #endif
    return file;
}