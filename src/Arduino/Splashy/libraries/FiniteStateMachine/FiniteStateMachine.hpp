/**
 * @file FiniteStateMachine.hpp
 * @brief Header file for the FiniteStateMachine class.
 * @version 1.1
*/
#ifndef __FINITE_STATE_MACHINE__
#define __FINITE_STATE_MACHINE__

#include "../Config/Global.hpp"
#include "../Core/Core.hpp"

#ifdef DEBUG
#define FINITE_STATE_MACHINE_DEBUG
#endif

/**
 * @enum State
 * @brief Enumeration of possible states for the finite state machine.
 */
enum State {
    IDLE,   ///< Idle state.
    ATTRACT, ///< Attract state.
    FILLING, ///< Filling state.
    PETTING, ///< Petting state.
    FILLED,  ///< Filled state.
    HAPPY,   ///< Happy state.
    SAD,     ///< Sad state.
    PRE_FILLING, ///< Pre-filling state.
    StateCount ///< Counter of states.
};

/**
 * @typedef StateFunction
 * @brief Definition of the state function type.
 * 
 * A state function is a function that takes the time of entering the state as an argument and returns the next state.
 */
typedef State (*StateFunction)(unsigned long int state_entering_time);

// State function declarations
State idle(unsigned long int state_entering_time);
State attract(unsigned long int state_entering_time);
State filling(unsigned long int state_entering_time);
State petting(unsigned long int state_entering_time);
State filled(unsigned long int state_entering_time);
State happy(unsigned long int state_entering_time);
State sad(unsigned long int state_entering_time);
State pre_filling(unsigned long int state_entering_time);

/**
 * @var _state_functions
 * @brief Array of state functions.
 * 
 * This array maps each state to its corresponding state function.
 */
StateFunction _state_functions[StateCount] = {
    idle,
    attract,
    filling,
    petting,
    filled,
    happy,
    sad,
    pre_filling
};

/**
 * @typedef TransitionFunction
 * @brief Definition of the transition function type.
 * 
 * A transition function is a function that performs the necessary actions for transitioning to a specific state.
 */
typedef void (*TransitionFunction)();

// Transition function declarations
void to_Idle_state();
void to_Attract_state();
void to_Filling_state();
void to_Petting_state();
void to_Filled_state();
void to_Happy_state();
void to_Sad_state();
void to_Pre_Filling_state();

/**
 * @var _transition_functions
 * @brief Array of transition functions.
 * 
 * This array maps each state to its corresponding transition function.
 */
TransitionFunction _transition_functions[StateCount] = {
    to_Idle_state,
    to_Attract_state,
    to_Filling_state,
    to_Petting_state,
    to_Filled_state,
    to_Happy_state,
    to_Sad_state,
    to_Pre_Filling_state
};

/**
 * @class FiniteStateMachine
 * @brief This class represents a finite state machine.
 * 
 * The FiniteStateMachine class provides methods for transitioning between states based on the current state and the state functions.
 */
class FiniteStateMachine {
    private:
        State current_state; ///< The current state.
        unsigned long int state_entering_time; ///< The time of entering the current state.

    public:
        /**
         * @brief Construct a new FiniteStateMachine object.
         * 
         * This constructor creates a new FiniteStateMachine object and initializes the current state to IDLE.
         */
        FiniteStateMachine();

        /**
         * @brief Perform the next step in the state machine.
         * 
         * This method should be called periodically to perform the next step in the state machine. It uses the current state and the state functions to determine the next state, and then uses the transition functions to transition to the next state.
         */
        void next();
};

#endif