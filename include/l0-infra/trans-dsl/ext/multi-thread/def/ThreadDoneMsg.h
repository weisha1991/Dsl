/*
 * ThreadDoneMsg.h
 *
 * Created on: Apr 23, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef THREADDONEMSG_H_
#define THREADDONEMSG_H_

#include <l0-infra/event/concept/EventId.h>
#include <l0-infra/base/Status.h>

#include "l0-infra/trans-dsl/ext/multi-thread/concept/ActionThreadId.h"

TSL_NS_BEGIN

const ev::EventId EV_ACTION_THREAD_DONE = 0xFFFE;

struct ThreadDoneMsg
{
   ThreadDoneMsg(ActionThreadId who, Status status)
     : who(who)
     , result(status)
   {}

   const ActionThreadId who;
   const Status    result;
};

TSL_NS_END

#endif /* THREADDONEMSG_H_ */
