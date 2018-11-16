#ifndef __PLAY_UTILS_CELLSENSOR_H
#define __PLAY_UTILS_CELLSENSOR_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <vector>
#include <log4cxx/logger.h>

#include "tron/tools/FileReader.h"

namespace smart
{
// Class used to sense simulated board cells.
// It uses a file as the physical existence of the cell.
class CellSensor
{
private:
    static log4cxx::LoggerPtr logger;
    tron::FileReader oFileReader;

public:
    CellSensor();
    ~CellSensor();

    bool init(std::string cellAddress);
    bool isEnabled();
    
    std::vector<std::string> readCell();
};
}
#endif
