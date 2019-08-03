/*
 * SimpleTransaction.h
 *
 * Created on: Apr 24, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef SIMPLETRANSACTION_H_
#define SIMPLETRANSACTION_H_

#include "l0-infra/trans-dsl/sched/trans/SchedulerBasedTransaction.h"
#include "l0-infra/trans-dsl/sched/trans/SimpleTransactionScheduler.h"
#include "l0-infra/trans-dsl/tsl.h"

TSL_NS_BEGIN

using SimpleTransaction =  SchedulerBasedTransaction<SimpleTransactionScheduler>;
//typedef SchedulerBasedTransaction<SimpleTransactionScheduler> BBTrans;

TSL_NS_END

#endif /* SIMPLETRANSACTION_H_ */
