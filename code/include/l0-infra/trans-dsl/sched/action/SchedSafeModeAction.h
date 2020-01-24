/*
 * SchedSafeModeAction.h
 *
 * Created on: Jun 10, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef SCHEDSAFEMODEACTION_H_
#define SCHEDSAFEMODEACTION_H_

#include "l0-infra/trans-dsl/sched/concept/SchedAction.h"

TSL_NS_BEGIN

struct SchedSafeModeAction : SchedAction
{
   OVERRIDE(Status exec(TransactionContext&));
   OVERRIDE(Status handleEvent(TransactionContext&, const ev::Event&));
   OVERRIDE(Status stop(TransactionContext&, const Status));
   OVERRIDE(void kill(TransactionContext&, const Status));

private:
   Status final(TransactionContext& context, Status status);

private:
   USE_ROLE(SchedAction);
};

TSL_NS_END

#endif /* SCHEDSAFEMODEACTION_H_ */
