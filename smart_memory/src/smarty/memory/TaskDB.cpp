/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "smarty/memory/TaskDB.h"
#include "smarty/memory/StateDB.h"
#include "smarty/task/State.h"

namespace smarty 
{
const std::string TaskDB::TABLE = "TAB_TASKS";     
const std::string TaskDB::colon = ",";     
const std::string TaskDB::C1_TASKID = "ID";     
const std::string TaskDB::C2_TASK_TYPE = "type";     
const std::string TaskDB::C3_TASK_DESC = "desc";     

std::string TaskDB::whereSpecificTask(int taskID)
{
     return " WHERE " + C1_TASKID + " = " + std::to_string(taskID);
}

Task TaskDB::getTask(tron::Database* pDatabase, sql::Connection* con, int taskID)
{
    std::string query = "SELECT * FROM " + TABLE + whereSpecificTask(taskID);
    
    sql::ResultSet* res = pDatabase->select(query, con);
    
    // if found state, return it
    if (res->next())
    {
        Task oTask(taskID, res->getInt(C2_TASK_TYPE), res->getString(C3_TASK_DESC));
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
     std::string query = "INSERT INTO " + TABLE +
            "(" + C1_TASKID + colon + C2_TASK_TYPE + colon + C3_TASK_DESC + ") VALUES (" +
            std::to_string(oTask.getID()) + colon +  
            std::to_string(oTask.getType()) + colon +             
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
    std::string query = "DELETE FROM " + TABLE + whereSpecificTask(taskID);
                 
    bool bok = pDatabase->update(query, con);   

     // also delete its states
    if (bok)
        bok = StateDB::deleteTaskStates(pDatabase, con, taskID);
     
    return bok;
}


bool TaskDB::updateTask(tron::Database* pDatabase, sql::Connection* con, Task& oTask)
{
    std::string query = "UPDATE " + TABLE + 
            " SET " + C2_TASK_TYPE + " = " + std::to_string(oTask.getType())  +
            colon + C3_TASK_DESC + " = " + oTask.getDesc()  +
            whereSpecificTask(oTask.getID());
    
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