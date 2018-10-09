#ifndef __SMARTY_CORE_TASKRULES_H
#define __SMARTY_CORE_TASKRULES_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "opencv2/core/core.hpp"

#include <string>
#include <set>

namespace smarty 
{
// Class used to manage the rules of a task.
class TaskRules
{
 public:
    /*! task results  */
    enum eResults
    {
         eRESULT_UNDEFINED,                       
         eRESULT_WIN,                       
         eRESULT_LOOSE,                       
         eRESULT_DRAW,                    
         eRESULT_DIM
    };

protected:
    std::set<int> setActions;    // available actions for the task
    //std::vector<std::string> listNames;  // action names
    cv::Mat mat;   // results matrix for all action combinations
    
public:
    TaskRules();
    //~TaskRules();
    
    // gets result for given action combination (mine vs others)
    int getResult4Move(int myAction, int othersAction);
    
    // gets copy of actions list
    std::set<int> getListActions() {return setActions;};
    
    virtual void setRules() = 0;

    // get opposite result to given one
    static int getOppositeResult(int result);
    
protected:
    // add an action to actions list
    bool addAction(int actionCode);
    //bool addAction(int actionCode, std::string actionName);
    
    // add a specific rule (deterministic result for the given action combination)
    bool addRule(int myAction, int othersAction, int result);
};
}

#endif
