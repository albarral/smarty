/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "smarty/memory/StateDB.h"
#include "smarty/memory/TransitionDB.h"
#include "smarty/task/Transition.h"

namespace smarty 
{
const std::string StateDB::TABLE = "TAB_STATES";     
const std::string StateDB::colon = ",";     
const std::string StateDB::C1_TASKID = "taskID";     
const std::string StateDB::C2_STATEID = "stateID";     
const std::string StateDB::C3_REWARD = "reward";     


std::string StateDB::whereSpecificState(StatePk& statePk)
{
    return " WHERE " + C1_TASKID + " = " + std::to_string(statePk.getTaskID()) +
            " and " + C2_STATEID + " = " + std::to_string(statePk.getStateID());
}

std::string StateDB::whereSpecificTask(int taskID)
{
     return " WHERE " + C1_TASKID + " = " + std::to_string(taskID);
}

State StateDB::getState(tron::Database* pDatabase, sql::Connection* con, StatePk& statePk)
{
    std::string query = "SELECT * FROM " + TABLE + whereSpecificState(statePk);
    
    sql::ResultSet* res = pDatabase->select(query, con);
    
    // if found state, return it
    if (res->next())
    {
        State oState(statePk, res->getDouble(C3_REWARD));
        // also get its transitions
        oState.getListTransitions() = TransitionDB::getStateTransitions(pDatabase, con, statePk);
        return oState;
    }
    // otherwise return empty one
    else
    {
        State oState;
        return oState;
    }
}

bool StateDB::insertState(tron::Database* pDatabase, sql::Connection* con, State& oState)
{
    StatePk& statePk = oState.getStatePk();
    std::string query = "INSERT INTO " + TABLE +
            "(" + C1_TASKID + colon + C2_STATEID + colon + C3_REWARD + ") VALUES (" +
            std::to_string(statePk.getTaskID()) + colon +  
            std::to_string(statePk.getStateID()) + colon +             
            std::to_string(oState.getReward()) + ")";
    
    bool bok = pDatabase->update(query, con);
            
    // also insert its transitions
    if (bok)
    {
        for (Transition& oTransition : oState.getListTransitions())
            bok = TransitionDB::insertTransition(pDatabase, con, oTransition);
    }

    return bok;
}


bool StateDB::deleteState(tron::Database* pDatabase, sql::Connection* con, StatePk& statePk)
{
    std::string query = "DELETE FROM " + TABLE + whereSpecificState(statePk);
                 
    bool bok = pDatabase->update(query, con);   

     // also delete its transitions
    if (bok)
        bok = TransitionDB::deleteStateTransitions(pDatabase, con, statePk);
     
    return bok;
}


bool StateDB::updateState(tron::Database* pDatabase, sql::Connection* con, State& oState)
{
    StatePk& statePk = oState.getStatePk();
    
    bool bok = StateDB::updateStateReward(pDatabase, con, statePk, oState.getReward());   
    
    // also update its transitions
    if (bok)
    {
        for (Transition& oTransition : oState.getListTransitions())
            bok = TransitionDB::updateTransition(pDatabase, con, oTransition);
    }
    
    return bok;
}

bool StateDB::updateStateReward(tron::Database* pDatabase, sql::Connection* con, StatePk& statePk, float reward)
{
    std::string query = "UPDATE " + TABLE + 
            " SET " + C3_REWARD + " = " + std::to_string(reward)  + 
            whereSpecificState(statePk);

    return pDatabase->update(query, con);
}

std::vector<State> StateDB::getTaskStates(tron::Database* pDatabase, sql::Connection* con, int taskID)
{
    std::string query = "SELECT * FROM " + TABLE + whereSpecificTask(taskID);

    sql::ResultSet* res = pDatabase->select(query, con);
    
    std::vector<State> listStates;    
    // for each obtained State, load its transitions and add to list
    while (res->next())
    {
        StatePk statePk(taskID, res->getInt(C2_STATEID));
        State oState(statePk, res->getDouble(C3_REWARD));
        oState.getListTransitions() = TransitionDB::getStateTransitions(pDatabase, con, statePk);
        listStates.push_back(oState);
    }
    
    return listStates;
}

bool StateDB::deleteTaskStates(tron::Database* pDatabase, sql::Connection* con, int taskID)
{
    // delete states
    std::string query = "DELETE FROM " + TABLE + whereSpecificTask(taskID);

    bool bok = pDatabase->update(query, con);       
    
    // also delete the task transitions
    if (bok)
        bok = TransitionDB::deleteTaskTransitions(pDatabase, con, taskID);
    
    return bok;    
}
}