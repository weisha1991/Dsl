/*
 * SchedExclusiveAction.h
 *
 * Created on: Apr 28, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef SCHEDEXCLUSIVEACTION_H_
#define SCHEDEXCLUSIVEACTION_H_

#include "l0-infra/repo/list/List.h"

#include "l0-infra/trans-dsl/sched/action/LinkedSchedAction.h"
#include "l0-infra/trans-dsl/sched/concept/SchedAction.h"

TSL_NS_BEGIN

struct SchedExclusiveAction : SchedAction
{
   SchedExclusiveAction();

   OVERRIDE(Status exec(TransactionContext&));
   OVERRIDE(Status handleEvent(TransactionContext&, const ev::Event&));
   OVERRIDE(Status stop(TransactionContext&, const Status));
   OVERRIDE(void   kill(TransactionContext&, const Status));

   void addAction(LinkedSchedAction&);

private:
   Status selectAction(TransactionContext&, const ev::Event&);
   void interruptOthers(TransactionContext&);

private:
   typedef List<LinkedSchedAction> Actions;

   Actions actions;
   SchedAction* selectedAction;
};

TSL_NS_END

#endif /* SCHEDEXCLUSIVEACTION_H_ */
