/*
 * BaseTransactionScheduler.h
 *
 * Created on: Jun 11, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef BASETRANSACTIONSCHEDULER_H_
#define BASETRANSACTIONSCHEDULER_H_

#include "l0-infra/trans-dsl/sched/concept/TransactionScheduler.h"
#include "l0-infra/trans-dsl/sched/trans/SimpleTransactionContext.h"

TSL_NS_BEGIN

struct BaseTransactionScheduler
         : SimpleTransactionContext
         , TransactionScheduler
{
   explicit BaseTransactionScheduler(InstanceId iid = InstanceId(0));
   explicit BaseTransactionScheduler(RuntimeContext& runtimeContext, InstanceId iid = InstanceId(0));

   OVERRIDE(void updateInstanceId(InstanceId iid));
   OVERRIDE(void updateTimerInfo(const TimerInfo&));
   OVERRIDE(void updateTransactionListener(TransactionListener&));
   OVERRIDE(void updateUserContext(dci::Unknown*));
   OVERRIDE(void updateMutexScheduler(TransMutexScheduler&));

   OVERRIDE(Status stop(const Status));

private:
   ABSTRACT(Status actualStop(const Status));
   ABSTRACT(bool isWorking() const);
};

TSL_NS_END

#endif /* BASETRANSACTIONSCHEDULER_H_ */
