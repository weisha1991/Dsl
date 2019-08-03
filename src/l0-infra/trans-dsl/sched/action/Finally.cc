/*
 * Finally.cc
 *
 *  Created on: Apr 22, 2013
 *      Author: arthur
 */


#include "l0-infra/trans-dsl/sched/action/Finally.h"

#include "l0-infra/trans-dsl/sched/concept/SchedAction.h"

TSL_NS_BEGIN

//////////////////////////////////////////////////////////////////////////
Status Finally::exec(TransactionContext& context)
{
   return ROLE(SchedAction).exec(context);
}

//////////////////////////////////////////////////////////////////////////
Status Finally::handleEvent(TransactionContext& context, const ev::Event& event)
{
   return ROLE(SchedAction).handleEvent(context, event);
}

//////////////////////////////////////////////////////////////////////////
void Finally::kill(TransactionContext& context, Status cause)
{
   return ROLE(SchedAction).kill(context, cause);
}

TSL_NS_END

