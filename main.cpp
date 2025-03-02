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

/* Discount Factor */
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
    
    // Populate all possible states with their utilities and possible transitions
    State state1(0, {{STransition::down,  0}, {STransition::right, 0}});
    State state2(0, {{STransition::left,  0}, {STransition::down,  0}, {STransition::right, 50}});
    State state3(0, {});
    State state4(0, {{STransition::up,    0}, {STransition::right, 0}});
    State state5(0, {{STransition::left,  0}, {STransition::up,    0}, {STransition::right, 0}});
    State state6(0, {{STransition::left, 0}, {STransition::up,   100}});

    vector<vector<State>> states = {{state1, state2, state3}, {state4, state5, state6}};

    bool converged = true;
    int count = 10;

    // Application of the Bellman Equation
    for (int i = 0; i < count; i++) {
        cout << "-----------------------\nIteration: " << i+1 << "\n-----------------------" << endl;
        displayData(states);
        converged = true;
        for (int j = 0; j < states.size(); j++) {
            for (int k = 0; k < states[0].size(); k++) {
                vector<double> rewards = {};
                // Calculates the new values that could be obtained for all possible transistions
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

                if(rewards.size() > 0){
                    // Determine the action with greatest reward
                    auto value = *max_element(rewards.begin(), rewards.end());
                    // Converged if the iteration does not change the utility value
                    if(states[j][k].value != value){
                        converged = false;
                    }
                    states[j][k].value = value;
                }
            }
        }

        // Check for convergence of algorithm
        if(converged){
            cout << "\nValue Iteration algorithm converged after " << (i+1) << " iterations" << "\n\n";
            break;
        }

    }
    return 0;
}