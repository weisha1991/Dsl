/*
 * SchedSleepAction.h
 *
 * Created on: Apr 29, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef SCHEDSLEEPACTION_H_
#define SCHEDSLEEPACTION_H_

#include "l0-infra/trans-dsl/sched/concept/SchedAction.h"

TSL_NS_BEGIN

struct RelativeTimer;

struct SchedSleepAction : SchedAction
{
   OVERRIDE(Status exec(TransactionContext&));
   OVERRIDE(Status handleEvent(TransactionContext&, const ev::Event&));
   OVERRIDE(Status stop(TransactionContext&, const Status));
   OVERRIDE(void kill(TransactionContext&, const Status));

private:
   USE_ROLE(RelativeTimer);
};

TSL_NS_END

#endif /* SCHEDSLEEPACTION_H_ */
