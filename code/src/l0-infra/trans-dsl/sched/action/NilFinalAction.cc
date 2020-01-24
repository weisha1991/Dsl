/*
 * NilFinalAction.cc
 *
 *  Created on: Apr 22, 2013
 *      Author: arthur
 */

#include "l0-infra/trans-dsl/sched/action/NilFinalAction.h"

#include "l0-infra/trans-dsl/sched/concept/TransactionContext.h"

TSL_NS_BEGIN

Status NilFinalAction::exec(TransactionContext&)
{
   return TSL_SUCCESS;
}

Status NilFinalAction::handleEvent(TransactionContext&, const ev::Event&)
{
   return TSL_FATAL_BUG;
}

void NilFinalAction::kill(TransactionContext&, const Status)
{
}

TSL_NS_END
