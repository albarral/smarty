/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "smart/agent/Analyzer.h"

namespace smart
{

Analyzer::Analyzer() : SmartBehaviour("Analyzer")
{
    pEnvironment = 0;
    pRules = 0;
    bchangeAnalyzed = false;
    numChange = 0;
}

//Analyzer::~Analyzer()
//{
//}

void Analyzer::connect(SmartBus& oAgentBus, SmartData& oAgentData)
{
    pEnvironment = &oAgentData.getEnvironment();    
    pRules = &oAgentData.getRules();
    SmartBehaviour::connect(oAgentBus, oAgentData);
}


void Analyzer::informChangeAnalyzed()
{
    if (bchangeAnalyzed)
        pAgentBus->getSO_CHANGE_ANALYZED().setValue(numChange);
}

}