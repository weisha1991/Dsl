/*
 * UeTranaction.h
 *
 *  Created on: 2019Äê8ÔÂ3ÈÕ
 *      Author: zhengbinlong
 */

#ifndef INCLUDE_L3_TRANS_TESTTRANS_H_
#define INCLUDE_L3_TRANS_TESTTRANS_H_


#include "l0-infra/trans-dsl/TransactionDSL.h"
#include "l0-infra/event/impl/SimpleEventInfo.h"
#include "l0-infra/event/concept/Event.h"
#include "l0-infra/trans-dsl/action/SimpleAsyncActionHelper.h"
#include <l0-infra/event/impl/ConsecutiveEventInfo.h>
#include <l0-infra/trans-dsl/TslStatus.h>
#include "l0-infra/trans-dsl/action/Actor.h"
#include "l0-infra/trans-dsl/sched/helper/TransactionHelper.h"

USING_TSL_NS

__def_transaction
( __sequential
   ( __wait(1)
   , __wait(2))
)transExample;



#endif /* INCLUDE_L3_TRANS_TESTTRANS_H_ */
