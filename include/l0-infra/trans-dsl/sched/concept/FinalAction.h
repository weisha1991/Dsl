/*
 * FinalAction.h
 *
 * Created on: Apr 22, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef FINALACTION_H_
#define FINALACTION_H_

#include "l0-infra/event/event.h"
#include "l0-infra/base/dci/Role.h"

#include "l0-infra/trans-dsl/tsl.h"
#include "l0-infra/trans-dsl/TslStatus.h"

FWD_DECL_EV(Event);

TSL_NS_BEGIN

struct TransactionContext;

DEFINE_ROLE(FinalAction)
{
   ABSTRACT(Status exec(TransactionContext&));
   ABSTRACT(Status handleEvent(TransactionContext&, const ev::Event&));
   ABSTRACT(void   kill(TransactionContext&, const Status));
};

TSL_NS_END

#endif /* FINALACTION_H_ */
