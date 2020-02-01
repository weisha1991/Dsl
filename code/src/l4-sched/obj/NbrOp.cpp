/*
 * NbrOp.cpp
 *
 *  Created on: 2020年1月31日
 *      Author: zhengbinlong
 */
#include <l0-infra/base/Status.h>
#include <l0-infra/event/concept/EventId.h>
#include "l4-sched/obj/NbrOp.h"
#include "l4-sched/event/SchedEventDef.h"

Status NbrOp::active() const
{
    return pubSchedMsg(EV_SCHED_ACTIVE);
}

Status NbrOp::deactive() const
{
    return pubSchedMsg(EV_SCHED_DEACTIVE);
}

Status NbrOp::pubSchedMsg(EventId eventId) const
{
    return USI_SUCCESS;
}



