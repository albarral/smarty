/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "smarty/agent/Analyzer.h"

namespace smarty
{

Analyzer::Analyzer() : AgentBehaviour("Analyzer")
{
    pEnvironment = 0;
    pTaskRules = 0;
    bchangeAnalyzed = false;
    numChange = 0;
}

//Analyzer::~Analyzer()
//{
//}

void Analyzer::connect(AgentBus& oAgentBus, AgentData& oAgentData)
{
    pEnvironment = &oAgentData.getEnvironment();    
    pTaskRules = &oAgentData.getTaskRules();
    AgentBehaviour::connect(oAgentBus, oAgentData);
}


void Analyzer::informChangeAnalyzed()
{
    if (bchangeAnalyzed)
        pAgentBus->getSO_CHANGE_ANALYZED().setValue(numChange);
}

}