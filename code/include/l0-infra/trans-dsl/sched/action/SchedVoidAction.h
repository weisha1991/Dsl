/*
 * SchedVoidAction.h
 *
 * Created on: Apr 22, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef SCHEDVOIDACTION_H_
#define SCHEDVOIDACTION_H_

#include "l0-infra/trans-dsl/sched/concept/SchedAction.h"

TSL_NS_BEGIN

struct SchedVoidAction : SchedAction
{
   OVERRIDE(Status exec(TransactionContext&));
   OVERRIDE(Status handleEvent(TransactionContext&, const ev::Event&));
   OVERRIDE(Status stop(TransactionContext&, const Status));
   OVERRIDE(void   kill(TransactionContext&, const Status));

private:
   USE_ROLE(SchedAction);
};

TSL_NS_END

#endif /* SCHEDVOIDACTION_H_ */
