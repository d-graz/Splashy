#include "MySD.hpp"

bool init_sd(){
    bool sd_status;
    #ifdef SD_DEBUG
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
    #ifdef SD_DEBUG
        Serial.println(F("SD card initialized successfully"));
    #endif
    return true;

}

File open_file(String file_path, char mode){
    File file;
    #ifdef SD_DEBUG
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
    #ifdef SD_DEBUG
        Serial.println(F("File opened successfully"));
        Serial.println(file_path);
    #endif
    return file;
}

//FIXME:[HIGH] handel limit case when the number is just the tight size
bool read_line(File file, char* buffer, byte buffer_size){
    bool control;
    char c;
    byte i = 0;
    for(i=0; i<buffer_size; i++){
        control = file.read(&c, 1);
        #ifdef SD_DEBUG
            Serial.print(c);
        #endif
        if(!control){
            #ifdef DEBUG
                Serial.println(F("End of file reached when reading line"));
            #endif
            return false;
        }
        if(c == '\n'){
            buffer[i] = '\0';
            return true;
        }
        buffer[i] = c;
    }
    #ifdef DEBUG
        Serial.println(F("String too large for buffer"));
    #endif
    return false;
}