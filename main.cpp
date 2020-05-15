#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ios>
#include <cmath>
#include <algorithm> 
#include <iterator>

#include "Transition.h"
#include "State.h"

using namespace std;

double discount =  0.8;

/* Displays Grid of Data */
void displayData(vector<vector<State>> toDisplay){
    for (int i = 0; i < toDisplay.size(); i++) {
        for (int j = 0; j < toDisplay[0].size(); j++) {
            cout << toDisplay[i][j] << "\t";
        }
        cout << "\n";
    }
}

/* Main Method */
int main(){
     
    State s1(0, {{STransition::down,  0}, {STransition::right, 0}});
    State s2(0, {{STransition::left,  0}, {STransition::down,  0}, {STransition::right, 50}});
    State s3(0, {});
    State s4(0, {{STransition::up,    0}, {STransition::right, 0}});
    State s5(0, {{STransition::left,  0}, {STransition::up,    0}, {STransition::right, 0}});
    State s6(0, {{STransition::left, 0}, {STransition::up,   100}});

    vector<vector<State>> states = {{s1, s2, s3}, {s4, s5, s6}};

    bool converged = true;
    int count = 10;

    for (int i = 0; i < count; i++) {
        cout << "-----------------------\nIteration: " << i+1 << "\n-----------------------" << endl;
        displayData(states);
        converged = true;
        for (int j = 0; j < states.size(); j++) {
            for (int k = 0; k < states[0].size(); k++) {
                vector<double> rewards = {};
                for (Transition t : states[j][k].transitions) {
                    int nextK = k;
                    int nextJ = j;
                    
                    if (t.transition == STransition::up){
                        nextJ--;
                    }
                    else if (t.transition == STransition::left){
                        nextK--;
                    }
                    else if (t.transition == STransition::right){
                        nextK++;
                    }
                    else if (t.transition == STransition::down){
                        nextJ++;
                    }

                    rewards.push_back(t.reward + discount * states[nextJ][nextK].value);
                }
                if(!rewards.empty() && rewards.size() > 0){
                    auto value = *max_element(rewards.begin(), rewards.end());
                    if(states[j][k].value != value){
                        converged = false;
                    }
                    states[j][k].value = value;
                }

            }
        }
        if(converged){
            cout << "\nValue Iteration algorithm converged after " << (i+1) << " iterations" << "\n\n";
            break;
        }
    }
    return 0;
}