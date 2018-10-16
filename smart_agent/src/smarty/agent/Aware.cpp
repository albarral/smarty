/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "smarty/agent/Aware.h"

namespace smarty
{

Aware::Aware() : AgentBehaviour("Aware")
{
    pWorldStates = 0;
    bchangeDetected = false;
    numChange = 0;
}

//Aware::~Aware()
//{
//}

void Aware::connect(AgentBus& oAgentBus, AgentData& oAgentData)
{
    pWorldStates = &oAgentData.getWorldStates();    
    AgentBehaviour::connect(oAgentBus, oAgentData);
}


void Aware::informChangeDetected()
{
    if (bchangeDetected)
        pAgentBus->getSO_CHANGE_DETECTED().setValue(numChange);
}

}