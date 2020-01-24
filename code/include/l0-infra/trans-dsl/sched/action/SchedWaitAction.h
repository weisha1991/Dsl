/*
 * SchedWaitAction.h
 *
 * Created on: Apr 22, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef SCHEDWAITACTION_H_
#define SCHEDWAITACTION_H_

#include <l0-infra/event/concept/EventId.h>

#include "l0-infra/trans-dsl/sched/concept/SchedAction.h"

TSL_NS_BEGIN

struct SchedWaitAction : SchedAction
{
   OVERRIDE(Status exec(TransactionContext&));
   OVERRIDE(Status handleEvent(TransactionContext&, const ev::Event&));
   OVERRIDE(Status stop(TransactionContext&, const Status));
   OVERRIDE(void kill(TransactionContext&, const Status));

private:
   ABSTRACT(ev::EventId getEventId() const);
};

TSL_NS_END


#endif /* SCHEDWAITACTION_H_ */
