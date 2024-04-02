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
    StateCount
};

typedef State (*StateFunction)(unsigned int state_entering_time);

State idle(unsigned int state_entering_time);
State attract(unsigned int state_entering_time);
State filling(unsigned int state_entering_time);
State petting(unsigned int state_entering_time);


class FiniteStateMachine {
    private:
        State current_state;
        StateFunction state_functions[StateCount];
        unsigned int state_entering_time;
    public:
        FiniteStateMachine();
        void next();
        
};




#endif