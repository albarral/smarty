#ifndef __SMART_AGENT_SMARTDATA_H
#define __SMART_AGENT_SMARTDATA_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <mutex>

//#include "smarty/task/Task.h"
//#include "smarty/task/Rules.h"
#include "tron/space/Board.h"

namespace smart 
{
class SmartData
{
    private:
        std::mutex mutexBoard;        
//        std::mutex mutexRules;        
//        Task oTask;          // performed task
//        Rules oRules;     // task rules
        tron::Board oBoard;
        
    public:
        SmartData();
        //~SmartData();
                
//        Task& getTask() {return oTask;};
//        Rules& getRules() {return oRules;};
        tron::Board& getBoard() {return oBoard;};
        void getBoardCopy(tron::Board& oBoard2);
        
//        void setTask(Task& oTask) {this->oTask = oTask;};
//        void setRules(Rules& oRules) {this->oRules = oRules;};
        void updateBoard(tron::Board& oBoard2);
};
}    
#endif

        