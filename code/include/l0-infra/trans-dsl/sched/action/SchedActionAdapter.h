/*
 * SchedActionAdapter.h
 *
 * Created on: Apr 24, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef SCHEDACTIONADAPTER_H_
#define SCHEDACTIONADAPTER_H_

#include "l0-infra/base/dci/Role.h"
#include "l0-infra/trans-dsl/sched/concept/SchedAction.h"
#include "l0-infra/base/Keywords.h"

TSL_NS_BEGIN

struct Action;

///////////////////////////////////////////////////////////////
struct SchedActionAdapter: SchedAction
{
   OVERRIDE(Status exec(TransactionContext&));
   OVERRIDE(Status handleEvent(TransactionContext&, const ev::Event&));
   OVERRIDE(Status stop(TransactionContext&, const Status));
   OVERRIDE(void kill(TransactionContext&, const Status));

private:
   USE_ROLE(Action);
};

TSL_NS_END

#endif /* SCHEDACTIONADAPTER_H_ */
