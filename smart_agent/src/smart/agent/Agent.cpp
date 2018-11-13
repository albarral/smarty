/***************************************************************************
 *   Copyright (C) 2015 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <unistd.h>
#include "log4cxx/ndc.h"

#include "smart/agent/Agent.h"
#include "smart/agent/core/SmartConfig.h"

using namespace log4cxx;

namespace smart
{
LoggerPtr Agent::logger(Logger::getLogger("smart.agent"));

// Constructor
Agent::Agent ()
{    
    blaunched = false;
    topLevel = 0;       
}

// Destructor
Agent::~Agent ()
{
    for (int i=0; i<=topLevel; i++)
        clearLevel(i);
}


bool Agent::launch(SmartBus& oSmartBus)
{  
    // launch it if not launched yet
    if (!blaunched)
    {
        log4cxx::NDC::push("Agent");   	
        LOG4CXX_INFO(logger, "Launching ");
        
        // read configuration
        SmartConfig oSmartConfig;
        float freq = oSmartConfig.getModulesFreq();
        topLevel = oSmartConfig.getAgentLevels();
                
        LOG4CXX_INFO(logger, "top level: " << topLevel);
        // organize control architecture in levels
        initArchitecture(oSmartBus);
        showArchitecture();

        // start modules
        startModules(freq);
        
        blaunched = true;    
    }
    // report problems
    else
        LOG4CXX_ERROR(logger, "Can't launch Agent: already launched!");        
    
    return blaunched;
}

bool Agent::end()
{
    stopModules();
}

void Agent::initArchitecture(SmartBus& oSmartBus)
{
    // level 1    
    // aware behaviour
    oAware.connect(oSmartBus, oSmartData);
    listModules1.push_back(new tron::Module4(oAware));
}

void Agent::showArchitecture()
{
    LOG4CXX_INFO(logger, ">> control architecture ...");
    for (int i=0; i<=topLevel; i++)
    {
        LOG4CXX_INFO(logger, "level " << std::to_string(i) << ":");        
        // get list of modules for given level
        std::vector<tron::Module4*>* pLevelModules = getModules4Level(i);
        if (pLevelModules != nullptr)
        {
            // show all modules in the level
            for (tron::Module4* pModule : *pLevelModules)
            {
                LOG4CXX_INFO(logger, "module " << pModule->getBehaviour()->getName());        
            }
        }    
    }
}

void Agent::startModules(float freq)
{
    LOG4CXX_INFO(logger, "STARTING MODULES ...");

    int microsWait = 100000;  // 100ms
    for (int i=0; i<=topLevel; i++)
    {
        startLevel(i, freq);
        usleep(microsWait);
    }
}

void Agent::stopModules()
{    
    LOG4CXX_INFO(logger, "STOPPING MODULES ...");

    if (!blaunched)
        return;

    for (int i=topLevel; i>=0; i--)
    {
        stopLevel(i);
    }
}

void Agent::startLevel(int num, float freq)
{
    LOG4CXX_INFO(logger, ">> START level " << num);

    // get list of modules for given level
    std::vector<tron::Module4*>* pLevelModules = getModules4Level(num);
    if (pLevelModules != nullptr)
    {
        // start each module in the level
        for (tron::Module4* pModule : *pLevelModules)
        {
            if (!pModule->isOn())
            {
                pModule->setFrequency(freq);  
                pModule->on();
            }
        }
    }    
}

void Agent::stopLevel(int num)
{
    LOG4CXX_INFO(logger, ">> STOP level " << num);

    // get list of modules for given level
    std::vector<tron::Module4*>* pLevelModules = getModules4Level(num);
    if (pLevelModules != nullptr)
    {
        // stop each module in the level
        for (tron::Module4* pModule : *pLevelModules)
        {
            if (pModule->isOn())
            {
                pModule->off();
                pModule->wait();
            }
        }
    }    
}

void Agent::clearLevel(int num)
{
    LOG4CXX_INFO(logger, ">> CLEAR level " << num);

    // get list of modules for given level
    std::vector<tron::Module4*>* pLevelModules = getModules4Level(num);
    if (pLevelModules != nullptr)
    {
        // clear each module in the level (from heap)
        for (tron::Module4* pModule : *pLevelModules)
        {
            if (pModule)
                delete(pModule);                    
        }
        // finally delete modules list
        pLevelModules->clear();        
    }    
}

std::vector<tron::Module4*>* Agent::getModules4Level(int level)
{
    switch (level)
    {
        case 1: 
            return &listModules1;
//        case 2: 
//            return &listModules2;
//        case 3: 
//            return &listModules3;
//        case 4: 
//            return &listModules4;
        default: 
            return nullptr;
    }
}

}



