#ifndef CODE_INCLUDE_L4_SCHED_OBJ_NBROP_H_
#define CODE_INCLUDE_L4_SCHED_OBJ_NBROP_H_

#include <l0-infra/base/Status.h>
#include <l0-infra/event/concept/EventId.h>
#include <l4-sched/obj/Key.h>

using ev::EventId;




struct NbrOp
{
    Status active() const;
    Status deactive() const;
    Key key;

private:
    Status pubSchedMsg(EventId eventId) const;
};


#endif /* CODE_INCLUDE_L4_SCHED_OBJ_NBROP_H_ */
