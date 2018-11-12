#ifndef __SMART_TASK_TRANSITIONPK_H
#define __SMART_TASK_TRANSITIONPK_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

#include "smarty/task/StatePk.h"

namespace smart 
{
class TransitionPk
{
private:
    StatePk statePk;
    int transID;
    
public:
    TransitionPk();
    TransitionPk(StatePk& statePk, int transition);
    
    StatePk& getStatePk() {return statePk;};
    void setStatePk(StatePk& statePk) {this->statePk = statePk;};

    int getTransitionID() {return transID;};
    void setTransitionID(int value) {transID = value;};
    
    std::string toString();
};
}

#endif
