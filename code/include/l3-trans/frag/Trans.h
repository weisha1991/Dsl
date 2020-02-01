#ifndef CODE_INCLUDE_L3_TRANS_FRAG_TRANS_H_
#define CODE_INCLUDE_L3_TRANS_FRAG_TRANS_H_

#include "l0-infra/trans-dsl/tsl.h"
#include "l0-infra/trans-dsl/TransactionDSL.h"
#include "l0-infra/trans-dsl/sched/helper/TimerProtHelper.h"
#include "l1-domain/errorcode/CommonError.h"

TSL_NS_BEGIN

__def(Trans, __params(__timer_id(TIMER_ID), __action(TRANS))) __as
(
    __timer_prot(TIMER_ID, TRANS, E_COMM_FLOW_TIMEOUT)
);


TSL_NS_END

#endif /* CODE_INCLUDE_L3_TRANS_FRAG_TRANS_H_ */
