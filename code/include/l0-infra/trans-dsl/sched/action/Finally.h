/*
 * Finally.h
 *
 * Created on: Apr 22, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef FINALLY_H_
#define FINALLY_H_

#include "l0-infra/trans-dsl/sched/concept/FinalAction.h"

TSL_NS_BEGIN

struct SchedAction;

struct Finally : FinalAction
{
   OVERRIDE(Status exec(TransactionContext&));
   OVERRIDE(Status handleEvent(TransactionContext&, const ev::Event&));
   OVERRIDE(void   kill(TransactionContext&, const Status));

private:
   USE_ROLE(SchedAction);
};

TSL_NS_END

#endif /* FINALLY_H_ */
