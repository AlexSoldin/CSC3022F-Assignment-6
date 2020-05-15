#ifndef STATE_H
#define STATE_H

#include <vector>
#include <ostream>
#include "Transition.h"

class State {
public:
    double value;
    std::vector<Transition> transitions;

    State(double value, std::vector<Transition> transitions);

    friend std::ostream &operator<<(std::ostream &os, const State &state);
};


#endif 