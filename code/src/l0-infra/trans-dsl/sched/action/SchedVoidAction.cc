/*
 * SchedVoidAction.cc
 *
 *  Created on: Apr 22, 2013
 *      Author: arthur
 */

#include "l0-infra/trans-dsl/sched/action/SchedVoidAction.h"

#include "l0-infra/trans-dsl/sched/concept/TransactionContext.h"
#include "l0-infra/trans-dsl/sched/concept/TransactionInfo.h"
#include "l0-infra/trans-dsl/utils/ActionStatus.h"
#include "l0-infra/trans-dsl/utils/SimpleRuntimeContext.h"
#include "l0-infra/trans-dsl/utils/SimpleRuntimeContextAutoSwitch.h"

TSL_NS_BEGIN



/////////////////////////////////////////////////////////////////////////////////
namespace
{
   Status getFinalStatus(const ActionStatus status)
   {
      if(status.isWorking())
      {
         return status;
      }

      return CUB_SUCCESS;
   }
}

/////////////////////////////////////////////////////////////////////////////////
#define __CALL__(method) ROLE(SchedAction).method
#define __FINAL_CALL(method) getFinalStatus(__CALL__(method))

/////////////////////////////////////////////////////////////////////////////////
namespace
{
   struct AutoSwitch : SimpleRuntimeContext, SimpleRuntimeContextAutoSwitch
   {
      AutoSwitch(TransactionContext& context)
           : SimpleRuntimeContext(context.getTransactionInfo().getStatus())
           , SimpleRuntimeContextAutoSwitch(*this, context)
      {
      }
   };
}

/////////////////////////////////////////////////////////////////////////////////
#define __AUTO_SWITCH() AutoSwitch autoSwitch(context)

/////////////////////////////////////////////////////////////////////////////////
Status SchedVoidAction::exec(TransactionContext& context)
{
   __AUTO_SWITCH();
   return __FINAL_CALL(exec(context));
}

/////////////////////////////////////////////////////////////////////////////////
Status SchedVoidAction::handleEvent(TransactionContext& context, const ev::Event& event)
{
   __AUTO_SWITCH();
   return __FINAL_CALL(handleEvent(context, event));
}

/////////////////////////////////////////////////////////////////////////////////
Status SchedVoidAction::stop(TransactionContext& context, const Status cause)
{
   __AUTO_SWITCH();
   return __FINAL_CALL(stop(context, cause));
}

/////////////////////////////////////////////////////////////////////////////////
void SchedVoidAction::kill(TransactionContext& context, const Status cause)
{
   __AUTO_SWITCH();
   __CALL__(kill(context, cause));
}

TSL_NS_END

