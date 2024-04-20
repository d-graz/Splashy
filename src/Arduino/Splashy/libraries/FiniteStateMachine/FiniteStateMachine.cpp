#include "FiniteStateMachine.hpp"

//TODO: [CONFIG] set all theese parameters
#define ATTRACTION_TIME 30000 ///< The time in milliseconds to spend in the attract state.
#define ATTRACTION_STATE_ACTIVATION_TIME 120000 ///< The time that needs to pass before the penguin enters the attract state from idle state.

#define SADNESS_TIME 300000 ///< The time in milliseconds to show the sad face of the penguin if not being used in idle mode.
#define SADNESS_BACK_TO_IDLE_TIME 25000 ///< The time in milliseconds to show the sad face of the penguin if not being used in idle mode.

#define HAPPY_STATE_ACTIVATION_TIME 10000 ///< The time that needs to pass before the penguin enters the happy state from idle state. 
#define RECHARGE_COUNT_THRESHOLD 10 ///< The number of times the penguin needs to be recharged before entering the happy state.
byte recharge_count = 0; ///< The number of times the penguin has been recharged.

#define PETTING_TIME 60000 ///< The time in milliseconds to spend in the petting state.


State idle(unsigned long int state_entering_time) {
    #ifdef FINITE_STATE_MACHINE_DEBUG
        Serial.println(F("Currently in IDLE"));
    #endif
    if(ultrasonic_sensor->is_water_bottle_detected()){
        #ifdef FINITE_STATE_MACHINE_DEBUG
            Serial.println(F("Bottle detected"));
            Serial.println(F("Transitioning to FILLING"));
        #endif
        return State::FILLING;
    } else if (recharge_count >= RECHARGE_COUNT_THRESHOLD && millis() > state_entering_time + HAPPY_STATE_ACTIVATION_TIME){
        #ifdef FINITE_STATE_MACHINE_DEBUG
            Serial.println(F("People are actually using me!"));
            Serial.println(F("Transitioning to HAPPY"));
        #endif
        return State::HAPPY;
    } else if (proximity_sensor->is_person_detected() && millis() > state_entering_time + ATTRACTION_STATE_ACTIVATION_TIME){
        #ifdef FINITE_STATE_MACHINE_DEBUG
            Serial.println(F("Person detected"));
            Serial.println(F("Transitioning to ATTRACT"));
        #endif
        return State::ATTRACT;
    } else if (touch_sensor->is_active()) {
        #ifdef FINITE_STATE_MACHINE_DEBUG
            Serial.println(F("Petting detected"));
            Serial.println(F("Transitioning to PETTING"));
        #endif
        return State::PETTING;
    } else if(millis() > state_entering_time + SADNESS_TIME){
        #ifdef FINITE_STATE_MACHINE_DEBUG
            Serial.println(F("Nobody loves me"));
        #endif
        return State::SAD;
    }
    return State::IDLE;
}

State attract(unsigned long int state_entering_time){
    #ifdef FINITE_STATE_MACHINE_DEBUG
        Serial.println(F("Currently in ATTRACT"));
    #endif
    if (ultrasonic_sensor->is_water_bottle_detected()){
        #ifdef FINITE_STATE_MACHINE_DEBUG
            Serial.println(F("Bottle detected"));
        #endif
        return State::FILLING;
    } else if (touch_sensor->is_active()) {
        #ifdef FINITE_STATE_MACHINE_DEBUG
            Serial.println(F("Petting detected"));
        #endif
        return State::PETTING;
    } else if (millis() - state_entering_time > ATTRACTION_TIME){
        #ifdef FINITE_STATE_MACHINE_DEBUG
            Serial.println(F("Time to leave ATTRACT"));
        #endif
        return State::IDLE;
    }
    return State::ATTRACT;
}

State filling(unsigned long int state_entering_time){
    #ifdef FINITE_STATE_MACHINE_DEBUG
        Serial.println(F("Currently in FILLING"));
    #endif
    if(!ultrasonic_sensor->is_water_bottle_detected() && pump->is_pump_active()){
        #ifdef FINITE_STATE_MACHINE_DEBUG
            Serial.println(F("Bottle removed while charging"));
        #endif
        pump->hibernate();
        return State::FILLED;
    } else if (!pump->is_pump_active()){
        #ifdef FINITE_STATE_MACHINE_DEBUG
            Serial.println(F("Pump has filled the bottle"));
        #endif
        return State::FILLED;
    }
    return State::FILLING;
}

State filled(unsigned long int state_entering_time){
    #ifdef FINITE_STATE_MACHINE_DEBUG
        Serial.println(F("Currently in FILLED"));
    #endif
    if(!ultrasonic_sensor->is_water_bottle_detected()){
        #ifdef FINITE_STATE_MACHINE_DEBUG
            Serial.println(F("Bottle removed"));
        #endif
        return State::IDLE;
    }
    return State::FILLED;
}

