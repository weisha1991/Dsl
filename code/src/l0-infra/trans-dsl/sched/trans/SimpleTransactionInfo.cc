/*
 * SimpleTransactionInfo.cc
 *
 *  Created on: Apr 23, 2013
 *      Author: arthur
 */

#include"l0-infra/trans-dsl/sched/trans/SimpleTransactionInfo.h"

#include <l0-infra/base/log/log.h>

#include"l0-infra/trans-dsl/sched/concept/RuntimeContext.h"
#include"l0-infra/trans-dsl/sched/concept/RuntimeContextInfo.h"
#include"l0-infra/trans-dsl/utils/ActionStatus.h"

TSL_NS_BEGIN

/////////////////////////////////////////////////////////////////
SimpleTransactionInfo::SimpleTransactionInfo(InstanceId iid)
  : iid(iid)
{
}

/////////////////////////////////////////////////////////////////
InstanceId SimpleTransactionInfo::getInstanceId() const
{
   return iid;
}

void SimpleTransactionInfo::updateInstanceId(InstanceId iid)
{
   this->iid = iid;
}

/////////////////////////////////////////////////////////////////
Status SimpleTransactionInfo::getStatus() const
{
   RuntimeContext* context = ROLE(RuntimeContextInfo).getRuntimeContext();
   if(context == 0)
   {
      return TSL_SUCCESS;
   }

   if(ActionStatus(context->getStatus()).isFailed())
   {
      return context->getStatus();
   }

   return TSL_SUCCESS;
}

/////////////////////////////////////////////////////////////////
com::Unknown* SimpleTransactionInfo::getUserContext() const
{
   return userContext;
}

/////////////////////////////////////////////////////////////////
void SimpleTransactionInfo::updateUserContext(com::Unknown* userContext)
{
   this->userContext = userContext;
}

TSL_NS_END

