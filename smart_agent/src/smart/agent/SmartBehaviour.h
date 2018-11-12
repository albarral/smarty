#ifndef __SMART_AGENT_AGENTBEHAVIOUR_H
#define __SMART_AGENT_AGENTBEHAVIOUR_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "smart/agent/core/SmartBus.h"
#include "smart/agent/core/SmartData.h"
#include "tron/control/Behaviour.h"

namespace smart
{
// Base class for smart agent behaviours
// Must be connected to smart bus & smart data in order to enable it.
class SmartBehaviour : public tron::Behaviour
{
protected:
    bool benabled;
    SmartBus* pSmartBus;     // access to smart bus
    SmartData* pSmartData;     // access to smart data

public:
    SmartBehaviour(std::string name);
    //~SmartBehaviour();

    // bus & data connection 
    virtual void connect(SmartBus& oSmartBus, SmartData& oSmartData);
    bool isEnabled() {return benabled;};    
};
}		
#endif
