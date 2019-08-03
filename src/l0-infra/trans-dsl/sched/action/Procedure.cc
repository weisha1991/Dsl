/*
 * Procedure.cc
 *
 *  Created on: Apr 21, 2013
 *      Author: arthur
 */

#include "l0-infra/trans-dsl/sched/action/Procedure.h"

#include "l0-infra/trans-dsl/sched/concept/TransactionContext.h"
#include "l0-infra/trans-dsl/utils/ActionStatus.h"
#include "l0-infra/trans-dsl/utils/GofState.h"
#include "l0-infra/trans-dsl/utils/RuntimeContextAutoSwitch.h"

TSL_NS_BEGIN



///////////////////////////////////////////////////////////////////////
__DECL_STATE_INTERFACE(Procedure);

///////////////////////////////////////////////////////////////////////
__DEF_STATE_CLASS(Procedure, Idle)
{
   OVERRIDE(Status exec(Procedure& __THIS__, TransactionContext& context))
   {
      ActionStatus status = __THIS__.ROLE(SchedAction).exec(context);
      if(status.isWorking())
      {
         return __THIS__.__GOTO_STATE(Working);
      }

      return __THIS__.__GOTO_STATE(Final);
   }
};

///////////////////////////////////////////////////////////////////////
__DEF_BASE_STATE_CLASS(Procedure, WorkingState)
{
   OVERRIDE(Status handleEvent(Procedure& __THIS__, TransactionContext& context, const ev::Event& event))
   {
      ActionStatus status = __THIS__.ROLE(SchedAction).handleEvent(context, event);
      if(status.isWorking())
      {
         return status;
      }

      return __THIS__.__GOTO_STATE(Final);
   }

   OVERRIDE(void kill(Procedure& __THIS__, TransactionContext& context, const Status cause))
   {
      __THIS__.doKill(__THIS__.ROLE(SchedAction), context, cause);
   }
};

///////////////////////////////////////////////////////////////////////
__DEF_DERIVED_STATE_CLASS(Procedure, Working, WorkingState)
{
   OVERRIDE(Status stop(Procedure& __THIS__, TransactionContext& context, const Status cause))
   {
      ActionStatus status = __THIS__.ROLE(SchedAction).stop(context, cause);
      if(status.isWorking())
      {
         return __THIS__.__GOTO_STATE(Stopping);
      }

      return __THIS__.__GOTO_STATE(Final);
   }
};

///////////////////////////////////////////////////////////////////////
__DEF_DERIVED_STATE_CLASS(Procedure, Stopping, WorkingState)
{
   OVERRIDE(Status stop(Procedure&, TransactionContext&, const Status))
   {
      return TSL_CONTINUE;
   }
};

///////////////////////////////////////////////////////////////////////
__DEF_STATE_CLASS(Procedure, Final)
{
   OVERRIDE(Status enter(Procedure& __THIS__, TransactionContext& context, const ActionStatus result))
   {
      __THIS__.reportFailure(result);

      ActionStatus status = __THIS__.ROLE(FinalAction).exec(context);
      if(status.isWorking())
      {
         return status;
      }

      return __THIS__.__GOTO_STATE(Done);
   }

   OVERRIDE(Status handleEvent(Procedure& __THIS__, TransactionContext& context, const ev::Event& event))
   {
      ActionStatus status = __THIS__.ROLE(FinalAction).handleEvent(context, event);
      if(status.isWorking())
      {
         return status;
      }

      return __THIS__.__GOTO_STATE(Done);
   }

   OVERRIDE(Status stop(Procedure&, TransactionContext&, const Status))
   {
      return TSL_CONTINUE;
   }

   OVERRIDE(void kill(Procedure& __THIS__, TransactionContext& context, const Status cause))
   {
      __THIS__.doKill(__THIS__.ROLE(FinalAction), context, cause);
   }
};

///////////////////////////////////////////////////////////////////////
__DEF_STATE_CLASS(Procedure, Done)
{
   OVERRIDE(Status enter(Procedure& __THIS__, TransactionContext&, const ActionStatus result))
   {
      if(result.isFailed())
      {
         return result;
      }

      return __THIS__.isProtected() ? (Status)result : __THIS__.getFinalStatus();
   }
};

///////////////////////////////////////////////////////////////////////
__DEF_STATE(Procedure, Idle)
__DEF_STATE(Procedure, Working)
__DEF_STATE(Procedure, Stopping)
__DEF_STATE(Procedure, Final)
__DEF_STATE(Procedure, Done)

///////////////////////////////////////////////////////////////////////
Procedure::Procedure()
  : state(&Procedure::Idle::getInstance())
{
}

///////////////////////////////////////////////////////////////////////
bool Procedure::shouldReportParent() const
{
   return !isProtected();
}

///////////////////////////////////////////////////////////////////////
Status Procedure::getFinalStatus() const
{
   if(ActionStatus(getStatus()).isFailed())
   {
      return getStatus();
   }

   return TSL_SUCCESS;
}

///////////////////////////////////////////////////////////////////////
void Procedure::doKill(FinalAction& action, TransactionContext& context, Status cause)
{
   action.kill(context, cause);
   gotoDoneState(context, TSL_SUCCESS);
}

///////////////////////////////////////////////////////////////////////
struct Procedure::AutoSwitch : RuntimeContextAutoSwitch
{
   AutoSwitch(Procedure& proc, TransactionContext& context)
        : RuntimeContextAutoSwitch(proc, proc.parent, context)
   {
   }
};

///////////////////////////////////////////////////////////////////////
#define __AUTO_SWITCH()  AutoSwitch autoSwitch(*this, context)

///////////////////////////////////////////////////////////////////////
Status Procedure::exec(TransactionContext& context)
{
   __AUTO_SWITCH();
   return state->exec(*this, context);
}

///////////////////////////////////////////////////////////////////////
Status Procedure::handleEvent(TransactionContext& context, const ev::Event& event)
{
   __AUTO_SWITCH();
   return state->handleEvent(*this, context, event);
}

///////////////////////////////////////////////////////////////////////
Status Procedure::stop(TransactionContext& context, Status cause)
{
   __AUTO_SWITCH();
   return state->stop(*this, context, cause);
}

///////////////////////////////////////////////////////////////////////
void Procedure::kill(TransactionContext& context, Status cause)
{
   __AUTO_SWITCH();
   state->kill(*this, context, cause);
}

TSL_NS_END

