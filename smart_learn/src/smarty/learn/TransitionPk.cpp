/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "smarty/learn/TransitionPk.h"

namespace smarty 
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