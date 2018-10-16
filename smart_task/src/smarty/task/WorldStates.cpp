/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <exception>

#include "smarty/task/WorldStates.h"

using namespace log4cxx;

namespace smarty 
{
LoggerPtr WorldStates::logger(Logger::getLogger("smarty.task"));

WorldStates::WorldStates() 
{
}

WorldStates::~WorldStates ()
{
    setOwnStatus.clear();
    setWorldStatus.clear();
    listStates.clear();        
}
    
bool WorldStates::addOwnStatus(int ownStatus)
{
    int preSize = setOwnStatus.size();
    setOwnStatus.emplace(ownStatus);
    // returns true if correctly added (not existing before)    
    return (setOwnStatus.size() > preSize);
}

bool WorldStates::addWorldStatus(int worldStatus)
{
    int preSize = setWorldStatus.size();
    setWorldStatus.emplace(worldStatus);
    // returns true if correctly added (not existing before)    
    return (setWorldStatus.size() > preSize);
}

bool WorldStates::addState(int ownStatus, int worldStatus, int state)
{
    st_state stState{ownStatus, worldStatus, state};    
    listStates.push_back(stState);
    return true;    
}

void WorldStates::clearOwnStatusList()
{
    setOwnStatus.clear();
    clearMatrix();    
}

void WorldStates::clearWorldStatusList()
{
    setWorldStatus.clear();
    clearMatrix();        
}

void WorldStates::clearStates()
{
    listStates.clear();    
    clearMatrix();        
}

void WorldStates::buildMatrix()
{
    // create matrix 
    matStates = cv::Mat::zeros(setOwnStatus.size(), setWorldStatus.size(), CV_8UC1);
        
    // set states for all own_status - world_status combinations
    for (st_state& rule : listStates)
    {
        try 
        {
            matStates.at<uchar>(rule.ownStatus, rule.worldStatus) = (uchar)rule.state;
        } 
        // skip if action or state not valid
        catch (std::exception& e)
        {              
            LOG4CXX_ERROR(logger, "WorldStates: invalid state rejected " << rule.ownStatus << "," << rule.worldStatus << "," << rule.state);            
        }            
    }    
}

int WorldStates::getState4Situation(int ownStatus, int worldStatus)
{
    try 
    {
        // get result for given combination
        return (int)matStates.at<uchar>(ownStatus, worldStatus);
    } 
    // protect invalid access
    catch (std::exception& e)
    {
        return UNDEF_STATE;
    }
}

void WorldStates::clearMatrix()
{
    matStates = cv::Scalar(UNDEF_STATE);
}
}