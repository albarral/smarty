#ifndef __SMARTY_AGENT_ANALYZER_H
#define __SMARTY_AGENT_ANALYZER_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "smarty/agent/AgentBehaviour.h"

namespace smarty
{
// Base module used for aware behaviour.
class Analyzer : public AgentBehaviour
{
protected:    
    WorldStates* pWorldStates;  // shared access to world states   
    TaskRules* pTaskRules;     // shared access to task rules
    bool bchangeAnalyzed;
    int numChange; 

public:
        Analyzer();
        //~Analyzer();
        
        void connect(AgentBus& oAgentBus, AgentData& oAgentData) override;
        
protected:
        void informChangeAnalyzed();
};
}
#endif
