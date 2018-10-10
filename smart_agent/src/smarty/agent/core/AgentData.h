#ifndef __SMARTY_AGENT_AGENTDATA_H
#define __SMARTY_AGENT_AGENTDATA_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

//#include <mutex>

#include "smarty/task/Task.h"
#include "smarty/task/TaskRules.h"

namespace smarty 
{
class AgentData
{
    private:
//        std::mutex mutexTask;        
//        std::mutex mutexRules;        
        Task oTask;          // performed task
        TaskRules oTaskRules;     // present task rules
        
    public:
        AgentData();
        //~AgentData();
                
        Task& getTask() {return oTask;};
        TaskRules& getTaskRules() {return oTaskRules;};
};
}    
#endif

        