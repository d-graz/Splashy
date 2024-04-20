#include "TouchSensor.hpp"

TouchSensor::TouchSensor(const char* name): Task(name), sensor(TOUCH_SENSOR_PIN_SEND, TOUCH_SENSOR_PIN_RECIVE) {
    this->touch = false;
    // FIXME: [LOW] autocalibration should be used for production-ready code
    this->sensor.set_CS_AutocaL_Millis(0xFFFFFFFF);
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
    long sensor_value = this->sensor.capacitiveSensor(SAMPLES);
    #ifdef TOUCH_SENSOR_DEBUG
        Serial.print(F("Sensor value: "));
        Serial.println(sensor_value);
    #endif
    if(sensor_value > THRESHOLD){
        this->touch = true;
    } else {
        this->touch = false;
    }
    this->update_next_execution_millis();
    return true;
}