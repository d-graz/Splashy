#include "ProximitySensor.hpp"

ProximitySensor::ProximitySensor(const char* name): Task(name){
    #ifdef PROXIMITY_SENSOR_DEBUG
        Serial.println(F("Creating ProximitySensor object"));
    #endif
    this->object_detected = false;
    #ifndef PROXIMITY_SENSOR_SIMULATION
        pinMode(PROXIMITY_SENSOR_PIN, INPUT);
    #else
        pinMode(A2, INPUT);
    #endif
    this->status = TaskStatus::HIBERNATED;
    this->sleep_time_millis = SLEEP_TIME;
}

bool ProximitySensor::next(){
    #ifdef DEBUG
        #ifdef WARN
            if(this->status ==  TaskStatus::DEAD or this->status == TaskStatus::WAITING){
                Serial.println(F("[WARN]: Task is dead or waiting"));
                Serial.println("Generated exception in ProximitySensor::next()");
            }
        #endif
    #endif
    #ifndef PROXIMITY_SENSOR_SIMULATION
        this->object_detected = digitalRead(PROXIMITY_SENSOR_PIN);
    #else
        if(analogRead(A2)> 1000){
            this->object_detected = true;
        } else {
            this->object_detected = false;
        }
    #endif
    #ifdef PROXIMITY_SENSOR_DEBUG
        if(this->object_detected){
            Serial.println(F("Object detected"));
        } else {
            Serial.println(F("No object detected"));
        }
    #endif
    this->update_next_execution_millis();
    return true;
}

bool ProximitySensor::is_person_detected(){
    return this->object_detected;
}