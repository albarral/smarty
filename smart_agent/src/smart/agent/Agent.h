#ifndef __SMART_AGENT_AGENT_H
#define __SMART_AGENT_AGENT_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <vector>
#include <log4cxx/logger.h>

#include "smart/agent/core/SmartBus.h"
#include "smart/agent/core/SmartData.h"
#include "smart/agent/modules/Aware.h"
#include "tron/control/Module4.h"

namespace smart
{
// This class represents a smart agent.
// It is composed of various modules, each running a specific behaviour.
// Behaviours are distributed in levels.     
class Agent
{
    private:
        static log4cxx::LoggerPtr logger;
        SmartData oSmartData;   // agent's internal data
        bool blaunched;     // indicates when the manager has been launched   
        int topLevel; // allow activation of modules until this level
        // modules ...
        // level 4
        // level 3
        // level 2
        // level 1
        Aware oAware;       // Aware behaviour
        std::vector<tron::Module4*> listModules1;      // list of modules (level 1)
//        std::vector<tron::Module4*> listModules2;      // list of modules (level 2)
//        std::vector<tron::Module4*> listModules3;      // list of modules (level 3)
//        std::vector<tron::Module4*> listModules4;      // list of modules (level 4)

    public:
        Agent();
        ~Agent();

       // launches the agent (returns false if something fails)
       bool launch(SmartBus& oSmartBus);
       // ends the agent
       bool end();
       bool isLaunched() {return blaunched;};                
              
private:
    // initialize control architecture (organize in levels)
    void initArchitecture(SmartBus& oSmartBus);
    // show description of control architecture
    void showArchitecture();

    // starts the task's modules 
    void startModules(float freq);        
    // stops the tasks' modules
    void stopModules();            
    
   // start the modules of a level
    void startLevel(int level, float freq);        
   // stop the modules of a level
    void stopLevel(int level);
    // clear modules from level
    void clearLevel(int level);
    
    std::vector<tron::Module4*>* getModules4Level(int level);
};

}    
#endif
