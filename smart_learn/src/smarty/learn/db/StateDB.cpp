/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "smarty/learn/db/StateDB.h"
#include "smarty/learn/db/TransitionDB.h"
#include "smarty/learn/Transition.h"

namespace smarty 
{
State StateDB::getState(tron::Database* pDatabase, sql::Connection* con, StatePk& statePk)
{
    std::string query = "SELECT * FROM TAB_STATES WHERE taskID = " + std::to_string(statePk.getTaskID()) +
            " and stateID = " + std::to_string(statePk.getStateID());
    
    sql::ResultSet* res = pDatabase->select(query, con);
    
    // if found state, return it
    if (res->next())
    {
        State oState(statePk, res->getDouble("reward"));
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
    std::string query = "INSERT INTO TAB_STATES (taskID, stateID, reward) VALUES (" +
            std::to_string(statePk.getTaskID()) + ", " +  
            std::to_string(statePk.getStateID()) + ", " +             
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
    std::string query = "DELETE FROM TAB_STATES WHERE taskID = " + std::to_string(statePk.getTaskID()) +
            " and stateID = " + std::to_string(statePk.getStateID());
                 
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
    std::string query = "UPDATE TAB_STATES SET reward = " + std::to_string(reward)  +
            " WHERE taskID = " + std::to_string(statePk.getTaskID()) +
            " and stateID = " + std::to_string(statePk.getStateID());

    return pDatabase->update(query, con);
}

std::vector<State> StateDB::getTaskStates(tron::Database* pDatabase, sql::Connection* con, int taskID)
{
    std::string query = "SELECT * FROM TAB_STATES WHERE taskID = " + std::to_string(taskID);

    sql::ResultSet* res = pDatabase->select(query, con);
    
    std::vector<State> listStates;    
    // for each obtained State, load its transitions and add to list
    while (res->next())
    {
        StatePk statePk(taskID, res->getInt("stateID"));
        State oState(statePk, res->getDouble("reward"));
        oState.getListTransitions() = TransitionDB::getStateTransitions(pDatabase, con, statePk);
        listStates.push_back(oState);
    }
    
    return listStates;
}

bool StateDB::deleteTaskStates(tron::Database* pDatabase, sql::Connection* con, int taskID)
{
    // delete states
    std::string query = "DELETE FROM TAB_STATES WHERE taskID = " + std::to_string(taskID);
    // also delete state transitions
    std::string query2 = "DELETE FROM TAB_TRANSITIONS WHERE taskID = " + std::to_string(taskID);
                 
    bool bok = pDatabase->update(query, con);       
    
    if (bok)
        bok = pDatabase->update(query2, con);       
    
    return bok;    
}
}