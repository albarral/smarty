/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "smarty/task/TransitionPk.h"

namespace smart 
{
TransitionPk::TransitionPk() 
{
    transID = 0;
}

TransitionPk::TransitionPk(StatePk& statePk, int transition)
{
    setStatePk(statePk);
    transID = transition;
}

std::string TransitionPk::toString()
{
    return "TransitionPk: [" + statePk.toString() + ", transID = " + std::to_string(transID) + "]";    
}

}