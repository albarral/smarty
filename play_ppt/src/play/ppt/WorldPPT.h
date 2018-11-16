#ifndef __PLAY_PPT_WORLDPPT_H
#define __PLAY_PPT_WORLDPPT_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <vector>
#include <log4cxx/logger.h>

#include "play/utils/CellSensor.h"
#include "tron/control/module3.h"
#include "tron/display/DrawnDisplay.h"

namespace smart
{
// Class used to test tron_tools lib.
class WorldPPT : public tron::Module3

{
private:
    static log4cxx::LoggerPtr logger;
    CellSensor oCellSensor1;
    CellSensor oCellSensor2;
    std::vector<std::string> listElements1;
    std::vector<std::string> listElements2;    
    tron::DrawnDisplay oDisplay;

public:
    WorldPPT();
    ~WorldPPT();

    void init();
    
private:
    // first actions when the thread begins 
    virtual void first();
    // loops inside the thread 
    virtual void loop();
    
    void checkCells();
    void updateDisplay();
};
}
#endif
