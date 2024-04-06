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
    StateCount
};

typedef State (*StateFunction)(unsigned int state_entering_time);

State idle(unsigned int state_entering_time);
State attract(unsigned int state_entering_time);
State filling(unsigned int state_entering_time);
State petting(unsigned int state_entering_time);
State filled(unsigned int state_entering_time);

StateFunction _state_functions[StateCount] = {
    idle,
    attract,
    filling,
    petting,
    filled
};


typedef void (*TransitionFunction)();

void to_Idle_state();
void to_Attract_state();
void to_Filling_state();
void to_Petting_state();
void to_Filled_state();

TransitionFunction _transition_functions[StateCount] = {
    to_Idle_state,
    to_Attract_state,
    to_Filling_state,
    to_Petting_state,
    to_Filled_state
};



class FiniteStateMachine {
    private:
        State current_state;
        unsigned int state_entering_time;
    public:
        FiniteStateMachine();
        void next();
        
};




#endif