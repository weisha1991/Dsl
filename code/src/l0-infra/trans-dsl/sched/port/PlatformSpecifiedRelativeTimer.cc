/*
 * PlatformSpecifiedRelativeTimer.cc
 *
 *  Created on: Apr 24, 2013
 *      Author: arthur
 */

#include "l0-infra/trans-dsl/sched/port/PlatformSpecifiedRelativeTimer.h"

#include <l0-infra/event/concept/Event.h>

#include "l0-infra/trans-dsl/TslStatus.h"

TSL_NS_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////
PlatformSpecifiedRelativeTimer::PlatformSpecifiedRelativeTimer(
         const TimerId timerId)
   : RelativeTimer(timerId)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
namespace
{
   const ev::EventId TIMER_EVENT_START = 400;
   const ev::EventId TIMER_EVENT_END   = 430;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
bool PlatformSpecifiedRelativeTimer::isTimerEvent(const ev::Event& event) const
{
   return event.getEventId() >= TIMER_EVENT_START && event.getEventId() < TIMER_EVENT_END;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
Status PlatformSpecifiedRelativeTimer::actualStartTimer(const TimerId, U32)
{
   return TSL_SUCCESS;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
void PlatformSpecifiedRelativeTimer::actualStopTimer(const TimerId)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
bool PlatformSpecifiedRelativeTimer::actualMatches(const ev::Event& event, const TimerId timerId) const
{
   return timerId + TIMER_EVENT_START == event.getEventId();
}

TSL_NS_END
