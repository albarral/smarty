#ifndef __SMARTY_AGENT_AGENTBEHAVIOUR_H
#define __SMARTY_AGENT_AGENTBEHAVIOUR_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "smarty/agent/core/AgentBus.h"
#include "smarty/agent/core/AgentData.h"
#include "tron/control/Behaviour.h"

namespace smarty
{
// Base class for smart agent behaviours
// Must be connected to agent bus & agent data in order to enable it.
class AgentBehaviour : public tron::Behaviour
{
protected:
    bool benabled;
    AgentBus* pAgentBus;     // access to agent bus
    AgentData* pAgentData;     // access to agent data

public:
    AgentBehaviour(std::string name);
    //~AgentBehaviour();

    // bus & data connection 
    virtual void connect(AgentBus& oAgentBus, AgentData& oAgentData);
    bool isEnabled() {return benabled;};    
};
}		
#endif
