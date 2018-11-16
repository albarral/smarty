/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "play/ppt/WorldPPT.h"

using namespace log4cxx;

namespace smart
{
LoggerPtr WorldPPT::logger(Logger::getLogger("play.ppt"));

// Constructor 
WorldPPT::WorldPPT()
{    
    modName = "WorldPPT";
 }

WorldPPT::~WorldPPT()
{    
    listElements1.clear();
    listElements2.clear();
 }

void WorldPPT::init()
{    
    LOG4CXX_INFO(logger, modName + ": init \n");

    oCellSensor1.init("/home/albarral/TESTS/SMART/pptcell1.txt");
    oCellSensor2.init("/home/albarral/TESTS/SMART/pptcell2.txt");
    oDisplay.init("PPT board", 200, 100);
};

void WorldPPT::first()
{
    LOG4CXX_INFO(logger, modName + ": first ...");
    
    if (!oCellSensor1.isEnabled() || !oCellSensor2.isEnabled())
    {
        LOG4CXX_WARN(logger, modName + ": ppt cells not enabled, going down!");
        off();
    }
}

void WorldPPT::loop()
{
    checkCells();
    
    updateDisplay();    
}

void WorldPPT::checkCells()
{
    listElements1 = oCellSensor1.readCell();
    listElements2 = oCellSensor2.readCell();
}

void WorldPPT::updateDisplay()
{
    cv::Point center = oDisplay.getCardinalPoint(tron::Draw::ePOINT_CENTER);    

    oDisplay.clear();
    oDisplay.drawVLine(center.x);
    
    // draw cell 1
    int x = 20;
    int y = 20;
    for (std::string element : listElements1)
    {
        cv::Point pos = cv::Point(x, y);
        oDisplay.drawText(element, pos);
        y += 20;        
    }
    
    // draw cell 2
    x = center.x + 20;
    y = 20;
    for (std::string element : listElements2)
    {
        cv::Point pos = cv::Point(x, y);
        oDisplay.drawText(element, pos);
        y += 20;        
    }
    
    oDisplay.update();
}

}