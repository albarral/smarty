#ifndef __SMARTY_AGENT_AGENTBUS_H
#define __SMARTY_AGENT_AGENTBUS_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

//#include "tron/control/brooks/control.h"
//#include "tron/control/brooks/ControlS.h"
//#include "tron/control/brooks/controlT.h"
//#include "tron/control/brooks/inhibition.h"
//#include "tron/control/brooks/sensor.h"
#include "tron/control/brooks/sensor2.h"

namespace smarty
{
class AgentBus
{
    private:        
        // CONTROLS                
                                
        // SENSORS
        tron::Sensor2 SO_CHANGE_DETECTED;        // change detected by Aware module
        tron::Sensor2 SO_CHANGE_ANALYSED;        // change analyzed by Analyzer module
        tron::Sensor2 SO_ACTION_DONE;                // action done by Actor module
        tron::Sensor2 SO_ACTION_LEARNED;            // action learned by Learner module
        
    public:
        AgentBus();
        //~AgentBus();
                
        // CONTROLS                
        
        // SENSORS
        tron::Sensor2& getSO_CHANGE_DETECTED() {return SO_CHANGE_DETECTED;};        
        tron::Sensor2& getSO_CHANGE_ANALYSED() {return SO_CHANGE_ANALYSED;};        
        tron::Sensor2& getSO_ACTION_DONE() {return SO_ACTION_DONE;};        
        tron::Sensor2& getSO_ACTION_LEARNED() {return SO_ACTION_LEARNED;};        
        
        //std::string toString();
};

}    
#endif
