/*
 * SchedJoinAction.h
 *
 * Created on: Apr 23, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef SCHEDJOINACTION_H_
#define SCHEDJOINACTION_H_

#include "l0-infra/trans-dsl/ext/multi-thread/concept/ActionThreadId.h"
#include "l0-infra/trans-dsl/sched/concept/SchedAction.h"
#include "l0-infra/trans-dsl/sched/def/ActionThreadDefs.h"

TSL_NS_BEGIN

struct SchedJoinAction : SchedAction
{
   SchedJoinAction();

   OVERRIDE(Status exec(TransactionContext&));
   OVERRIDE(Status handleEvent(TransactionContext&, const ev::Event&));
   OVERRIDE(Status stop(TransactionContext&, Status));
   OVERRIDE(void        kill(TransactionContext&, Status));

   Status addJoinThread(const ActionThreadId threadId);

private:
   typedef ThreadBitmapType HostType;

private:
   bool isWaiting(const ActionThreadId threadId) const;
   void addThread(const ActionThreadId threadId);
   void threadDone(const ActionThreadId threadId);

   Status reschedule();
   Status join(const ActionThreadId threadId,
            TransactionContext& context);
   Status onThreadDone(const ActionThreadId tid, const Status);

private:
   HostType joinPointBitmap;
};

TSL_NS_END

#endif /* SCHEDJOINACTION_H_ */
