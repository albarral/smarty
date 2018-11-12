/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "smarty/task/State.h"

namespace smart 
{
State::State() 
{
    reward = 0.0;
}

State::State(StatePk& statePk, float reward)
{
    setStatePk(statePk);
    setReward(reward);    
}

State::~State()
{
    listTransitions.clear();    
}

void State::addTransition(Transition& oTransition)
{
    // transition ID is assigned automatically
    oTransition.getTransitionPk().setTransitionID(listTransitions.size());
    listTransitions.push_back(oTransition);
}

void State::clearTransitions()
{
    listTransitions.clear();        
}

std::string State::toString()
{
    std::string text = "State: [" + statePk.toString() + ", reward=" + std::to_string(reward) + "]\n";
    for (Transition& oTransition : listTransitions)
    {
        text += oTransition.toString() + "\n";
    }        
        
    return text;
}

}