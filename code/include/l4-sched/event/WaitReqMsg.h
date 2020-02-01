#ifndef CODE_INCLUDE_L4_SCHED_EVENT_WAITREQMSG_H_
#define CODE_INCLUDE_L4_SCHED_EVENT_WAITREQMSG_H_

#include "l4-sched/obj/Key.h"

struct WaitReqMsg
{
    Key key;
    WORD32 len;
    BYTE originMsg[100];
};

struct WaitRspMsg
{
    Key key;
    WORD32 len;
    BYTE originMsg[100];
};

struct ReplaceReqMsg
{
    Key key;
    WORD32 len;
    BYTE originMsg[100];
};


#endif /* CODE_INCLUDE_L4_SCHED_EVENT_WAITREQMSG_H_ */
