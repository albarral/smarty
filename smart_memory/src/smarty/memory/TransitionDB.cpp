/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "smarty/memory/TransitionDB.h"

namespace smart 
{
const std::string TransitionDB::TABLE = "TAB_TRANSITIONS";     
const std::string TransitionDB::colon = ",";     
const std::string TransitionDB::C1_TASKID = "taskID";     
const std::string TransitionDB::C2_STATEID = "stateID";     
const std::string TransitionDB::C3_TRANSID = "transID";     
const std::string TransitionDB::C4_NEXTSTATE = "nextState";     
const std::string TransitionDB::C5_Q = "Q";     


std::string TransitionDB::whereSpecificTransition(TransitionPk& transitionPk)
{
    StatePk& statePk = transitionPk.getStatePk();   
     return " WHERE " + C1_TASKID + " = " + std::to_string(statePk.getTaskID()) +
            " and " + C2_STATEID + " = " + std::to_string(statePk.getStateID());
            " and " + C3_TRANSID + "= " + std::to_string(transitionPk.getTransitionID());    
}

std::string TransitionDB::whereSpecificState(StatePk& statePk)
{
    return " WHERE " + C1_TASKID + " = " + std::to_string(statePk.getTaskID()) +
            " and " + C2_STATEID + " = " + std::to_string(statePk.getStateID());
}

Transition TransitionDB::getTransition(tron::Database* pDatabase, sql::Connection* con, TransitionPk& transitionPk)
{
    std::string query = "SELECT * FROM " + TABLE + whereSpecificTransition(transitionPk);
    
    sql::ResultSet* res = pDatabase->select(query, con);
    
    // if found transition, return it
    if (res->next())
    {
        Transition oTransition(transitionPk, res->getInt(C4_NEXTSTATE), res->getDouble(C5_Q));
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
    StatePk& statePk = transitionPk.getStatePk();   
    std::string query = "INSERT INTO " + TABLE +
            "(" + C1_TASKID + colon + C2_STATEID + colon + C3_TRANSID + colon + C4_NEXTSTATE + colon + C5_Q + ") VALUES (" +
            std::to_string(statePk.getTaskID()) + colon +  
            std::to_string(statePk.getStateID()) + colon +             
            std::to_string(transitionPk.getTransitionID()) + colon + 
            std::to_string(oTransition.getNextState()) + colon +
            std::to_string(oTransition.getQ()) + ")";
    
    return pDatabase->update(query, con);
}

bool TransitionDB::deleteTransition(tron::Database* pDatabase, sql::Connection* con, TransitionPk& transitionPk)
{
    std::string query = "DELETE FROM " + TABLE + whereSpecificTransition(transitionPk);
            
     return pDatabase->update(query, con);   
}

bool TransitionDB::updateTransition(tron::Database* pDatabase, sql::Connection* con, Transition& oTransition)
{
    TransitionPk& transitionPk = oTransition.getTransitionPk();
    std::string query = "UPDATE " + TABLE + 
            " SET " + C4_NEXTSTATE + " = " + std::to_string(oTransition.getNextState())  +
            colon + C5_Q + " = " + std::to_string(oTransition.getQ())  +
            whereSpecificTransition(transitionPk);
    
    return pDatabase->update(query, con);
}

bool TransitionDB::updateTransitionQValue(tron::Database* pDatabase, sql::Connection* con, TransitionPk& transitionPk, float q)
{
    std::string query = "UPDATE " + TABLE + 
            " SET " + C5_Q + " = " + std::to_string(q)  + 
            whereSpecificTransition(transitionPk);
    
    return pDatabase->update(query, con);
}

std::vector<Transition> TransitionDB::getStateTransitions(tron::Database* pDatabase, sql::Connection* con, StatePk& statePk)
{
    std::string query = "SELECT * FROM " + TABLE + whereSpecificState(statePk);

    sql::ResultSet* res = pDatabase->select(query, con);
    
    std::vector<Transition> listTransitions;    
    while (res->next())
    {
        TransitionPk transitionPk(statePk, res->getInt(C3_TRANSID));
        Transition oTransition(transitionPk, res->getInt(C4_NEXTSTATE), res->getDouble(C5_Q));
        listTransitions.push_back(oTransition);
    }
    
    return listTransitions;
}


bool TransitionDB::deleteStateTransitions(tron::Database* pDatabase, sql::Connection* con, StatePk& statePk)
{
    std::string query = "DELETE FROM " + TABLE + whereSpecificState(statePk);
            
     return pDatabase->update(query, con);       
}

bool TransitionDB::deleteTaskTransitions(tron::Database* pDatabase, sql::Connection* con, int taskID)
{
    std::string query = "DELETE FROM " + TABLE + " WHERE " + C1_TASKID + " = " + std::to_string(taskID);
            
     return pDatabase->update(query, con);       
}

}