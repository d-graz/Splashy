#include "Core.hpp"

void handle_error(bool execution_status, String error_message){
    if(execution_status){
        return;
    }
    #ifdef DEBUG
    Serial.print(F("ERROR : "));
    Serial.println(error_message);
    #endif
    led_matrix->show_error();
    while(true){
        delay(1000);
    }
}

float map_float(float x, float in_min, float in_max, float out_min, float out_max){
    return ((((x - in_min) / (in_max - in_min)) * (out_max - out_min))  + out_min);
}