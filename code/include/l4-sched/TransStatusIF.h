#ifndef CODE_INCLUDE_L4_SCHED_TRANSSTATUSIF_H_
#define CODE_INCLUDE_L4_SCHED_TRANSSTATUSIF_H_

#include "l0-infra/base/dci/InterfaceDef.h"


enum class TransMachineStatus
{
    TRANS_IDLE,
    TRANS_WAIT,
    TRANS_WORK
};

UNKNOWN_INTERFACE(TransStatusIF, 0x20200131)
{
    TransMachineStatus getStatus()
    {
        return status;
    }

    void setStatus(TransMachineStatus status)
    {
        this->status = status;
    }

    TransMachineStatus status = TransMachineStatus::TRANS_IDLE;
};



#endif /* CODE_INCLUDE_L4_SCHED_TRANSSTATUSIF_H_ */
