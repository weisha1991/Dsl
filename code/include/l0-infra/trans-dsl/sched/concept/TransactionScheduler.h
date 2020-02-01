/*
 * TransactionScheduler.h
 *
 * Created on: Jun 11, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef TRANSACTIONSCHEDULER_H_
#define TRANSACTIONSCHEDULER_H_

#include <l0-infra/base/Status.h>
#include <l0-infra/base/dci/Role.h>
#include <l0-infra/base/dci/Unknown.h>
#include <l0-infra/event/concept/Event.h>
#include "l0-infra/event/event.h"
#include "l0-infra/trans-dsl/sched/concept/InstanceId.h"

USING_EV_NS

TSL_NS_BEGIN

struct ActionThread;
struct TransactionListener;
struct TimerInfo;
struct TransMutexScheduler;
struct UserContext;


DEFINE_ROLE(TransactionScheduler)
{
   ABSTRACT(Status start(ActionThread&));
   ABSTRACT(Status handleEvent(const EV_NS::Event&));
   ABSTRACT(Status stop(const Status));
   ABSTRACT(void   kill(const Status));

   ABSTRACT(void updateInstanceId(InstanceId iid));
   ABSTRACT(void updateTimerInfo(const TimerInfo&));
   ABSTRACT(void updateTransactionListener(TransactionListener&));
   ABSTRACT(void updateUserContext(dci::Unknown*));
   ABSTRACT(void updateMutexScheduler(TransMutexScheduler&));
};

TSL_NS_END

#endif /* TRANSACTIONSCHEDULER_H_ */
