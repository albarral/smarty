/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <unistd.h>

#include "smart/app/Smarty.h"

using namespace log4cxx;

namespace smart
{
LoggerPtr Smarty::logger(Logger::getLogger("smart.app"));

// Constructor
Smarty::Smarty ()
{    
}

// Destructor
Smarty::~Smarty ()
{
}

bool Smarty::launch() 
{      
    bool bok = false;
    LOG4CXX_INFO(logger, "Launch smarty agent");
            
    // launch agent
    bok = oAgent.launch(oSmartBus);        

    return bok;
}

bool Smarty::end()
{
    // finish agent
    oAgent.end();
}

bool Smarty::checkEndRequested()
{
//    return oSmartComs.checkEndRequested();
    return false;
}

}



