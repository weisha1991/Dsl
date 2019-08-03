/*
 * UserActionListener.h
 *
 * Created on: May 28, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef USERACTIONLISTENER_H_
#define USERACTIONLISTENER_H_

#include <l0-infra/base/Status.h>
#include <l0-infra/event/event.h>

#include "l0-infra/trans-dsl/sched/concept/ActionId.h"

FWD_DECL_EV(Event)

TSL_NS_BEGIN

DEFINE_ROLE(UserActionListener)
{
   DEFAULT(void, onActionStarting(const ActionId));
   DEFAULT(void, onActionStarted(const ActionId));
   DEFAULT(void, onActionEventConsumed(const ActionId, const ev::Event&));
   DEFAULT(void, onActionDone(const ActionId, const Status));

   DEFAULT(void, onActionKilled(const ActionId, const Status));
};

TSL_NS_END

#endif /* USERACTIONLISTENER_H_ */
