/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "smarty/learn/db/TaskDB.h"
#include "smarty/learn/db/StateDB.h"
#include "smarty/learn/State.h"

namespace smarty 
{
Task TaskDB::getTask(tron::Database* pDatabase, sql::Connection* con, int taskID)
{
    std::string query = "SELECT * FROM TAB_TASKS WHERE ID = " + std::to_string(taskID);
    
    sql::ResultSet* res = pDatabase->select(query, con);
    
    // if found state, return it
    if (res->next())
    {
        Task oTask(res->getInt("ID"), res->getInt("type"), res->getString("desc"));
        // also get its states
        oTask.getListStates() = StateDB::getTaskStates(pDatabase, con, taskID);
        return oTask;
    }
    // otherwise return empty one
    else
    {
        Task oTask;
        return oTask;
    }
}

bool TaskDB::insertTask(tron::Database* pDatabase, sql::Connection* con, Task& oTask)
{
    std::string query = "INSERT INTO TAB_TASKS (ID, type, desc) VALUES (" +
            std::to_string(oTask.getID()) + ", " +  
            std::to_string(oTask.getType()) + ", " +             
            oTask.getDesc() + ")";
    
    bool bok = pDatabase->update(query, con);
            
    // also insert its states
    if (bok)
    {
        for (State& oState : oTask.getListStates())
            bok = StateDB::insertState(pDatabase, con, oState);
    }

    return bok;
}


bool TaskDB::deleteTask(tron::Database* pDatabase, sql::Connection* con, int taskID)
{
    std::string query = "DELETE FROM TAB_TASKS WHERE ID = " + std::to_string(taskID);
                 
    bool bok = pDatabase->update(query, con);   

     // also delete its states
    if (bok)
        bok = StateDB::deleteTaskStates(pDatabase, con, taskID);
     
    return bok;
}


bool TaskDB::updateTask(tron::Database* pDatabase, sql::Connection* con, Task& oTask)
{
    std::string query = "UPDATE TAB_TASKS SET type = " + std::to_string(oTask.getType())  +
            ", desc = " + oTask.getDesc()  +
            " WHERE taskID = " + std::to_string(oTask.getID());
    
    bool bok = pDatabase->update(query, con);   
    
    // also update its states
    if (bok)
    {
        for (State& oState : oTask.getListStates())
            bok = StateDB::updateState(pDatabase, con, oState);
    }
    
    return bok;
}
}