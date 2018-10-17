#ifndef __SMARTY_AGENT_AGENTDATA_H
#define __SMARTY_AGENT_AGENTDATA_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

//#include <mutex>

#include "smarty/task/Task.h"
#include "smarty/task/Rules.h"
#include "smarty/task/Environment.h"

namespace smarty 
{
class AgentData
{
    private:
//        std::mutex mutexTask;        
//        std::mutex mutexRules;        
        Task oTask;          // performed task
        Rules oRules;     // task rules
        Environment oEnvironment; // task environment
        
    public:
        AgentData();
        //~AgentData();
                
        Task& getTask() {return oTask;};
        Rules& getRules() {return oRules;};
        Environment& getEnvironment() {return oEnvironment;};
        
        void setTask(Task& oTask) {this->oTask = oTask;};
        void setRules(Rules& oRules) {this->oRules = oRules;};
        void setEnvironment(Environment& oEnvironment) {this->oEnvironment = oEnvironment;};
};
}    
#endif

        