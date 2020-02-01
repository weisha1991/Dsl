#include <l0-infra/base/Assertions.h>
#include <l4-sched/event/WaitReqMsg.h>
#include "l4-sched/state/WorkState.h"
#include "l4-sched/TransMachine.h"
#include "l4-sched/event/SchedEventDef.h"

Status WorkState::enter(const ev::Event &event)
{
    context.ROLE(LockableTransaction).init(context.iid);
    context.node.prev.reset();

    ActionStatus ret = context.ROLE(LockableTransaction).start();

    if(ret.isWorking())
    {
        return handleEvent(event);
    }

    return ret;
}

Status WorkState::leave(const Status ret)
{
    ActionStatus status(ret);
    if(!status.isWorking())
    {
        return onDone(status.isDone());
    }

    return ret;
}

Status WorkState::handleEvent(const ev::Event &event)
{
    if(event.getEventId() == EV_SCHED_WAIT_RSP)
    {

    }

    ActionStatus ret= context.ROLE(LockableTransaction).handleEvent(event);

    if(ret.isFailed() || ret.isWorking())
    {
        return ret;
    }

    return onDone(ret.isDone());
}

Status WorkState::onDone(bool isSucc)
{
    auto &next = context.node.next;

    if(next.isPresent())
    {
        auto ret = isSucc ? next->active() : next->deactive();
        CUB_ASSERT_SUCC_CALL(ret);
    }

    return context.gotoIdle();
}

void WorkState::updateWaitRsp(const ev::Event &event)
{
    EVENT_TO_MSG_VOID(WaitRspMsg, msg);
    context.node.next.forceEffective();
    auto obj = context.node.next.getPointer();
    CUB_ASSERT_VALID_PTR_VOID(obj);
    obj->key = msg->key;
}


