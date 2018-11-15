/***************************************************************************
 *   Copyright (C) 2015 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/


#include <vector>
#include <string>
#include <unistd.h> // for sleep() 

#include <log4cxx/logger.h>
#include <log4cxx/xml/domconfigurator.h>

#include "smart/app/Smarty.h"

using namespace smart;

void run();
// obtains user's home path
std::string getHomePath();

log4cxx::LoggerPtr logger(log4cxx::Logger::getLogger("smart.app"));

// main program
int main(int argc, char** argv) 
{
    std::string home = getHomePath();
    std::string configFile = home + "/.tron/log4cxx_config_smarty.xml";
    log4cxx::xml::DOMConfigurator::configure(configFile);    
        
    LOG4CXX_INFO(logger, "\n\nSTART smarty\n");

    run();
      
    return 0;
}

// runs the body control
void run()
{        
    Smarty oSmarty; 

    // launch smarty & wait for it to end        
    if (oSmarty.launch())
    {    
        int secs =0;
        while (!oSmarty.checkEndRequested() && secs++ < 10) 
        {
            sleep(1);            
        }    

        LOG4CXX_INFO(logger, "\nsmarty end requested ...\n");
        oSmarty.end();        
    }
    else
        LOG4CXX_ERROR(logger, "smarty could not be launched");
        
    return;
}

std::string getHomePath()
{    
    // obtain value of HOME environment variable
    char* pVar = getenv("HOME");    
    if (pVar!=NULL)
    {
        // transform it in a string
        std::string home(pVar);
        return home;
    }
    else
        return "";
}
