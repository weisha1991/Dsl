#include <l0-infra/base/Status.h>
#include "l4-sched/TransMachine.h"
#include <algorithm>

TransMachine::TransMachine(dci::Unknown *obj, const std::vector<ev::EventId> &idVec) : user_context(nullptr),
                                                iid(&func), work(*this), idle(*this), wait(*this), transIdVec(idVec)
{
    func.commIf = obj;
    func.updateContext = [this](dci::Unknown *c) {user_context = c;};
    state = &idle;
    state->enter(ev::Event());
}

Status TransMachine::handle(const ev::Event &event)
{
    ActionStatus ret = state->handleEvent(event);

    stateHandle(event, ret);

    return ret;
}

Status TransMachine::stateHandle(const Event &event, ActionStatus &ret)
{
    if(ret.eventNotAccepted())
    {
        ret = decide(event);
    }

    idleStateHandle(event, &idle == state && ret.isDone());
    transPostHandle(event, ret);
    transUnknownEventHandle(event, ret);

    if(ret.isFailed())
    {
        fail(0);
    }

    return ret;
}

Status TransMachine::decide(const ev::Event &event)
{
    return USI_UNKNOWN;
}

Status TransMachine::discard(const Event &event)
{
    event.consume();
    return USI_CONTINUE;
}

Status TransMachine::reject(const Event &event)
{
    event.consume();
    return USI_CONTINUE;
}

Status TransMachine::interrupt(const Event &event, const Status ret)
{
    event.consume();
    return state->leave(ROLE(Transaction).stop(ret));
}

Status TransMachine::replace(const Event &event)
{
    ROLE(Transaction).kill(USI_FAILED);
    return gotoIdle();
}

Status TransMachine::fail(const Status status)
{
    ROLE(Transaction).kill(status);
    return gotoIdle();
}

Status TransMachine::gotoWork(const Event &event)
{
    state = &work;
    setStatus(TransMachineStatus::TRANS_WORK);

    return state->enter(event);
}

Status TransMachine::gotoIdle()
{
    ROLE(LockableTransaction).destroy();
    destroy();
    state = &idle;
    setStatus(TransMachineStatus::TRANS_IDLE);
    return state->enter(Event());
}

bool TransMachine::isTransEvent(const EventId id)
{
    return std::any_of(transIdVec.begin(), transIdVec.end(),
            [id](EventId var){return id == var;});
}

const InstanceId& TransMachine::getInstanceId()
{
    return iid;
}

void TransMachine::idleStateHandle(const ev::Event &event, bool Status)
{
    if(status)
    {
//        ROLE()
    }
}

void TransMachine::transPostHandle(const ev::Event&, ActionStatus &isNotAccept)
{

}
void TransMachine::transUnknownEventHandle(const ev::Event&, ActionStatus&ret)
{

}

