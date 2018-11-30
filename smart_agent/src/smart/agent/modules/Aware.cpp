/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "smart/agent/modules/Aware.h"

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
    // note: the Board must be perceived at sense()
    
    // if board contents changed
    if (!oSpaceCompare.compareBoardContents(oBoard, pSmartData->getBoard()))
    {
        // update shared board 
        pSmartData->updateBoardContents(oBoard, oSpaceCompare.getListDifferences());
        // and inform everybody
        numChange++;        
        pSmartBus->getSO_CHANGE_DETECTED().setValue(numChange);        
    }
}
}