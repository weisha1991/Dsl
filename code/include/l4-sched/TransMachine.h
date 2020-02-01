#ifndef CODE_INCLUDE_L4_SCHED_TRANSMACHINE_H_
#define CODE_INCLUDE_L4_SCHED_TRANSMACHINE_H_

#include <l0-infra/base/dci/Unknown.h>
#include <l0-infra/base/Default.h>
#include <l0-infra/base/Status.h>
#include <l0-infra/event/concept/Event.h>
#include <l0-infra/event/concept/EventId.h>
#include <l0-infra/mem/Maybe.h>
#include <l0-infra/trans-dsl/sched/concept/InstanceId.h>
#include <l0-infra/trans-dsl/sched/concept/LockableTransaction.h>
#include <l0-infra/trans-dsl/sched/concept/Transaction.h>
#include <l0-infra/trans-dsl/utils/ActionStatus.h>
#include <l0-infra/utils/InstanceIdHelper.h>
#include <l4-sched/obj/NbrOp.h>
#include <l4-sched/state/IdleState.h>
#include <l4-sched/state/SchedState.h>
#include <l4-sched/state/WaitState.h>
#include <l4-sched/state/WorkState.h>
#include <l4-sched/TransStatusIF.h>
#include "l0-infra/base/dci/Role.h"
#include "l0-infra/base/Default.h"
#include <vector>

using tsl::ActionStatus;
using tsl::InstanceId;
using tsl::LockableTransaction;
using tsl::Transaction;

struct TransNode
{
    Maybe<NbrOp> prev;
    Maybe<NbrOp> next;
};

DEFINE_ROLE(TransMachine), TransStatusIF
{
    TransMachine(dci::Unknown *obj, const std::vector<ev::EventId> &idVec);
    ~TransMachine(){}

    Status handle(const ev::Event &);
    USE_ROLE(LockableTransaction);

    TransNode node;
    dci::Unknown *user_context;
    const InstanceId iid;

    Status gotoWork(const ev::Event&);
    Status gotoIdle();
    Status gotoWait(const ev::Event&);

    virtual bool isTransEvent(const ev::EventId id);
    SchedState *getState() const {return state;}
    DEFAULT(Status, preWork(const Event &));
private:
    DEFAULT(void, destroy());
    DECL_ROLE(Transaction){return ROLE(LockableTransaction);}
private:
    Status buffer(const ev::Event&, Status next);
    Status decide(const ev::Event&);
    Status replace(const ev::Event&);
    Status discard(const ev::Event&);
    Status reject(const ev::Event&);
    Status fail(const Status);
    Status interrupt(const ev::Event&, const Status);
    const InstanceId& getInstanceId();
    void idleStateHandle(const ev::Event&, bool Status);
    void transPostHandle(const ev::Event&, ActionStatus &isNotAccept);
    void transUnknownEventHandle(const ev::Event&, ActionStatus&ret);
    Status stateHandle(const ev::Event &, ActionStatus&);

private:
    SchedState *state;
    WorkState work;
    IdleState idle;
    WaitState wait;
    InstFunc func;
    std::vector<ev::EventId> transIdVec;

};


#endif /* CODE_INCLUDE_L4_SCHED_TRANSMACHINE_H_ */
