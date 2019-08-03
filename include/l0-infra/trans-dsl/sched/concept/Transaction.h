/*
 * Transaction.h
 *
 * Created on: Apr 23, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef TRANSACTION_H_
#define TRANSACTION_H_

#include <l0-infra/base/dci/Role.h>
#include <l0-infra/event/event.h>

#include "l0-infra/trans-dsl/utils/StopCause.h"

FWD_DECL_EV(Event)

TSL_NS_BEGIN

DEFINE_ROLE(Transaction)
{
   ABSTRACT(Status start());
   ABSTRACT(Status handleEvent(const ev::Event&));
   ABSTRACT(Status stop(const StopCause& = StopCause()));
   ABSTRACT(void   kill(const StopCause& = StopCause()));

   Status startWithEvent(const ev::Event&);
};

TSL_NS_END

#endif /* TRANSACTION_H_ */
