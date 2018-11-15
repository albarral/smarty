#ifndef __SMART_APP_SMARTY_H
#define __SMART_APP_SMARTY_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <log4cxx/logger.h>

#include "smart/agent/Agent.h"
#include "smart/agent/core/SmartBus.h"

namespace smart
{
// This class controls the smarty agent.
// It instantiates the bus and launches the agent.
class Smarty
{
    private:
        static log4cxx::LoggerPtr logger;
        SmartBus oSmartBus;                            
        Agent oAgent;

    public:
        Smarty();
        ~Smarty();

       // launches the agent (returns false if something fails)
       bool launch();
       // ends all modules
       bool end();

        // checks if end process has been requested from outside
        bool checkEndRequested();        
                
        // access body bus (JUST FOR TEST)
        SmartBus& getSmartBus4Test() {return oSmartBus;};        
};

}    
#endif
