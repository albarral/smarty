/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "smarty/task/Task.h"

namespace smart 
{
Task::Task() 
{
    ID = 0;
    type = 0;
    desc = "";
}

Task::Task(int id, int type, std::string desc)
{
    this->ID = id;
    this->type = type;
    this->desc = desc;    
}

Task::~Task()
{
    listStates.clear();    
}

void Task::addState(State& oState)
{
    listStates.push_back(oState);
}

void Task::clearStates()
{
    listStates.clear();    
}

std::string Task::toString()
{
    std::string text = "Task: [ID=" + std::to_string(ID) + ", type=" + std::to_string(type) + ", desc=" + desc + "]\n";
    for (State& oState : listStates)
    {
        text += oState.toString() + "\n";
    }                
    return text;
}

}