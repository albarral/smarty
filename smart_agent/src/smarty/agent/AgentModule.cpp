/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "smarty/agent/AgentModule.h"

namespace smarty
{
// Constructor 
AgentModule::AgentModule()
{    
    modName = "AgentModule";
    benabled = false;
    pAgentBus = 0;
    pAgentData = 0;
 }

void AgentModule::init(AgentBus& oAgentBus, AgentData& oAgentData)
{
    pAgentBus = &oAgentBus;    
    pAgentData = &oAgentData;    
    benabled = true;    
    showInitialized();
}

}