#ifndef __SMARTY_TASK_TRANSITION_H
#define __SMARTY_TASK_TRANSITION_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

#include "smarty/task/TransitionPk.h"

namespace smarty 
{
class Transition
{
protected:
    TransitionPk transitionPk;
    int nextState;
    float Q;
  
public:
    Transition();
    Transition(TransitionPk& transitionPk, int nextState, float q = 0.0);
        
    TransitionPk& getTransitionPk() {return transitionPk;};
    void setTransitionPk(TransitionPk& transitionPk) {this->transitionPk = transitionPk;};
        
    int getNextState() {return nextState;};
    void setNextState(int value) {nextState = value;};
    
    float getQ() {return Q;};
    void setQ(float value) {Q = value;};
    
    std::string toString();
};
}

#endif
