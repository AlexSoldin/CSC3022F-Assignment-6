#ifndef TRANS_H
#define TRANS_H

/* Possible Transitions for a Particular State */
enum STransition{
    up,
    down,
    left,
    right
};

class Transition {
    public:
        STransition transition;
        // Each reward is associated with a reward
        double reward;

        Transition(STransition transition, double reward);
};


#endif 