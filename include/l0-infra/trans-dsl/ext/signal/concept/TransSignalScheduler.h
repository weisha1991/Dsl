#ifndef HA466B077_02E9_4409_95A5_4599FE9B2B9A
#define HA466B077_02E9_4409_95A5_4599FE9B2B9A

#include <l0-infra/base/dci/InterfaceDef.h>
#include <l0-infra/base/dci/Role.h>

#include "l0-infra/trans-dsl/ext/signal/concept/TransSignalId.h"
#include "l0-infra/trans-dsl/tsl.h"

TSL_NS_BEGIN

UNKNOWN_INTERFACE(TransSignalScheduler, 0x09061329)
{
    ABSTRACT(Status broadcast(const TransSignalId));
};

TSL_NS_END

#endif /* HA466B077_02E9_4409_95A5_4599FE9B2B9A */
