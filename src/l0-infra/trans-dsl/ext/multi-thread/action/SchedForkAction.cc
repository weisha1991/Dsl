/*
 * SchedForkAction.cc
 *
 *  Created on: Apr 23, 2013
 *      Author: arthur
 */

#include "l0-infra/trans-dsl/ext/multi-thread/action/SchedForkAction.h"

#include <l0-infra/base/Assertions.h>
#include <l0-infra/base/dci/Unknown.h>

#include "l0-infra/trans-dsl/ext/multi-thread/concept/MultiThreadContext.h"
#include "l0-infra/trans-dsl/sched/concept/TransactionContext.h"
#include "l0-infra/trans-dsl/utils/ActionStatus.h"

TSL_NS_BEGIN

//////////////////////////////////////////////////////////////////////////////////
Status SchedForkAction::exec(TransactionContext& context)
{
   MultiThreadContext* mt = com::unknown_cast<MultiThreadContext>(&context);
   CUB_ASSERT_VALID_PTR(mt);

   Status result = TSL_SUCCESS;
   CUB_ASSERT_SUCC_CALL(mt->startThread(getThreadId(), ROLE(ActionThread), result));

   if(ActionStatus(result).isFailed())
   {
      return result;
   }

   return TSL_SUCCESS;
}

//////////////////////////////////////////////////////////////////////////////////
Status SchedForkAction::handleEvent(TransactionContext&, const ev::Event&)
{
   return TSL_UNKNOWN_EVENT;
}

//////////////////////////////////////////////////////////////////////////////////
Status SchedForkAction::stop(TransactionContext&, Status)
{
   return TSL_SUCCESS;
}

//////////////////////////////////////////////////////////////////////////////////
void   SchedForkAction::kill(TransactionContext&, Status)
{
}

TSL_NS_END

