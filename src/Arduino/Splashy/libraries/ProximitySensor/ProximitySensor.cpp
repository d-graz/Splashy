#include "ProximitySensor.hpp"

ProximitySensor::ProximitySensor(const char* name): Task(name){
    #ifdef PROXIMITY_SENSOR_DEBUG
    Serial.println(F("Creating ProximitySensor object"));
    #endif
    this->object_detected = false;
    pinMode(PROXIMITY_SENSOR_PIN, INPUT);
    this->status = TaskStatus::HIBERNATED;
}

bool ProximitySensor::next(){
    #ifdef DEBUG
    if(this->status ==  TaskStatus::DEAD or this->status == TaskStatus::WAITING){
        Serial.println(F("Task is dead or waiting"));
        Serial.println("Generated exception in ProximitySensor::next()");
        return false;
    }
    #endif
    this->object_detected = digitalRead(PROXIMITY_SENSOR_PIN);
    if(this->object_detected){
        #ifdef PROXIMITY_SENSOR_DEBUG
        Serial.println(F("Object detected"));
        #endif
        this->sleep_time_millis = SLEEP_AFTER_DETECTION;
    } else {
        #ifdef PROXIMITY_SENSOR_DEBUG
        Serial.println(F("No object detected"));
        #endif
        this->sleep_time_millis = SLEEP_AFTER_NO_DETECTION;
    }
    this->update_next_execution_millis();
    return true;
}

bool ProximitySensor::is_person_detected(){
    return this->object_detected;
}