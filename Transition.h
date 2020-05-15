#ifndef TRANS_H
#define TRANS_H


enum STransition{
    up,
    down,
    left,
    right
};

class Transition {
    public:
        STransition transition;
        double reward;

        Transition(STransition transition, double reward);
};


#endif 