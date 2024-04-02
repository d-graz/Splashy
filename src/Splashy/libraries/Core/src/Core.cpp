#include "Core.hpp"

void handle_error(bool execution_status, String error_message = "generic expection during execution"){
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