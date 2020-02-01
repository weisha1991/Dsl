#ifndef CODE_INCLUDE_L4_SCHED_STATE_WAITSTATE_H_
#define CODE_INCLUDE_L4_SCHED_STATE_WAITSTATE_H_

#include <l4-sched/state/SchedState.h>


struct WaitState : SchedState
{
    using SchedState::SchedState;
    WaitState(const WaitState &) = delete;
    WaitState& operator == (const WaitState&) = delete;
    virtual ~WaitState();
private:
    OVERRIDE(Status enter(const Event&));
    OVERRIDE(Status handleEvent(const Event &));
private:
    Status gotoWork();
    Status gotoIdle();
private:
    void *buff = nullptr;
    WORD32 len = 0;
};


#endif /* CODE_INCLUDE_L4_SCHED_STATE_WAITSTATE_H_ */
