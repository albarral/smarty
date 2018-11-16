/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "play/utils/CellSensor.h"

using namespace log4cxx;

namespace smart
{
LoggerPtr CellSensor::logger(Logger::getLogger("tron"));

// Constructor 
CellSensor::CellSensor()
{    
 }

CellSensor::~CellSensor()
{
    if (oFileReader.isOpen())
        oFileReader.close();  
}

bool CellSensor::init(std::string cellAddress)
{    
    LOG4CXX_DEBUG(logger, "CellSensor: init on path " + cellAddress);
    oFileReader.open(cellAddress);    
    
    return oFileReader.isOpen();
}

bool CellSensor::isEnabled()
{
    return oFileReader.isOpen();    
}

std::vector<std::string> CellSensor::readCell()
{
    std::vector<std::string> listLines;            
    if (oFileReader.isOpen())
    {
        oFileReader.readAllLines(listLines);
        LOG4CXX_DEBUG(logger, "CellSensor: read ... " << listLines.data());
    }
    else
    {
        LOG4CXX_WARN(logger, "CellSensor: can't read cell, file reader not open");        
    }
    
    return listLines;
}

}
