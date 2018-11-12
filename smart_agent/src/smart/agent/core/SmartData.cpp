/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "smart/agent/core/SmartData.h"

namespace smart 
{
// Constructor
SmartData::SmartData ()
{    
}

// Destructor
//SmartData::~SmartData ()
//{
//}

void SmartData::getBoardCopy(tron::Board& oBoard2)
{
    std::lock_guard<std::mutex> locker(mutexBoard);
    oBoard2.clear();
    oBoard2 = oBoard;        
}

void SmartData::updateBoard(tron::Board& oBoard2)
{
    std::lock_guard<std::mutex> locker(mutexBoard);
    oBoard.clear();
    oBoard = oBoard2;    
}

}

