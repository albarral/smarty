/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <vector>

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
    
    std::vector<int> listDifSpaces; 
    // if board contents changed
    if (pSmartData->getBoard().compareContents(oBoard, listDifSpaces) == false)      
    {
        // update shared board 
        pSmartData->updateBoardContents(oBoard, listDifSpaces);
        // and inform everybody
        numChange++;        
        pSmartBus->getSO_CHANGE_DETECTED().setValue(numChange);        
    }
}
}