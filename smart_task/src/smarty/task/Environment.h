#ifndef __SMART_TASK_ENVIRONMENT_H
#define __SMART_TASK_ENVIRONMENT_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <log4cxx/logger.h>
#include "opencv2/core/core.hpp"

#include <string>
#include <set>
#include <vector>

namespace smart 
{
// Class used to manage the states of the environment (the place where a task occurs).
// An environment state is a combination of own status, world status and its associated state.
// A states matrix is used to represent all the environment states.
class Environment
{
 public:
     static const int UNDEF_STATE = 0;
    
    struct st_state{
        int ownStatus; 
        int worldStatus; 
        int state;
    };

private:
    static log4cxx::LoggerPtr logger;
    std::set<int> setOwnStatus;    // available own status options
    std::set<int> setWorldStatus;    // available world status options
    std::vector<st_state> listStates;  // world main states (specified)
    cv::Mat matStates;   // environment states matrix (states for all own_status-world_status combinations)
    
public:
    Environment();
    ~Environment();

    // get copy of own status list
    std::set<int> getListOwnStatus() {return setOwnStatus;};
    // get copy of world status list
    std::set<int> getListWorldStatus() {return setWorldStatus;};
    // get copy of states list
    std::vector<st_state> getListStates() {return listStates;};

    // add status to own status list
    bool addOwnStatus(int ownStatus);
    // add status to world status list
    bool addWorldStatus(int worldStatus);    
    // add state to states list
    bool addState(int ownStatus, int worldStatus, int state);
    
    // clear own status list (implies clearing states matrix)
    void clearOwnStatusList();
    // clear world status list (implies clearing states matrix)
    void clearWorldStatusList();
    // clear states list (implies clearing states matrix)
    void clearStates();
            
    // build states matrix from world main states
    void buildMatrix();
    // get state for given own_status-world_status combination
    int getState4Situation(int ownStatus, int worldStatus);    
    
private:
    // clear states matrix
    void clearMatrix();
};
}

#endif
