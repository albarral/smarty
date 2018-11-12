/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "smart/agent/SmartBehaviour.h"

namespace smart
{
// Constructor 
SmartBehaviour::SmartBehaviour(std::string name) : tron::Behaviour(name)
{    
    benabled = false;
    pSmartBus = 0;
    pSmartData = 0;
 }

void SmartBehaviour::connect(SmartBus& oSmartBus, SmartData& oSmartData)
{
    pSmartBus = &oSmartBus;    
    pSmartData = &oSmartData;    
    benabled = true;    
}

}