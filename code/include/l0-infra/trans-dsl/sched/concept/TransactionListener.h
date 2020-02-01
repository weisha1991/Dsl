/*
 * TransactionListener.h
 *
 * Created on: May 28, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef TRANSACTIONLISTENER_H_
#define TRANSACTIONLISTENER_H_

#include <l0-infra/base/Default.h>
#include <l0-infra/base/Status.h>
#include <l0-infra/base/dci/Role.h>
#include <l0-infra/base/Keywords.h>
#include <l0-infra/event/event.h>
#include <l0-infra/gof/Singleton.h>

#include "l0-infra/trans-dsl/sched/concept/ActionId.h"

FWD_DECL_EV(Event)

TSL_NS_BEGIN

DEFINE_ROLE(TransactionListener)
{
   DEFAULT(void, onActionStarting(const ActionId));
   DEFAULT(void, onActionStarted(const ActionId));
   DEFAULT(void, onActionEventConsumed(const ActionId, const ev::Event&));
   DEFAULT(void, onActionDone(const ActionId, const Status));

   DEFAULT(void, onActionStartStopping(const ActionId, const Status));
   DEFAULT(void, onActionStoppingStarted(const ActionId));
   DEFAULT(void, onStoppingEventConsumed(const ActionId, const ev::Event&));
   DEFAULT(void, onActionStopped(const ActionId, const Status));

   DEFAULT(void, onActionKilled(const ActionId, const Status));
};

TransactionListener& getNilTransactionListener();

DEF_SINGLETON(NilTransactionListener) EXTENDS(TransactionListener)
{
    NilTransactionListener()
    {

    }
};

TSL_NS_END

#endif /* TRANSACTIONLISTENER_H_ */
