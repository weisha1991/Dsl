/*
 * NilFinalAction.h
 *
 * Created on: Apr 22, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef NILFINALACTION_H_
#define NILFINALACTION_H_

#include "l0-infra/trans-dsl/sched/concept/FinalAction.h"

TSL_NS_BEGIN

struct NilFinalAction : FinalAction
{
   OVERRIDE(Status exec(TransactionContext&));
   OVERRIDE(Status handleEvent(TransactionContext&, const ev::Event&));
   OVERRIDE(void   kill(TransactionContext&, const Status));
};

TSL_NS_END

#endif /* NILFINALACTION_H_ */
