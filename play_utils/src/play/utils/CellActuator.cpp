/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

#include "play/utils/CellActuator.h"

using namespace log4cxx;

namespace smart
{
LoggerPtr CellActuator::logger(Logger::getLogger("tron"));

// Constructor 
CellActuator::CellActuator()
{    
 }

CellActuator::~CellActuator()
{
    if (oFileWriter.isOpen())
        oFileWriter.close();  
}

bool CellActuator::init(std::string cellAddress)
{    
    LOG4CXX_DEBUG(logger, "CellActuator: init on path " + cellAddress);
    oFileWriter.open(cellAddress, true);    // append mode
    
    return oFileWriter.isOpen();
}

void CellActuator::clearCell()
{
    oFileWriter.cleanFile();
}

void CellActuator::putElement(int element)
{
    if (oFileWriter.isOpen())
    {
        std::string line = std::to_string(element) + "\n";        
        oFileWriter.writeFlush(line);                
        LOG4CXX_DEBUG(logger, "CellActuator: write ... " + line);
    }
    else
    {
        LOG4CXX_WARN(logger, "CellActuator: can't put element, file writer not open");        
    }
}

}
