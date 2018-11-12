/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "smarty/task/Learn.h"
#include "smarty/task/Transition.h"

namespace smart
{  
Learn::Learn()
{
    gamma = 0;   
}

// Q(state2) = reward(state2) + gamma * max [Q(transitions from state2)]
float Learn::computeQ(State& oState2)
{
    return oState2.getReward() + gamma * maxQFromState(oState2);
}

    
// gets max Q value of all transitions from the given state
float Learn::maxQFromState(State& oState1)
{
    float maxQ = 0.0;    
    for (Transition& oTransition : oState1.getListTransitions())
    {
        if (oTransition.getQ() > maxQ)
            maxQ = oTransition.getQ();            
    }        
    return maxQ;
}

}