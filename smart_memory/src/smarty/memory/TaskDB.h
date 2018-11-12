#ifndef __SMART_MEMORY_TASK_DB_H
#define __SMART_MEMORY_TASK_DB_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <vector>
#include <cppconn/connection.h>

#include "smarty/task/Task.h"
#include "tron/db/Database.h"

namespace smart 
{
class TaskDB
{
private:
    /*! table & columns */
    static const std::string TABLE;
    static const std::string colon;
    static const std::string C1_TASKID;
    static const std::string C2_TASK_TYPE;
    static const std::string C3_TASK_DESC;

public:
    //TaskDB();
    
    static Task getTask(tron::Database* pDatabase, sql::Connection* con, int taskID);
    
    static bool insertTask(tron::Database* pDatabase, sql::Connection* con, Task& oTask);
    
    static bool deleteTask(tron::Database* pDatabase, sql::Connection* con, int taskID);

    static bool updateTask(tron::Database* pDatabase, sql::Connection* con, Task& oTask);    

private:
    // builds where clause for specified task
    static std::string whereSpecificTask(int taskID);
    
};
}

#endif
