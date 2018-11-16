#ifndef __PLAY_UTILS_CELLACTUATOR_H
#define __PLAY_UTILS_CELLACTUATOR_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <log4cxx/logger.h>

#include "tron/tools/FileWriter.h"

namespace smart
{
// Class used to actuate on simulated board cells.
// It uses a file as the physical existence of the cell.
class CellActuator
{
private:
    static log4cxx::LoggerPtr logger;
    tron::FileWriter oFileWriter;

public:
    CellActuator();
    ~CellActuator();

    bool init(std::string cellAddress);
    bool isEnabled();
    
    void clearCell();
    void putElement(int element);
};
}
#endif
