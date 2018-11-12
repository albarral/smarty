/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <exception>

#include "smarty/task/Environment.h"

using namespace log4cxx;

namespace smart 
{
LoggerPtr Environment::logger(Logger::getLogger("smarty.task"));

Environment::Environment() 
{
}

Environment::~Environment ()
{
    setOwnStatus.clear();
    setWorldStatus.clear();
    listStates.clear();        
}
    
bool Environment::addOwnStatus(int ownStatus)
{
    int preSize = setOwnStatus.size();
    setOwnStatus.emplace(ownStatus);
    // returns true if correctly added (not existing before)    
    return (setOwnStatus.size() > preSize);
}

bool Environment::addWorldStatus(int worldStatus)
{
    int preSize = setWorldStatus.size();
    setWorldStatus.emplace(worldStatus);
    // returns true if correctly added (not existing before)    
    return (setWorldStatus.size() > preSize);
}

bool Environment::addState(int ownStatus, int worldStatus, int state)
{
    st_state stState{ownStatus, worldStatus, state};    
    listStates.push_back(stState);
    return true;    
}

void Environment::clearOwnStatusList()
{
    setOwnStatus.clear();
    clearMatrix();    
}

void Environment::clearWorldStatusList()
{
    setWorldStatus.clear();
    clearMatrix();        
}

void Environment::clearStates()
{
    listStates.clear();    
    clearMatrix();        
}

void Environment::buildMatrix()
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
            LOG4CXX_ERROR(logger, "Environment: invalid state rejected " << rule.ownStatus << "," << rule.worldStatus << "," << rule.state);            
        }            
    }    
}

int Environment::getState4Situation(int ownStatus, int worldStatus)
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

void Environment::clearMatrix()
{
    matStates = cv::Scalar(UNDEF_STATE);
}
}