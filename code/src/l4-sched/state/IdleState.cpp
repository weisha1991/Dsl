/*
 * IdleState.cpp
 *
 *  Created on: 2020年1月31日
 *      Author: zhengbinlong
 */
#include <l0-infra/base/Assertions.h>
#include <l0-infra/base/Status.h>
#include <l0-infra/event/concept/EventId.h>
#include <l0-infra/mem/Maybe.h>
#include "l4-sched/state/IdleState.h"
#include "l4-sched/TransMachine.h"
#include "l4-sched/event/SchedEventDef.h"

Status IdleState::enter(const ev::Event &event)
{

    context.node.prev.reset();
    context.node.next.reset();
    return USI_SUCCESS;
}

Status IdleState::handleEvent(const Event &event)
{
    if(context.isTransEvent(event.getEventId()))
    {
        CUB_ASSERT_SUCC_CALL(context.preWork(event));
        return context.gotoWork(event);
    }
    else if(event.getEventId() == EV_SCHED_WAIT_REQ)
    {
        return context.gotoWait(event);
    }

    return USI_SUCCESS;
}


