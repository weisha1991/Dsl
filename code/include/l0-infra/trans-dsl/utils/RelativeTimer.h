/*
 * RelativeTimer.h
 *
 * Created on: Apr 24, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef RELATIVETIMER_H_
#define RELATIVETIMER_H_

#include <l0-infra/base/Keywords.h>
#include <l0-infra/base/Status.h>
#include <l0-infra/event/event.h>

#include "l0-infra/trans-dsl/sched/concept/TimerId.h"

FWD_DECL_EV(Event);

TSL_NS_BEGIN

struct TimerInfo;

struct RelativeTimer
{
   RelativeTimer(const TimerId timerId);

   Status start(const TimerInfo&);
   void stop();

   bool matches(const ev::Event& event) const;

   virtual ~RelativeTimer() {}

private:
   const TimerId timerId;
   bool started;

private:
   ABSTRACT(bool isTimerEvent(const ev::Event&) const);
   ABSTRACT(Status actualStartTimer(const TimerId, U32 timerLen));
   ABSTRACT(void actualStopTimer(const TimerId));
   ABSTRACT(bool actualMatches(const ev::Event&, const TimerId) const);
};

TSL_NS_END

#endif /* RELATIVETIMER_H_ */
