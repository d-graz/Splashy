#include "FiniteStateMachine.hpp"

#define ATTRACTION_TIME 30000 ///< The time in milliseconds to spend in the attract state.
#define SADNESS_TIME 300000 ///< The time in milliseconds to show the sad face of the penguin if not being used in idle mode.

/**
 * If the ultrasonic sensor detects a water bottle, the state machine transitions to the Filling state.
 * Else If the proximity sensor detects a person, the state machine transitions to the Attract state.
 * Otherwise, the state machine remains in the Idle state.
*/
State idle(unsigned int state_entering_time) {
    #ifdef FINITE_STATE_MACHINE_DEBUG
    Serial.println(F("Currently in IDLE"));
    #endif
    if(ultrasonic_sensor->is_water_bottle_detected()){
        #ifdef FINITE_STATE_MACHINE_DEBUG
        Serial.println(F("Bottle detected"));
        Serial.println(F("Transitioning to FILLING"));
        #endif
        return State::FILLING;
    } else if (proximity_sensor->is_person_detected()){
        #ifdef FINITE_STATE_MACHINE_DEBUG
        Serial.println(F("Person detected"));
        Serial.println(F("Transitioning to ATTRACT"));
        #endif
        return State::ATTRACT;
    } else if(millis() > state_entering_time + SADNESS_TIME){
        #ifdef FINITE_STATE_MACHINE_DEBUG
        Serial.println(F("Time to show sad face"));
        #endif
        led_matrix->load_animation(LedMatrixAnimation::Sad);
    }
    //TODO: [CRITICAL] Add the condition for petting state
    return State::IDLE;
}

State attract(unsigned int state_entering_time){
    #ifdef FINITE_STATE_MACHINE_DEBUG
    Serial.println(F("Currently in ATTRACT"));
    #endif
    if(millis() - state_entering_time > ATTRACTION_TIME){
        #ifdef FINITE_STATE_MACHINE_DEBUG
        Serial.println(F("Time to leave ATTRACT"));
        #endif
        to_Idle_state();
        return State::IDLE;
    }
    if (ultrasonic_sensor->is_water_bottle_detected()){
        to_Filling_state();
        return State::FILLING;
    }
    //TODO: [CRITICAL] Add the condition for petting state (evaluate if this is necessary)
    return State::ATTRACT;
}

State filling(unsigned int state_entering_time){
    if(!ultrasonic_sensor->is_water_bottle_detected() && pump->is_pump_active()){
        pump->hibernate();
        to_Idle_state();
        return State::IDLE;
    } else if (ultrasonic_sensor->is_water_bottle_detected() && !pump->is_pump_active()){
        to_Filled_state();
        return State::FILLED;
    }
    return State::FILLING;
}

State filled(unsigned int state_entering_time){
    return State::FILLED;
}

State petting(unsigned int state_entering_time){
    return State::PETTING;
}

FiniteStateMachine::FiniteStateMachine() {
    this->current_state = State::IDLE;
    this->state_entering_time = millis();
}

void FiniteStateMachine::next() {
    State next_state = _state_functions[this->current_state](this->state_entering_time);
    if (next_state != this->current_state){
        this->current_state = next_state;
        this->state_entering_time = millis();
        _transition_functions[this->current_state]();
    }
}

/**
 * Activates the proximity sensor in order to detect persons
 * Loads the idle animation on the led matrix
*/
void to_Idle_state(){
    handle_error(proximity_sensor->activate(), F("Failed to activate proximity sensor"));
    handle_error(led_matrix->load_animation(LedMatrixAnimation::Idle), F("Failed to load idle animation"));
}

/**
 * Hibernates the proximity sensor as it's not required in this state an frees up cpu cycles
 * Homes the servo motor
 * Loads the attract animation on the led matrix
 * Loads the hi animation on the servo motor
*/
void to_Attract_state(){
    proximity_sensor->hibernate();
    servo_controller->home(false);
    handle_error(led_matrix->load_animation(LedMatrixAnimation::Attract), F("Error loading Attract animation"));
    handle_error(servo_controller->load_animation(ServoMotorAnimation::Hi), F("Error loading Hi animation"));
}

/**
 * Stops the proximity sensor and servo controller (frees up cpu cycles)
 * Homes the servo motor
 * Loads the refill animation on the led matrix
 * Activates the pump (inserts it into the sceduler)
 * Start the pump up
*/
void to_Filling_state(){
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
    handle_error(pump->activate(), F("Error activating pump in IDLE state"));
    pump->activate_pump();
}

void to_Petting_state(){};

void to_Filled_state(){
    #ifdef FINITE_STATE_MACHINE_DEBUG
    Serial.println(F("Bottle filled"));
    #endif
    //TODO: load filled animation face expression and maybe some servo motor animation
}