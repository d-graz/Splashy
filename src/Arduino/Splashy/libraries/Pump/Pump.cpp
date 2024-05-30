#include "Pump.hpp"

Pump::Pump(const char* name): Task(name) {
    #ifdef PUMP_DEBUG
        Serial.println(F("Creating pump object"));
    #endif
    this->water_dispensed = 0.0;
    this->target_water_dispensed = 0.0;
    this->pump_active = false;
    pinMode(FLOW_SENSOR_PIN, INPUT_PULLUP);
    pinMode(PUMP_PIN, OUTPUT);
    pinMode(POTENTIOMETER_PIN, INPUT);
}

void Pump::get_user_water_quantity(){
    #ifdef PUMP_DEBUG
        Serial.println(F("Getting user water quantity"));
    #endif
    short unsigned int potentiometer_value = analogRead(POTENTIOMETER_PIN);
    this->target_water_dispensed = map_float((float) potentiometer_value, 0, 1023, MINUMUM_WATER_DISPENSED, MAXIMUM_WATER_DISPENSED);
    #ifdef PUMP_DEBUG
        Serial.print(F("Target water dispensed: "));
        Serial.println(this->target_water_dispensed);
    #endif
}

void Pump::hibernate(){
    digitalWrite(PUMP_PIN, LOW);
    delay(100);
    this->pump_active = false;
    Serial.println(this->water_dispensed);
    Serial.flush();
    #ifdef PUMP_DEBUG
        Serial.println(F("Hibernating pump"));
    #endif
    #ifndef PUMP_SIMULATION
        detachInterrupt(digitalPinToInterrupt(FLOW_SENSOR_PIN));
    #endif
    this->status = TaskStatus::HIBERNATED;
}

bool Pump::activate(){
    if(this->status == TaskStatus::HIBERNATED){
        #ifdef PUMP_DEBUG
            Serial.println(F("Activating pump task"));
        #endif
        #ifndef PUMP_SIMULATION
            attachInterrupt(digitalPinToInterrupt(FLOW_SENSOR_PIN), []{ _pulse_count++; }, RISING);
        #endif
        this->status = TaskStatus::WAITING;
        return true;
    }
    #ifdef DEBUG
        Serial.println(F("Called activate on a non-hibernated pump"));
    #endif
    return false;
}

void Pump::activate_pump(){
    #ifdef PUMP_DEBUG
        Serial.println(F("Activating pump"));
    #endif
    this->water_dispensed = 0.0;
    this->get_user_water_quantity(); 
    noInterrupts();
    _pulse_count = 0;
    interrupts();
    this->pump_active = true;
    digitalWrite(PUMP_PIN, HIGH);
}

bool Pump::next(){
    float quantity_dispensed;
    #ifdef DEBUG
    if(this->status ==  TaskStatus::DEAD or this->status == TaskStatus::WAITING){
        Serial.println(F("Task is dead or waiting"));
        Serial.println("Generated exception in LedMatrix::next()");
        return false;
    }
    #endif
    if(!this->pump_active){
        #ifdef PUMP_DEBUG
        Serial.println(F("Pump is not active, nothing to do"));
        #endif
        return true;
    }
    noInterrupts();
    #ifdef PUMP_SIMULATION
        _pulse_count = 1;
    #endif
    quantity_dispensed = (float) _pulse_count * FLOW_SENSOR_CONSTANT;
    _pulse_count = 0;
    interrupts();
    this->water_dispensed += quantity_dispensed;
    #ifdef PUMP_DEBUG
        Serial.print(F("pulse count in this period: "));
        Serial.println(_pulse_count);
        Serial.print(F("Water dispensed: "));
        Serial.println(this->water_dispensed);
    #endif
    this->get_user_water_quantity(); //TODO: [MEDIUM] see if this is really necessary
    if(this->water_dispensed >= this->target_water_dispensed){
        #ifdef PUMP_DEBUG
            Serial.println(F("Target water dispensed reached"));
        #endif
        this->hibernate();
    }
    return true;
}

bool Pump::is_pump_active(){
    return this->pump_active;
}