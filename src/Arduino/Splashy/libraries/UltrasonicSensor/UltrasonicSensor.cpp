#include "UltrasonicSensor.hpp"

UltrasonicSensor::UltrasonicSensor(const char* name): sonar(ULTRASONIC_SENSOR_TRIGGER_PIN, ULTRASONIC_SENSOR_ECHO_PIN, MAX_DISTANCE), Task(name){
    #ifdef ULTRASONIC_SENSOR_DEBUG
        Serial.println(F("Creating UltrasonicSensor object"));
    #endif
    this->object_detected = false;
    for(byte i = 0; i < FILTER_SIZE; i++){
        this->filter[i] = this->read_distance();
    }
    #ifdef ULTRASONIC_SENSOR_DEBUG
        for(byte i = 0; i < FILTER_SIZE; i++){
            Serial.print(F("Filter["));
            Serial.print(i);
            Serial.print(F("] = "));
            Serial.println(this->filter[i]);
        }
    #endif
}

float UltrasonicSensor::get_distance(){
    float sum = 0;
    for (byte i = 0; i < FILTER_SIZE; i++) {
        sum += filter[i];
    }
    return (sum / (float) FILTER_SIZE);
}

bool UltrasonicSensor::next(){
    #ifdef DEBUG
        #ifdef WARN
            if(this->status ==  TaskStatus::DEAD or this->status == TaskStatus::WAITING){
                Serial.println(F("Task is dead or waiting"));
                Serial.println("Generated exception in UltrasonicSensor::next()");
            }
        #endif
    #endif
    for(byte i = 0; i < FILTER_UPDATE_SIZE; i++){
        this->filter[this->filter_index] = this->read_distance();
        this->filter_index = (this->filter_index + 1) % FILTER_SIZE;
    }
    #ifdef ULTRASONIC_SENSOR_DEBUG
        for(byte i = 0; i < FILTER_SIZE; i++){
            Serial.print(F("Filter["));
            Serial.print(i);
            Serial.print(F("] = "));
            Serial.println(this->filter[i]);
        }
        Serial.print(F("Distance: "));
        Serial.println(this->get_distance());
    #endif
    if(this->get_distance() < TRIGGERING_DISTANCE){
        #ifdef ULTRASONIC_SENSOR_DEBUG
            Serial.println(F("Object detected"));
        #endif
            this->object_detected = true;
    } else {
        #ifdef ULTRASONIC_SENSOR_DEBUG
            Serial.println(F("No object detected"));
        #endif
        this->object_detected = false;
    }
    this->update_next_execution_millis();
    return true;
}

bool UltrasonicSensor::is_water_bottle_detected(){
    return this->object_detected;
}

float UltrasonicSensor::read_distance(){
    unsigned long distance = this->sonar.ping_cm();
    if(distance == 0){
        return static_cast<float>(MAX_DISTANCE);
    } else {
        return static_cast<float>(distance);
    }
}