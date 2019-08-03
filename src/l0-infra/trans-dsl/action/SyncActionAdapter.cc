/*
 * SyncActionAdapter.cc
 *
 *  Created on: Apr 24, 2013
 *      Author: arthur
 */

#include "l0-infra/trans-dsl/action/SyncActionAdapter.h"

#include "l0-infra/base/dci/Role.h"
#include "l0-infra/trans-dsl/TslStatus.h"
#include "l0-infra/trans-dsl/utils/ActionStatus.h"

TSL_NS_BEGIN

///////////////////////////////////////////////////////
Status SyncActionAdapter::exec(const TransactionInfo& trans)
{
   ActionStatus status = ROLE(SyncAction).exec(trans);
   if(status.isWorking())
   {
      return TSL_FATAL_BUG;
   }

   return status;
}

//////////////////////////////////////////////////////////////////////
Status SyncActionAdapter::handleEvent(const TransactionInfo&, const ev::Event&)
{
   return TSL_UNKNOWN_EVENT;
}

///////////////////////////////////////////////////////
void SyncActionAdapter::kill(const TransactionInfo&, const Status)
{
}

TSL_NS_END

