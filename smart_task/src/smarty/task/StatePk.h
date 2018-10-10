#ifndef __SMARTY_TASK_STATEPK_H
#define __SMARTY_TASK_STATEPK_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

namespace smarty 
{
class StatePk
{
private:
    int taskID;
    int stateID;
    
public:
    StatePk();
    StatePk(int task, int state);
    
    int getTaskID() {return taskID;};
    void setTaskID(int value) {taskID = value;};

    int getStateID() {return stateID;};
    void setStateID(int value) {stateID = value;};
    
    std::string toString();
};
}

#endif
