#ifndef __SMART_TASK_STATE_H
#define __SMART_TASK_STATE_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <vector>

#include "smarty/task/StatePk.h"
#include "smarty/task/Transition.h"

namespace smart 
{
class State
{
protected:
    StatePk statePk;
    float reward;
    std::vector<Transition> listTransitions;
    
public:
    State();
    State(StatePk& statePk, float reward = 0.0);
    ~State();

    StatePk& getStatePk() {return statePk;};
    void setStatePk(StatePk& statePk) {this->statePk = statePk;};

    float getReward() {return reward;};
    void setReward(float value) {reward = value;};

    std::vector<Transition>& getListTransitions() {return listTransitions;};
    void addTransition(Transition& oTransition);      
    void clearTransitions();

    std::string toString();   
};
}

#endif
