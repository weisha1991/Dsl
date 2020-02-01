/*
 * Event.h
 *
 * Created on: Apr 21, 2013, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef EVENT_H_
#define EVENT_H_

#include <l0-infra/event/concept/EventId.h>
#include <l0-infra/base/Status.h>
#include "l0-infra/base/Assertions.h"
#include <cstddef>

EV_NS_BEGIN

struct EventInfo;

struct Event
{
   Event();
   Event(const EventInfo& info);

   EventId getEventId() const;
   const void* getMsg() const;
   size_t getMsgSize() const;

   bool matches(const EventId eventId) const;

   Status updateEventId(const EventId) const;
   void assignEventInfoTo(Event&) const;
   const EventInfo& getEventInfo() const
   {
       return *info;
   }

   void consume() const;
   bool isConsumed() const;

private:
   const EventInfo* info;
   mutable bool consumed;
};

#define GET_MSG_PTR(type) (static_cast<const type*>(event.getMsg()))

#define EVENT_TO_MSG_VOID(type, var) \
    const type *var = GET_MSG_PTR(type);\
    CUB_ASSERT_VALID_PTR_VOID(var);


EV_NS_END

#endif /* EVENT_H_ */
