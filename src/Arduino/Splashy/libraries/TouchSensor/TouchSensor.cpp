#include "TouchSensor.hpp"

TouchSensor::TouchSensor(const char* name): Task(name), sensor(TOUCH_SENSOR_PIN_SEND, TOUCH_SENSOR_PIN_RECIVE) {
    this->touch = false;
    // FIXME: [LOW] autocalibration should be used for production-ready code
    this->sensor.set_CS_AutocaL_Millis(0xFFFFFFFF);
    for (byte i = 0; i < FILTER_SIZE_TS; i++) {
        this->samples[i] = this->sensor.capacitiveSensor(SAMPLES);
    }
}

bool TouchSensor::is_active() {
    return this->touch;
}

bool TouchSensor::next() {
    #ifdef DEBUG
        #ifdef WARN
            if(this->status ==  TaskStatus::DEAD or this->status == TaskStatus::WAITING){
            Serial.println(F("[WARN] : called next() on a dead or waiting task"));
            Serial.println(F("Generated exception in TouchSensor::next()"));
            }
        #endif    
    #endif
    for(byte i = 0; i < FILTER_UPDATE_SIZE_TS; i++){
        this->samples[this->index] = this->sensor.capacitiveSensor(SAMPLES);
        delay(10);
        #ifdef TOUCH_SENSOR_DEBUG
            Serial.print(F("Touch Sensor value: "));
            Serial.println(this->samples[this->index]);
        #endif
        this->index = (this->index + 1) % FILTER_SIZE_TS;
    }
    if(this->get_filtered_value() > THRESHOLD){
        this->touch = true;
    } else {
        this->touch = false;
    }
    this->update_next_execution_millis();
    return true;
}

float TouchSensor::get_filtered_value(){
    float sum = 0;
    for (byte i = 0; i < FILTER_SIZE_TS; i++) {
        sum += this->samples[i];
    }
    return sum / FILTER_SIZE_TS;
}