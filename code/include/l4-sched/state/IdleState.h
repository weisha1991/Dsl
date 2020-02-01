/*
 * IdleState.h
 *
 *  Created on: 2020��1��31��
 *      Author: zhengbinlong
 */

#ifndef CODE_INCLUDE_L4_SCHED_STATE_IDLESTATE_H_
#define CODE_INCLUDE_L4_SCHED_STATE_IDLESTATE_H_

#include <l4-sched/state/SchedState.h>

struct IdleState : SchedState
{
    using SchedState::SchedState;
    OVERRIDE(Status enter(const Event &event));
    OVERRIDE(Status handleEvent(const Event &));
};

#endif /* CODE_INCLUDE_L4_SCHED_STATE_IDLESTATE_H_ */
