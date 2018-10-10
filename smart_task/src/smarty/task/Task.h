#ifndef __SMARTY_TASK_TASK_H
#define __SMARTY_TASK_TASK_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <vector>

#include "smarty/task/State.h"

namespace smarty 
{
class Task
{
private:
    int ID;
    int type;
    std::string desc;
    std::vector<State> listStates;
    
public:
    Task();
    Task(int id, int type, std::string desc = "");    
    ~Task();
    
    int getID() {return ID;};
    void setID(int value) {ID = value;};

    int getType() {return type;};
    void setType(int value) {type = value;};
    
    std::string getDesc() {return desc;};
    void setDesc(std::string value) {desc = value;};
        
    std::vector<State>& getListStates() {return listStates;}; 
    void addState(State& oState);
    void clearStates();
            
    std::string toString();

};
}

#endif
