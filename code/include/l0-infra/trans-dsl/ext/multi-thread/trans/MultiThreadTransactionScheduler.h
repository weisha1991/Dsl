/*
 * MultiThreadTransactionScheduler.h
 *
 * Created on: Jun 11, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef MULTITHREADTRANSACTIONSCHEDULER_H_
#define MULTITHREADTRANSACTIONSCHEDULER_H_

#include "l0-infra/trans-dsl/ext/multi-thread/trans/MultiThreadScheduler.h"
#include "l0-infra/trans-dsl/sched/trans/BaseTransactionScheduler.h"

TSL_NS_BEGIN

struct MultiThreadTransactionScheduler
   : MultiThreadScheduler
   , BaseTransactionScheduler
{
   explicit MultiThreadTransactionScheduler(const InstanceId iid = InstanceId(0));

   OVERRIDE(Status start(ActionThread&));
   OVERRIDE(Status handleEvent(const ev::Event&));
   OVERRIDE(void   kill(const Status));

private:
   OVERRIDE(Status actualStop(const Status));
   OVERRIDE(bool isWorking() const);

private:
   IMPL_ROLE(TransactionContext);

   APPEND_INTERFACE_TABLE(BaseTransactionScheduler)
      __HAS_INTERFACE(MultiThreadContext)
   END_INTERFACE_TABLE()
};

TSL_NS_END

#endif /* MULTITHREADTRANSACTIONSCHEDULER_H_ */
