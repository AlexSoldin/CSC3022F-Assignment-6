#include <vector>
#include <ostream>
#include <utility>

#include "State.h"

State::State(double value, std::vector<Transition> transitions) : value(value), transitions(std::move(transitions)) {}

std::ostream &operator<<(std::ostream &os, const State &state) {
    os << state.value;
    return os;
}