#ifndef __SMARTY_TASK_LEARN_H
#define __SMARTY_TASK_LEARN_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "smarty/task/State.h"

namespace smarty
{
class Learn
{
private:   
    float gamma;
    
public:
    Learn();
    
    float getGamma() {return gamma;};
    void setGamma(float value) {gamma = value;};

    // compute the Q value of a transition to a given state
    float computeQ(State& oState2);
   
private:    
    // gets maximum Q value of all transitions from the given state
    float maxQFromState(State& oState1);
};

}

#endif
