#ifndef __SMART_AGENT_ANALYZER_H
#define __SMART_AGENT_ANALYZER_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "smart/agent/SmartBehaviour.h"

namespace smart
{
// Base module used for aware behaviour.
class Analyzer : public SmartBehaviour
{
protected:    
    Environment* pEnvironment;  // shared access to environment   
    Rules* pRules;     // shared access to task rules
    bool bchangeAnalyzed;
    int numChange; 

public:
        Analyzer();
        //~Analyzer();
        
        void connect(SmartBus& oAgentBus, SmartData& oAgentData) override;
        
protected:
        void informChangeAnalyzed();
};
}
#endif
