/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "smarty/learn/db/TransitionDB.h"

namespace smarty 
{
Transition TransitionDB::getTransition(tron::Database* pDatabase, sql::Connection* con, TransitionPk& transitionPk)
{
    std::string query = "SELECT * FROM TAB_TRANSITIONS WHERE taskID = " + std::to_string(transitionPk.getStatePk().getTaskID()) +
            " and stateID = " + std::to_string(transitionPk.getStatePk().getStateID()) +
            " and transID = " + std::to_string(transitionPk.getTransitionID());
    
    sql::ResultSet* res = pDatabase->select(query, con);
    
    // if found transition, return it
    if (res->next())
    {
        Transition oTransition(transitionPk, res->getInt("nextState"), res->getDouble("Q"));
        return oTransition;
    }
    // otherwise return empty one
    else
    {
        Transition oTransition;
        return oTransition;
    }
}

bool TransitionDB::insertTransition(tron::Database* pDatabase, sql::Connection* con, Transition& oTransition)
{
    TransitionPk& transitionPk = oTransition.getTransitionPk();
    std::string query = "INSERT INTO TAB_TRANSITIONS (taskID, stateID, transID, nextState, Q) VALUES (" +
            std::to_string(transitionPk.getStatePk().getTaskID()) + ", " +  
            std::to_string(transitionPk.getStatePk().getStateID()) + ", " +             
            std::to_string(transitionPk.getTransitionID()) + ", " + 
            std::to_string(oTransition.getNextState()) + ", " +
            std::to_string(oTransition.getQ()) + ")";
    
    return pDatabase->update(query, con);
}

bool TransitionDB::deleteTransition(tron::Database* pDatabase, sql::Connection* con, TransitionPk& transitionPk)
{
    std::string deleteDB = "DELETE FROM TAB_TRANSITIONS WHERE taskID = " + std::to_string(transitionPk.getStatePk().getTaskID()) +
            " and stateID = " + std::to_string(transitionPk.getStatePk().getStateID()) +
            " and transID = " + std::to_string(transitionPk.getTransitionID());
            
     return pDatabase->update(deleteDB, con);   
}

bool TransitionDB::updateTransition(tron::Database* pDatabase, sql::Connection* con, Transition& oTransition)
{
    TransitionPk& transitionPk = oTransition.getTransitionPk();
    std::string query = "UPDATE TAB_TRANSITIONS SET nextState = " + std::to_string(oTransition.getNextState()) + 
            ", Q = " + std::to_string(oTransition.getQ())  +
            " WHERE taskID = " + std::to_string(transitionPk.getStatePk().getTaskID()) +
            " and stateID = " + std::to_string(transitionPk.getStatePk().getStateID()) +
            " and transID = " + std::to_string(transitionPk.getTransitionID());

    return pDatabase->update(query, con);
}

bool TransitionDB::updateTransitionQValue(tron::Database* pDatabase, sql::Connection* con, TransitionPk& transitionPk, float q)
{
    std::string query = "UPDATE TAB_TRANSITIONS SET Q = " + std::to_string(q)  +
            " WHERE taskID = " + std::to_string(transitionPk.getStatePk().getTaskID()) +
            " and stateID = " + std::to_string(transitionPk.getStatePk().getStateID()) +
            " and transID = " + std::to_string(transitionPk.getTransitionID());

    return pDatabase->update(query, con);
}

std::vector<Transition> TransitionDB::getStateTransitions(tron::Database* pDatabase, sql::Connection* con, StatePk& statePk)
{
    std::string query = "SELECT * FROM TAB_TRANSITIONS WHERE taskID = " + std::to_string(statePk.getTaskID()) +
            " and stateID = " + std::to_string(statePk.getStateID());

    sql::ResultSet* res = pDatabase->select(query, con);
    
    std::vector<Transition> listTransitions;    
    while (res->next())
    {
        TransitionPk transitionPk(statePk, res->getInt("transID"));
        Transition oTransition(transitionPk, res->getInt("nextState"), res->getDouble("Q"));
        listTransitions.push_back(oTransition);
    }
    
    return listTransitions;
}


bool TransitionDB::deleteStateTransitions(tron::Database* pDatabase, sql::Connection* con, StatePk& statePk)
{
    std::string query = "DELETE FROM TAB_TRANSITIONS WHERE taskID = " + std::to_string(statePk.getTaskID()) +
            " and stateID = " + std::to_string(statePk.getStateID());
            
     return pDatabase->update(query, con);       
}

}