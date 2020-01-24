/*
 * SimpleTransactionScheduler.h
 *
 * Created on: Apr 23, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */

#ifndef SIMPLETRANSACTIONSCHEDULER_H_
#define SIMPLETRANSACTIONSCHEDULER_H_

#include "l0-infra/trans-dsl/sched/trans/BaseTransactionScheduler.h"
#include "l0-infra/trans-dsl/sched/trans/SimpleTransactionContext.h"

TSL_NS_BEGIN

struct SimpleTransactionScheduler
   : BaseTransactionScheduler
{
   explicit SimpleTransactionScheduler(InstanceId iid = 0);
   explicit SimpleTransactionScheduler(RuntimeContext& runtimeContext, InstanceId iid = 0);

   OVERRIDE(Status start(ActionThread&));
   OVERRIDE(Status handleEvent(const Event&));
   OVERRIDE(void   kill(const Status));

private:
   OVERRIDE(Status actualStop(const Status));
   OVERRIDE(bool isWorking() const);

private:
   ActionThread* thread;
};

TSL_NS_END

#endif /* SIMPLETRANSACTIONSCHEDULER_H_ */
