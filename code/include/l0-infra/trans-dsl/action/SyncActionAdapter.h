/*
 * SyncActionAdapter.h
 *
 * Created on: Apr 24, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef SYNCACTIONADAPTER_H_
#define SYNCACTIONADAPTER_H_

#include "l0-infra/trans-dsl/action/Action.h"

TSL_NS_BEGIN

struct SyncActionAdapter: Action
{
private:
   OVERRIDE(Status exec(const TransactionInfo&));
   OVERRIDE(Status handleEvent(const TransactionInfo&, const ev::Event&));
   OVERRIDE(void   kill(const TransactionInfo&, const Status cause));

private:
   USE_ROLE(SyncAction);
};

TSL_NS_END

#endif /* SYNCACTIONADAPTER_H_ */
