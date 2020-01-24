/*
 * SimpleAsyncAction.h
 *
 * Created on: Apr 29, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef SIMPLEASYNCACTION_H_
#define SIMPLEASYNCACTION_H_

#include "l0-infra/trans-dsl/action/Action.h"
#include "l0-infra/trans-dsl/utils/EventHandlerRegistry.h"

TSL_NS_BEGIN

struct SimpleAsyncAction: Action
{
   OVERRIDE(Status handleEvent(const TransactionInfo&, const ev::Event&));
   OVERRIDE(void kill(const TransactionInfo&, const Status));

   template<typename T>
   Status waitOn(const ev::EventId eventId, T* thisPointer,
		   Status (T::*handler)(const TransactionInfo&, const ev::Event&), bool forever = false)
   {
      return registry.addHandler(eventId, thisPointer, handler, forever);
   }

   Status waitUntouchEvent(const ev::EventId eventId);

private:
   EventHandlerRegistry registry;

private:
   DEFAULT(void, doKill(const TransactionInfo&, const Status));
};

TSL_NS_END

#endif /* SIMPLEASYNCACTION_H_ */
