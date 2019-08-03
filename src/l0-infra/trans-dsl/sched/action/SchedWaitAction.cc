/*
 * SchedWaitAction.cc
 *
 *  Created on: Apr 22, 2013
 *      Author: arthur
 */

#include "l0-infra/trans-dsl/sched/action/SchedWaitAction.h"

#include <l0-infra/event/concept/Event.h>

TSL_NS_BEGIN



////////////////////////////////////////////////////////////////////////////////////
Status SchedWaitAction::exec(TransactionContext&)
{
   return TSL_CONTINUE;
}

////////////////////////////////////////////////////////////////////////////////////
Status SchedWaitAction::handleEvent(TransactionContext&, const ev::Event& event)
{
   if(event.matches(getEventId()))
   {
      event.consume();
      return TSL_SUCCESS;
   }

   return TSL_UNKNOWN_EVENT;
}

////////////////////////////////////////////////////////////////////////////////////
Status SchedWaitAction::stop(TransactionContext&, const Status cause)
{
   return cause;
}

////////////////////////////////////////////////////////////////////////////////////
void SchedWaitAction::kill(TransactionContext&, const Status)
{
}

TSL_NS_END

