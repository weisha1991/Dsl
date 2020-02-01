/*
 * main.cpp
 *
 *  Created on: 2019��8��3��
 *      Author: zhengbinlong
 */

#include <l3-trans/testTrans.h>
#include <l4-sched/TransMachine.h>
#include "l3-trans/AddTrans.h"
#include <iostream>
#include "l0-infra/trans-dsl/sched/helper/TransactionHelper.h"

using namespace tsl;
using namespace ev;

enum class OpState
{
    OP_IDLE,
    OP_WORK
};

static OpState globalOpState = OpState::OP_IDLE;

OpState getCurOpState()
{
    return (globalOpState);
}

void setNextWorkState(OpState opState)
{
    globalOpState = opState;
}

namespace
{
    std::vector<EventId> transMsgVec{X2_HO_REQ};

    struct MccInst: TransMachine
                    , private x2hod
    {
        MccInst() :TransMachine(this, transMsgVec)
        {

        }

        BEGIN_INTERFACE_TABLE()
            __HAS_INTERFACE(TransStatusIF)
        END_INTERFACE_TABLE()

    private:
        IMPL_ROLE(LockableTransaction);
    };

    MccInst mccInst;

    Status handleOnIdle(U32 msgId, void *msg, U32 msgSize)
    {

        std::cout << "StartTrans" <<std::endl;
        mccInst.updateTimerInfo(timerInfo);
        mccInst.start();
        std::cout << mccInst.handleEvent(ConsecutiveEventInfo(msgId, msg ,msgSize)) << std::endl;

        setNextWorkState(OpState::OP_WORK);
        return 0;
    }

    Status handleOnWork(U32 msgId, void *msg, U32 msgSize)
    {
        setNextWorkState(OpState::OP_WORK);
        std::cout << mccInst.handleEvent(ConsecutiveEventInfo(msgId, msg ,msgSize)) << std::endl;
        return 0;
    }

}

extern "C" void MccEntry(U32 msgId, void *msg, U32 msgSize)
{
    auto opState = getCurOpState();
    switch(opState)
    {
    case OpState::OP_IDLE:
        handleOnIdle(msgId, msg, msgSize);
        break;
    case OpState::OP_WORK:
        handleOnWork(msgId, msg, msgSize);
        break;
    default:
        break;
    }
}
