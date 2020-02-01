#ifndef CODE_INCLUDE_L4_SCHED_STATE_WORKSTATE_H_
#define CODE_INCLUDE_L4_SCHED_STATE_WORKSTATE_H_

#include <l4-sched/state/SchedState.h>


struct WorkState : SchedState
{
    using SchedState::SchedState;
    OVERRIDE(Status enter(const Event&));
    OVERRIDE(Status handleEvent(const Event &));
    OVERRIDE(Status leave(const Status ret));
private:
    Status onDone(bool isSucc);
    void updateWaitRsp(const Event&);
};


#endif /* CODE_INCLUDE_L4_SCHED_STATE_WORKSTATE_H_ */
