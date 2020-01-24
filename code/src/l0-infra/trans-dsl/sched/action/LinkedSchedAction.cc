/*
 * LinkedSchedAction.cc
 *
 *  Created on: Apr 22, 2013
 *      Author: arthur
 */


#include "l0-infra/trans-dsl/sched/action/LinkedSchedAction.h"

TSL_NS_BEGIN

/////////////////////////////////////////////////////////////////////////////////////////
Status LinkedSchedAction::exec(TransactionContext& context)
{
   return ROLE(SchedAction).exec(context);
}

/////////////////////////////////////////////////////////////////////////////////////////
Status LinkedSchedAction::handleEvent(TransactionContext& context, const ev::Event& event)
{
   return ROLE(SchedAction).handleEvent(context, event);
}

/////////////////////////////////////////////////////////////////////////////////////////
Status LinkedSchedAction::stop(TransactionContext& context, const Status cause)
{
   return ROLE(SchedAction).stop(context, cause);
}

/////////////////////////////////////////////////////////////////////////////////////////
void LinkedSchedAction::kill(TransactionContext& context, const Status cause)
{
   ROLE(SchedAction).kill(context, cause);
}

TSL_NS_END

