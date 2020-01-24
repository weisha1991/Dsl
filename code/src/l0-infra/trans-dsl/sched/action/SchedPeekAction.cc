/*
 * SchedPeekAction.cc
 *
 *  Created on: Apr 28, 2013
 *      Author: arthur
 */

#include "l0-infra/trans-dsl/sched/action/SchedPeekAction.h"

#include "l0-infra/event/concept/Event.h"

TSL_NS_BEGIN



////////////////////////////////////////////////////////////////////////
Status SchedPeekAction::exec(TransactionContext&)
{
   return TSL_CONTINUE;
}

////////////////////////////////////////////////////////////////////////
Status SchedPeekAction::handleEvent(TransactionContext&, const ev::Event& event)
{
   if(event.matches(getEventId()))
   {
      return TSL_SUCCESS;
   }

   return TSL_UNKNOWN_EVENT;
}

////////////////////////////////////////////////////////////////////////
Status SchedPeekAction::stop(TransactionContext&, const Status cause)
{
   return cause;
}

////////////////////////////////////////////////////////////////////////
void SchedPeekAction::kill(TransactionContext&, const Status)
{
}

TSL_NS_END
