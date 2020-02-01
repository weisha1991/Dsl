#ifndef CODE_INCLUDE_L4_SCHED_EVENT_SCHEDEVENTDEF_H_
#define CODE_INCLUDE_L4_SCHED_EVENT_SCHEDEVENTDEF_H_

#include <l0-infra/event/concept/EventId.h>

using ev::EventId;

const EventId EV_SCHED_FIRST= 0x1000;
const EventId EV_SCHED_WAIT_REQ = 0x1002;
const EventId EV_SCHED_WAIT_RSP = 0x1003;
const EventId EV_SCHED_ACTIVE = 0x1004;
const EventId EV_SCHED_DEACTIVE= 0x1005;



#endif /* CODE_INCLUDE_L4_SCHED_EVENT_SCHEDEVENTDEF_H_ */