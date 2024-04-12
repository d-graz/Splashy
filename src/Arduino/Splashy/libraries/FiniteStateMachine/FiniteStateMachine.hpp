#ifndef __FINITE_STATE_MACHINE__
#define __FINITE_STATE_MACHINE__

#include "../Config/Global.hpp"
#include "../Core/Core.hpp"

#ifdef DEBUG
#define FINITE_STATE_MACHINE_DEBUG
#endif

enum State {
    IDLE,
    ATTRACT,
    FILLING,
    PETTING,
    FILLED,
    HAPPY,
    SAD,
    StateCount
};

typedef State (*StateFunction)(unsigned long int state_entering_time);

State idle(unsigned long int state_entering_time);
State attract(unsigned long int state_entering_time);
State filling(unsigned long int state_entering_time);
State petting(unsigned long int state_entering_time);
State filled(unsigned long int state_entering_time);
State happy(unsigned long int state_entering_time);
State sad(unsigned long int state_entering_time);

StateFunction _state_functions[StateCount] = {
    idle,
    attract,
    filling,
    petting,
    filled,
    happy,
    sad
};


typedef void (*TransitionFunction)();

void to_Idle_state();
void to_Attract_state();
void to_Filling_state();
void to_Petting_state();
void to_Filled_state();
void to_Happy_state();
void to_Sad_state();

TransitionFunction _transition_functions[StateCount] = {
    to_Idle_state,
    to_Attract_state,
    to_Filling_state,
    to_Petting_state,
    to_Filled_state,
    to_Happy_state,
    to_Sad_state
};



class FiniteStateMachine {
    private:
        State current_state;
        unsigned long int state_entering_time;
    public:
        FiniteStateMachine();
        void next();
        
};




#endif