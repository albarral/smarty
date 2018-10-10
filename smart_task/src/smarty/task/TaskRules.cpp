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
    
    return (setActions.size() > preSize);
}

bool TaskRules::addState(int state)
{
    int preSize = setStates.size();
    setStates.emplace(state);
    
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
    clearResults();    
}

void TaskRules::clearStates()
{
    setStates.clear();
    clearResults();        
}

void TaskRules::clearRules()
{
    listRules.clear();    
    clearResults();        
}

void TaskRules::setResults()
{
    // create matrix 
    matResults = cv::Mat::zeros(setActions.size(), setStates.size(), CV_8UC1);
        
    // set results for all rules
    for (st_rule& rule : listRules)
    {
        try 
        {
            matResults.at<uchar>(rule.action, rule.state) = (uchar)rule.result;
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
        return (int)matResults.at<uchar>(action, state);
    } 
    // protect invalid access
    catch (std::exception& e)
    {
        return eRESULT_UNDEFINED;
    }
}

int TaskRules::getOppositeResult(int result)
{
    switch (result)
    {
        case eRESULT_WIN:
            return eRESULT_LOOSE;
            break;
            
        case eRESULT_LOOSE:
            return eRESULT_WIN;
            break;
            
        case eRESULT_NEUTRAL:
            return eRESULT_NEUTRAL;
            break;
            
        default:
            return eRESULT_UNDEFINED;
    }
}

void TaskRules::clearResults()
{
    matResults = cv::Scalar(eRESULT_UNDEFINED);
}
}