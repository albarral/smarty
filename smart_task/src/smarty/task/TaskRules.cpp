/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <exception>

#include "smarty/task/TaskRules.h"

using namespace log4cxx;

namespace smarty 
{
LoggerPtr TaskRules::logger(Logger::getLogger("smarty.task"));

TaskRules::TaskRules() 
{
}

TaskRules::~TaskRules ()
{
    setActions.clear();
    setStates.clear();
    listRules.clear();        
}
    
bool TaskRules::addAction(int action)
{
    int preSize = setActions.size();
    setActions.emplace(action);
    // returns true if correctly added (not existing before)
    return (setActions.size() > preSize);
}

bool TaskRules::addState(int state)
{
    int preSize = setStates.size();
    setStates.emplace(state);
    // returns true if correctly added (not existing before)    
    return (setStates.size() > preSize);
}

bool TaskRules::addRule(int action, int state, int result)
{
    st_rule rule{action, state, result};    
    listRules.push_back(rule);
    return true;    
}

void TaskRules::clearActions()
{
    setActions.clear();
    clearMatrix();    
}

void TaskRules::clearStates()
{
    setStates.clear();
    clearMatrix();        
}

void TaskRules::clearRules()
{
    listRules.clear();    
    clearMatrix();        
}

void TaskRules::buildMatrix()
{
    // create matrix 
    matRules = cv::Mat::zeros(setActions.size(), setStates.size(), CV_8UC1);
        
    // set results for all rules
    for (st_rule& rule : listRules)
    {
        try 
        {
            matRules.at<uchar>(rule.action, rule.state) = (uchar)rule.result;
        } 
        // skip if action or state not valid
        catch (std::exception& e)
        {              
            LOG4CXX_ERROR(logger, "TaskRules: invalid rule rejected " << rule.action << "," << rule.state << "," << rule.result);            
        }            
    }    
}

int TaskRules::getResult4Action(int action, int state) 
{
    try 
    {
        // get result for given combination
        return (int)matRules.at<uchar>(action, state);
    } 
    // protect invalid access
    catch (std::exception& e)
    {
        return UNDEF_RESULT;
    }
}

void TaskRules::clearMatrix()
{
    matRules = cv::Scalar(UNDEF_RESULT);
}
}