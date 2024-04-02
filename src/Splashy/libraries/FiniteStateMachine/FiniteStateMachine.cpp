#include "FiniteStateMachine.hpp"

State idle(unsigned int state_entering_time) {
    #ifdef FINITE_STATE_MACHINE_DEBUG
    Serial.println(F("Currently in IDLE"));
    #endif
    /**
     * If there is a bottle detected
     * - stop the proximity sensor
     * - stop the motor
     * - home the servo
     * - load refill animation for ledmatrix
     * - start the refill process
     * 
    */
    if(ultrasonic_sensor->is_water_bottle_detected()){
        #ifdef FINITE_STATE_MACHINE_DEBUG
        Serial.println(F("Bottle detected"));
        Serial.println(F("Stopping proximity sensor and servo controller"));
        #endif
        proximity_sensor->hibernate();
        servo_controller->hibernate();
        #ifdef FINITE_STATE_MACHINE_DEBUG
        Serial.println(F("Homing the servo"));
        #endif
        servo_controller->home(false);
        #ifdef FINITE_STATE_MACHINE_DEBUG
        Serial.println(F("Loading refill animation"));
        #endif
        handle_error(led_matrix->load_animation(LedMatrixAnimation::Refill), F("Error loading refill animation in IDLE state"));
        //TODO: [CRITICAL] start the refill process
        return State::FILLING;
    }
    /**
     * If no bottle detected but person detected
     * - stop the proximity sensor
     * - home the servo
     * 
    */ 
    else if (proximity_sensor->is_person_detected()){
        proximity_sensor->hibernate();
        servo_controller->home(false);
        //TODO: [CRITICAL] start and handle the petting process
        return State::PETTING;
    }
    return State::IDLE;
}

FiniteStateMachine::FiniteStateMachine() {
    this->current_state = State::IDLE;
    this->state_entering_time = millis();
    state_functions[State::IDLE] = idle;
    state_functions[State::ATTRACT] = attract;
    state_functions[State::FILLING] = filling;
    state_functions[State::PETTING] = petting;
}

void FiniteStateMachine::next() {
    State next_state = this->state_functions[this->current_state](this->state_entering_time);
    if (next_state != this->current_state){
        this->current_state = next_state;
        this->state_entering_time = millis();
    }
}

