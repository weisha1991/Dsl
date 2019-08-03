/*
 * SchedLockAction.h
 *
 * Created on: Aug 7, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef SCHEDLOCKACTION_H_
#define SCHEDLOCKACTION_H_

#include "l0-infra/trans-dsl/ext/mutex/concept/TransMutextId.h"
#include "l0-infra/trans-dsl/sched/concept/SchedAction.h"

TSL_NS_BEGIN

struct SchedLockAction : SchedAction
{
   SchedLockAction();

   OVERRIDE(Status exec(TransactionContext&));
   OVERRIDE(Status handleEvent(TransactionContext&, const ev::Event&));
   OVERRIDE(Status stop(TransactionContext&, Status));
   OVERRIDE(void   kill(TransactionContext&, Status));

private:
   Status final(Status, TransactionContext&);
   Status lock(TransactionContext&);
   Status unlock(TransactionContext&);
   Status tryExec(TransactionContext&, const ev::Event&);

private:
   bool waiting;

private:
   USE_ROLE(SchedAction);
   ABSTRACT(TransMutexId getMutexId() const);
};

TSL_NS_END

#endif /* SCHEDLOCKACTION_H_ */
