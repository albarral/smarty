/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "smarty/learn/Transition.h"

namespace smarty 
{
Transition::Transition() 
{
    nextState = 0;
    Q = 0.0;
}

Transition::Transition(TransitionPk& transitionPk, int nextState, float q)
{
    setTransitionPk(transitionPk);
    setNextState(nextState);
    setQ(q);    
}

std::string Transition::toString()
{
    return ("Transition: [" + transitionPk.toString() + ", nextState=" + std::to_string(nextState) + ", Q=" + std::to_string(Q) + "]");
}
}