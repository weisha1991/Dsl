/*
 * SchedThrowAction.cc
 *
 *  Created on: Apr 22, 2013
 *      Author: arthur
 */

#include "l0-infra/trans-dsl/sched/action/SchedThrowAction.h"

#include "l0-infra/trans-dsl/sched/concept/TransactionContext.h"
#include "l0-infra/trans-dsl/sched/concept/TransactionInfo.h"

TSL_NS_BEGIN



Status SchedThrowAction::exec(TransactionContext& context)
{
   return getStatus() == TSL_RESERVED_FAILURE ? context.getTransactionInfo().getStatus() : getStatus();
}

////////////////////////////////////////////////////////////////////////
Status SchedThrowAction::handleEvent(TransactionContext&, const ev::Event&)
{
   return TSL_FATAL_BUG;
}

////////////////////////////////////////////////////////////////////////
Status SchedThrowAction::stop(TransactionContext&, const Status)
{
   return TSL_FATAL_BUG;
}

////////////////////////////////////////////////////////////////////////
void SchedThrowAction::kill(TransactionContext&, const Status)
{
}

TSL_NS_END