State petting(unsigned long int state_entering_time){
    #ifdef FINITE_STATE_MACHINE_DEBUG
        Serial.println(F("Currently in PETTING"));
    #endif
    if (ultrasonic_sensor->is_water_bottle_detected()){
        #ifdef FINITE_STATE_MACHINE_DEBUG
            Serial.println(F("Bottle detected"));
        #endif
        return State::FILLING;
    } else if (millis() > state_entering_time + PETTING_TIME){
        #ifdef FINITE_STATE_MACHINE_DEBUG
            Serial.println(F("End of pet time"));
        #endif
        return State::IDLE;
    }
    return State::PETTING;
}

State sad(unsigned long int state_entering_time){
    #ifdef FINITE_STATE_MACHINE_DEBUG
        Serial.println(F("Currently in SAD"));
    #endif
    if (ultrasonic_sensor->is_water_bottle_detected()){
        #ifdef FINITE_STATE_MACHINE_DEBUG
            Serial.println(F("Bottle detected"));
        #endif
        return State::FILLING;
    } else if (proximity_sensor->is_person_detected()){
        #ifdef FINITE_STATE_MACHINE_DEBUG
            Serial.println(F("Person detected"));
        #endif
        return State::ATTRACT;
    } else if (millis() >= state_entering_time + SADNESS_BACK_TO_IDLE_TIME){
        #ifdef FINITE_STATE_MACHINE_DEBUG
            Serial.println(F("Time to leave SAD"));
        #endif
        return State::IDLE;
    }
    return State::SAD;
}

State happy(unsigned long int state_entering_time){
    #ifdef FINITE_STATE_MACHINE_DEBUG
        Serial.println(F("Currently in HAPPY"));
    #endif
    if (ultrasonic_sensor->is_water_bottle_detected()){
        #ifdef FINITE_STATE_MACHINE_DEBUG
            Serial.println(F("Bottle detected"));
        #endif
        return State::FILLING;
    } else if ((servo_controller->get_status() == TaskStatus::HIBERNATED) && (led_matrix->get_status() == TaskStatus::HIBERNATED)){
        #ifdef FINITE_STATE_MACHINE_DEBUG
            Serial.println(F("Finished happy animation"));
        #endif
        return State::IDLE;
    }
    return State::HAPPY;
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
 * Activates the touch sensor in order to detect petting
 * stops the servo motor
 * homes the servo motor
 * Loads the idle animation on the led matrix
*/
void to_Idle_state(){
    handle_error(proximity_sensor->activate(), F("Failed to activate proximity sensor"));
    handle_error(touch_sensor->activate(), F("Failed to activate touch sensor"));
    servo_controller->hibernate();
    servo_controller->home(false);
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
 * Stops the proximity sensor, servo controller and touch sensor (frees up cpu cycles)
 * Homes the servo motor
 * Loads the refill animation on the led matrix
 * Activates the pump (inserts it into the sceduler)
 * Start the pump up
*/
void to_Filling_state(){
    proximity_sensor->hibernate();
    servo_controller->hibernate();
    touch_sensor->hibernate();
    servo_controller->home(false);
    handle_error(led_matrix->load_animation(LedMatrixAnimation::Refill), F("Error loading refill animation"));
    handle_error(pump->activate(), F("Error activating pump to start filling process"));
    pump->activate_pump();
}

/**
 * Load the filled animation on the led matrix
 * Increments the recharge count
*/
void to_Filled_state(){
    recharge_count++;
    handle_error(led_matrix->load_animation(LedMatrixAnimation::Filled), F("Error loading filled animation"));
}

/**
 * Hibernates the proximity sensor and touch sensor
 * Homes the servo motor
 * Loads the petting animation on the led matrix
 * Loads the petting animation on the servo motor
*/
void to_Petting_state(){
    proximity_sensor->hibernate();
    touch_sensor->hibernate();
    servo_controller->home(false);
    handle_error(led_matrix->load_animation(LedMatrixAnimation::PettingLed), F("Error loading petting animation"));
    handle_error(servo_controller->load_animation(ServoMotorAnimation::PettingMotor), F("Error loading petting animation"));

}

/**
 * Set the strike back to 0
 * Hibernates the proximity sensor
 * Homes the servo motor (REDUNDANT)
 * Loads the happy animation on the led matrix
 * Loads the happy animation on the servo motor
*/
void to_Happy_state(){
    recharge_count = 0;
    proximity_sensor->hibernate();
    //servo_controller->home(false);
    handle_error(led_matrix->load_animation(LedMatrixAnimation::HappyLed), F("Error loading happy animation"));
    handle_error(servo_controller->load_animation(ServoMotorAnimation::HappyMotor), F("Error loading happy animation"));
}

/**
 * Load the sad animation on the led matrix
 * Set the strike back to 0
*/
void to_Sad_state(){
    handle_error(led_matrix->load_animation(LedMatrixAnimation::Sad), F("Error loading sad animation"));
    recharge_count = 0;
}
    