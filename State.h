#ifndef STATE_H
#define STATE_H

#include "Transition.h"

/* Each State holds a utility value and possible Tranistion objects */
class State {
public:
    double value;
    std::vector<Transition> transitions;

    State(double value, std::vector<Transition> transitions);

    friend std::ostream &operator<<(std::ostream &os, const State &state);
};


#endif 