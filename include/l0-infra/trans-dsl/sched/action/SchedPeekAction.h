/*
 * SchedPeekAction.h
 *
 * Created on: Apr 28, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef SCHEDPEEKACTION_H_
#define SCHEDPEEKACTION_H_

#include "l0-infra/trans-dsl/sched/concept/SchedAction.h"
#include "l0-infra/event/concept/EventId.h"

TSL_NS_BEGIN

struct SchedPeekAction : SchedAction
{
   OVERRIDE(Status exec(TransactionContext&));
   OVERRIDE(Status handleEvent(TransactionContext&, const ev::Event&));
   OVERRIDE(Status stop(TransactionContext&, const Status));
   OVERRIDE(void kill(TransactionContext&, const Status));

private:
   ABSTRACT(ev::EventId getEventId() const);
};

TSL_NS_END

#endif /* SCHEDPEEKACTION_H_ */
