/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "smart/agent/Aware.h"

namespace smart
{

Aware::Aware() : SmartBehaviour("Aware")
{
    numChange = 0;
}

//Aware::~Aware()
//{
//}

void Aware::actuate()
{
    // note: the Board should be perceived at sense()
    
    // if board has changed, inform everybody
    if (!(oBoard == pSmartData->getBoard()))
        pSmartBus->getSO_CHANGE_DETECTED().setValue(++numChange);        
}
}