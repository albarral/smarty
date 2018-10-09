/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <exception>

#include "smarty/core/TaskRules.h"

namespace smarty 
{
TaskRules::TaskRules() 
{
}

int TaskRules::getResult4Move(int myAction, int othersAction) 
{
    try 
    {
        // get result for given combination
        return (int)mat.at<uchar>(myAction, othersAction);
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
            
        case eRESULT_DRAW:
            return eRESULT_DRAW;
            break;
            
        default:
            return eRESULT_UNDEFINED;
    }
}

    
//bool TaskRules::addAction(int actionCode, std::string actionName)
bool TaskRules::addAction(int actionCode)
{
    setActions.emplace(actionCode);
    //listNames.push_back(actionName);
}
    
bool TaskRules::addRule(int myAction, int othersAction, int result)
{
    // prepare matrix if not done before
    if (mat.cols == 0 && mat.rows == 0)
    {
        mat = cv::Mat::zeros(setActions.size(), setActions.size(), CV_8UC1);
    }
        
    try 
    {
        // set result for given combination
        mat.at<uchar>(myAction, othersAction) = (uchar)result;
        // and opposite result for mirror combination
        mat.at<uchar>(othersAction, myAction) = (uchar)getOppositeResult(result);
        return true;
    } 
    // protect invalid access
    catch (std::exception& e)
    {
        return false;
    }    
}

}