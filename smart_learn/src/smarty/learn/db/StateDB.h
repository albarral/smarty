#ifndef __SMARTY_LEARN_STATE_DB_H
#define __SMARTY_LEARN_STATE_DB_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <vector>
#include <cppconn/connection.h>

#include "smarty/learn/State.h"
#include "smarty/learn/StatePk.h"
#include "tron/db/Database.h"

namespace smarty 
{
class StateDB
{
private:
    /*! table & columns */
    static const std::string TABLE;
    static const std::string colon;
    static const std::string C1_TASKID;
    static const std::string C2_STATEID;
    static const std::string C3_REWARD;

public:
    //StateDB();

    static State getState(tron::Database* pDatabase, sql::Connection* con, StatePk& statePk);
    
    static bool insertState(tron::Database* pDatabase, sql::Connection* con, State& oState);
    
    static bool deleteState(tron::Database* pDatabase, sql::Connection* con, StatePk& statePk);

    static bool updateState(tron::Database* pDatabase, sql::Connection* con, State& oState);    
    
    static bool updateStateReward(tron::Database* pDatabase, sql::Connection* con, StatePk& statePk, float reward);
    
    static std::vector<State> getTaskStates(tron::Database* pDatabase, sql::Connection* con, int taskID);

    static bool deleteTaskStates(tron::Database* pDatabase, sql::Connection* con, int taskID);
    
private:
    // builds where clause for specified state
    static std::string whereSpecificState(StatePk& statePk);
    // builds where clause for specified task
    static std::string whereSpecificTask(int taskID);
    
};
}

#endif
