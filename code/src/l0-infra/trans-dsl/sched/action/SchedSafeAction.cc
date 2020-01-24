/*
 * SchedSafeAction.cc
 *
 * Created on: May 28, 2013, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#include "l0-infra/trans-dsl/sched/action/SchedSafeAction.h"

#include "l0-infra/trans-dsl/utils/ActionStatus.h"

TSL_NS_BEGIN

/////////////////////////////////////////////////////////////////////////////////
SchedSafeAction::SchedSafeAction()
   : running(false)
{
}

/////////////////////////////////////////////////////////////////////////////////
Status SchedSafeAction::final(const Status status)
{
    running = ActionStatus(status).isWorking();

    return status;
}

/////////////////////////////////////////////////////////////////////////////////
Status SchedSafeAction::exec(TransactionContext& context)
{
   if(running) return TSL_CONTINUE;

   return final(ROLE(SchedAction).exec(context));
}

/////////////////////////////////////////////////////////////////////////////////
Status SchedSafeAction::handleEvent(TransactionContext& context, const ev::Event& event)
{
   if(!running) return TSL_UNKNOWN_EVENT;

   return final(ROLE(SchedAction).handleEvent(context, event));
}

/////////////////////////////////////////////////////////////////////////////////
Status SchedSafeAction::stop(TransactionContext&, Status)
{
   return running ? TSL_CONTINUE : TSL_SUCCESS;
}

/////////////////////////////////////////////////////////////////////////////////
void SchedSafeAction::kill(TransactionContext& context, Status cause)
{
   if(running) ROLE(SchedAction).kill(context, cause);
}

TSL_NS_END
