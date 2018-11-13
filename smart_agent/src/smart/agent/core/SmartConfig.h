#ifndef __SMART_AGENT_SMARTCONFIG_H
#define __SMART_AGENT_SMARTCONFIG_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

namespace smart
{
class SmartConfig 
{
private:                
        float modulesFreq;  // execution frequency for all modules (loops/sec)
        int agentLevels;        // hierarchical levels used in smart agent 
        
    public:
        SmartConfig();
        //~SmartConfig();
                        
        float getModulesFreq() {return modulesFreq;}
        int getAgentLevels() {return agentLevels;};
};

}

#endif
