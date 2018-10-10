#ifndef __SMARTY_TASK_TASKRULES_H
#define __SMARTY_TASK_TASKRULES_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <log4cxx/logger.h>
#include "opencv2/core/core.hpp"

#include <string>
#include <set>
#include <vector>

namespace smarty 
{
// Class used to manage the rules of a task.
// A rule is a combination of action, state and its associated result.
// A results matrix is used to represent all the task rules.
class TaskRules
{
 public:
    /*! task results  */
    enum eResults
    {
         eRESULT_UNDEFINED,                       
         eRESULT_WIN,                       
         eRESULT_LOOSE,                       
         eRESULT_NEUTRAL,                    
         eRESULT_DIM
    };
    
    struct st_rule{
        int action; 
        int state; 
        int result;
    };

private:
    static log4cxx::LoggerPtr logger;
    std::set<int> setActions;    // available actions for the task
    std::set<int> setStates;    // available states for the task
    std::vector<st_rule> listRules;  // main rules of the task
    cv::Mat matResults;   // results matrix for all action combinations
    
public:
    TaskRules();
    ~TaskRules();

    // get copy of actions list
    std::set<int> getListActions() {return setActions;};
    // get copy of states list
    std::set<int> getListStates() {return setStates;};
    // get copy of rules list
    std::vector<st_rule> getListRules() {return listRules;};

    // add action to actions list
    bool addAction(int action);
    // add state to states list
    bool addState(int state);    
    // add rule to rules list
    bool addRule(int action, int state, int result);
    
    // clear all actions (implies clearing results)
    void clearActions();
    // clear all states (implies clearing results)
    void clearStates();
    // clear all rules (implies clearing results)
    void clearRules();
            
    // build results matrix from existing rules
    void setResults();
    // get result for given action-state combination
    int getResult4Action(int action, int state);
    
    // get opposite result to given one
    static int getOppositeResult(int result);
    
private:
    // clear results matrix
    void clearResults();
};
}

#endif
