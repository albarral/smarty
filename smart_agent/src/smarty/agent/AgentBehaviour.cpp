/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "smarty/agent/AgentBehaviour.h"

namespace smarty
{
// Constructor 
AgentBehaviour::AgentBehaviour(std::string name) : tron::Behaviour(name)
{    
    benabled = false;
    pAgentBus = 0;
    pAgentData = 0;
 }

void AgentBehaviour::connect(AgentBus& oAgentBus, AgentData& oAgentData)
{
    pAgentBus = &oAgentBus;    
    pAgentData = &oAgentData;    
    benabled = true;    
}

}