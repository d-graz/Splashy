#include<MyServo.hpp>

ServoMotor::ServoMotor(short unsigned int pin, short unsigned int initial_position){
    #ifdef DEBUG
    Serial.println(F("Init ServoMotor class"));
    #endif
    this->servo.attach(pin);
    this->initial_position = initial_position;
}

bool ServoMotor::attached(){
    return this->servo.attached();
}

void ServoMotor::write(short unsigned int angle){
    #ifdef DEBUG
    Serial.println(F("Writing to servo"));
    #endif
    this->servo.write(angle);
}

short unsigned int ServoMotor::read(){
    #ifdef DEBUG
    Serial.println(F("Reading from servo"));
    #endif
    return this->servo.read();
}

