#ifndef __SMARTY_TASK_RULES_H
#define __SMARTY_TASK_RULES_H

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
// A rules matrix is used to represent all the task rules.
class Rules
{
 public:
     static const int UNDEF_RESULT = 0;
    
    struct st_rule{
        int action; 
        int state; 
        int result;
    };

private:
    static log4cxx::LoggerPtr logger;
    std::set<int> setActions;    // available actions for the task
    std::set<int> setStates;    // available states for the task
    std::vector<st_rule> listRules;  // task main rules (specified)
    cv::Mat matRules;   // rules matrix (results for all action-state combinations)
    
public:
    Rules();
    ~Rules();

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
    
    // clear all actions (implies clearing rules matrix)
    void clearActions();
    // clear all states (implies clearing rules matrix)
    void clearStates();
    // clear all rules (implies clearing rules matrix)
    void clearRules();
            
    // build rules matrix from task main rules
    void buildMatrix();
    // get result for given action-state combination
    int getResult4Action(int action, int state);    
    
private:
    // clear rules matrix
    void clearMatrix();
};
}

#endif
