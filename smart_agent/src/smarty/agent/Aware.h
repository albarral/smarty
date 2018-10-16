#ifndef __SMARTY_AGENT_AWARE_H
#define __SMARTY_AGENT_AWARE_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "smarty/agent/AgentBehaviour.h"

namespace smarty
{
// Base module used for aware behaviour.
class Aware : public AgentBehaviour
{
protected:    
    WorldStates* pWorldStates;  // shared access to world states   
    bool bchangeDetected;
    int numChange; 

public:
        Aware();
        //~Aware();
        
        void connect(AgentBus& oAgentBus, AgentData& oAgentData) override;
        
protected:
        void informChangeDetected();
};
}
#endif
