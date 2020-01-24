/*
 * SimpleRuntimeContext.cc
 *
 *  Created on: Apr 22, 2013
 *      Author: arthur
 */

#include "../include/l0-infra/trans-dsl/utils/SimpleRuntimeContext.h"

#include "../include/l0-infra/trans-dsl/utils/ActionStatus.h"

TSL_NS_BEGIN



////////////////////////////////////////////////////////////////
SimpleRuntimeContext::SimpleRuntimeContext(Status parentStatus)
  : parent(0)
  , objectStatus(parentStatus)
{
}

////////////////////////////////////////////////////////////////
void SimpleRuntimeContext::reportFailure(Status failure)
{
   if(!ActionStatus(failure).isFailed())
   {
      return;
   }

   objectStatus = failure;


   if(shouldReportParent() && parent != 0)
   {
      parent->reportFailure(failure);
   }
}

////////////////////////////////////////////////////////////////
Status SimpleRuntimeContext::getStatus() const
{
   return objectStatus;
}

TSL_NS_END
