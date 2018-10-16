#ifndef __SMARTY_AGENT_AGENTDATA_H
#define __SMARTY_AGENT_AGENTDATA_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

//#include <mutex>

#include "smarty/task/Task.h"
#include "smarty/task/TaskRules.h"
#include "smarty/task/WorldStates.h"

namespace smarty 
{
class AgentData
{
    private:
//        std::mutex mutexTask;        
//        std::mutex mutexRules;        
        Task oTask;          // performed task
        TaskRules oTaskRules;     // task rules
        WorldStates oWorldStates; // world states
        
    public:
        AgentData();
        //~AgentData();
                
        Task& getTask() {return oTask;};
        TaskRules& getTaskRules() {return oTaskRules;};
        WorldStates& getWorldStates() {return oWorldStates;};
        
        void setTask(Task& oTask) {this->oTask = oTask;};
        void setTaskRules(TaskRules& oTaskRules) {this->oTaskRules = oTaskRules;};
        void setWorldStates(WorldStates& oWorldStates) {this->oWorldStates = oWorldStates;};
};
}    
#endif

        