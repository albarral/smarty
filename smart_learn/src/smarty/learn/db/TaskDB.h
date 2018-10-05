#ifndef __SMARTY_LEARN_TASK_DB_H
#define __SMARTY_LEARN_TASK_DB_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <vector>
#include <cppconn/connection.h>

#include "smarty/learn/Task.h"
#include "tron/db/Database.h"

namespace smarty 
{
class TaskDB
{
public:
    //TaskDB();
    
    static Task getTask(tron::Database* pDatabase, sql::Connection* con, int taskID);
    
    static bool insertTask(tron::Database* pDatabase, sql::Connection* con, Task& oTask);
    
    static bool deleteTask(tron::Database* pDatabase, sql::Connection* con, int taskID);

    static bool updateTask(tron::Database* pDatabase, sql::Connection* con, Task& oTask);    
};
}

#endif
