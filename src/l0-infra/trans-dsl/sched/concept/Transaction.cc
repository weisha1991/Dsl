/*
 * Transaction.cc
 *
 *  Created on: Apr 23, 2013
 *      Author: arthur
 */

#include "l0-infra/trans-dsl/sched/concept/Transaction.h"

#include "l0-infra/trans-dsl/utils/ActionStatus.h"

TSL_NS_BEGIN

Status Transaction::startWithEvent(const ev::Event& event)
{
   ActionStatus status = start();
   if(!status.isWorking())
   {
      return status;
   }

   return handleEvent(event);
}

TSL_NS_END

