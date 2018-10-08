#ifndef __SMARTY_LEARN_TRANSITION_DB_H
#define __SMARTY_LEARN_TRANSITION_DB_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <vector>
#include <cppconn/connection.h>

#include "smarty/learn/Transition.h"
#include "smarty/learn/TransitionPk.h"
#include "smarty/learn/StatePk.h"
#include "tron/db/Database.h"

namespace smarty 
{
class TransitionDB
{  
private:
    /*! table & columns */
    static const std::string TABLE;
    static const std::string colon;
    static const std::string C1_TASKID;
    static const std::string C2_STATEID;
    static const std::string C3_TRANSID;
    static const std::string C4_NEXTSTATE;
    static const std::string C5_Q;
    
public:
    //TransitionDB();
    
    static Transition getTransition(tron::Database* pDatabase, sql::Connection* con, TransitionPk& transitionPk);
    
    static bool insertTransition(tron::Database* pDatabase, sql::Connection* con, Transition& oTransition);
    
    static bool deleteTransition(tron::Database* pDatabase, sql::Connection* con, TransitionPk& transitionPk);

    static bool updateTransition(tron::Database* pDatabase, sql::Connection* con, Transition& oTransition);
        
    static bool updateTransitionQValue(tron::Database* pDatabase, sql::Connection* con, TransitionPk& transitionPk, float q);
    
    static std::vector<Transition> getStateTransitions(tron::Database* pDatabase, sql::Connection* con, StatePk& statePk);

    static bool deleteStateTransitions(tron::Database* pDatabase, sql::Connection* con, StatePk& statePk);

    static bool deleteTaskTransitions(tron::Database* pDatabase, sql::Connection* con, int taskID);
    
private:
    // builds where clause for specified transition
    static std::string whereSpecificTransition(TransitionPk& transitionPk);
    // builds where clause for specified state
    static std::string whereSpecificState(StatePk& statePk);
};
}

#endif
