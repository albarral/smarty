#ifndef __SMARTY_AGENT_AGENTMODULE_H
#define __SMARTY_AGENT_AGENTMODULE_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "smarty/agent/core/AgentBus.h"
#include "smarty/agent/core/AgentData.h"
#include "tron/control/module3.h"

namespace smarty
{
// Base class for smart agent modules.
// Usage:
// - connect bus
// - init
// - on (now it works)
// - off    
class AgentModule : public tron::Module3
{
protected:
    bool benabled;
    // bus
//    bool binhibited;
    AgentBus* pAgentBus;     // access to agent bus
    AgentData* pAgentData;     // access to agent data

public:
    AgentModule();
    //~AgentModule();

    // initialize module
    void init(AgentBus& oAgentBus, AgentData& oAgentData);
    bool isEnabled() {return benabled;};
    
protected:
    // read bus data   
    virtual void senseBus() = 0;
    // write commands or sensor info to bus    
    virtual void writeBus() = 0;
    // show module initialization in logs
    virtual void showInitialized() = 0;

};
}		
#endif
