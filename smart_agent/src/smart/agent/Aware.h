#ifndef __SMART_AGENT_AWARE_H
#define __SMART_AGENT_AWARE_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "smart/agent/SmartBehaviour.h"
#include "tron/space/Board.h"

namespace smart
{
// Base module used for aware behaviour.
class Aware : public SmartBehaviour
{
protected:    
    tron::Board oBoard;
    int numChange; 

public:
        Aware();
        //~Aware();
        
        // things to do when the behavior starts
        virtual void start() {};
        // behavior sense phase
        virtual void sense() = 0;            
        // behavior actuate phase
        virtual void actuate() override;
        // things to do when the behavior ends
        virtual void end() {};        
};
}
#endif
