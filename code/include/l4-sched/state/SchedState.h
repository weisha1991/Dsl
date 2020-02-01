/*
 * SchedState.h
 *
 *  Created on: 2020��1��31��
 *      Author: zhengbinlong
 */

#ifndef CODE_INCLUDE_L4_SCHED_STATE_SCHEDSTATE_H_
#define CODE_INCLUDE_L4_SCHED_STATE_SCHEDSTATE_H_

#include <l0-infra/base/Keywords.h>
#include <l0-infra/base/Status.h>
#include "l0-infra/event/concept/Event.h"
#include "l0-infra/base/dci/Role.h"

using ev::Event;

struct TransMachine;

DEFINE_ROLE(SchedState)
{
    SchedState(TransMachine &context): context(context){}
    ABSTRACT(Status enter(const Event &event));
    ABSTRACT(Status handleEvent(const Event &event));
    virtual Status leave(const Status ret) {return USI_SUCCESS;}

protected:
    TransMachine &context;
};


#endif /* CODE_INCLUDE_L4_SCHED_STATE_SCHEDSTATE_H_ */
