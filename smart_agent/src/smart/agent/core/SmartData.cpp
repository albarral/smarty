/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "smart/agent/core/SmartData.h"
#include "tron/space/Space.h"

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

void SmartData::updateBoardContents(tron::Board& oBoard2, std::vector<int>& listSpaces)
{
    std::lock_guard<std::mutex> locker(mutexBoard);
    // update the specified spaces in board
    for (int pos : listSpaces)
    {
        tron::Space* pSpace2 = oBoard2.getSpace(pos);
        if (pSpace2 != nullptr)
            oBoard.updateSpace(pos, *pSpace2);
    }
}

}

