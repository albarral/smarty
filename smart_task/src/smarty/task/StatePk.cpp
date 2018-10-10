/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "smarty/task/StatePk.h"

namespace smarty 
{
StatePk::StatePk() 
{
    taskID = 0;
    stateID = 0;
}

StatePk::StatePk(int task, int state)
{
    taskID = task;
    stateID = state;
}

std::string StatePk::toString()
{
    return "StatePk: [taskID = " + std::to_string(taskID) + ", stateID = " + std::to_string(stateID) + "]";    
}

}