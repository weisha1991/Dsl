/*
 * SchedTimerProtAction.h
 *
 * Created on: Apr 21, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef SCHEDTIMERPROTACTION_H_
#define SCHEDTIMERPROTACTION_H_

#include "l0-infra/trans-dsl/sched/concept/SchedAction.h"
#include "l0-infra/trans-dsl/utils/DeclState.h"

TSL_NS_BEGIN

struct RelativeTimer;

namespace details
{
   struct TimerProtActionState
   {
      TimerProtActionState();

      void start();
      void stop(const Status status);

      bool isStopping() const;
      bool isDone() const;

   private:
      enum
      {
         IDLE,
         WORKING,
         STOPPING,
      }state;
   };

   struct TimerProtAction : SchedAction
   {
      OVERRIDE(Status exec(TransactionContext&));
      OVERRIDE(Status handleEvent(TransactionContext&, const ev::Event&));
      OVERRIDE(Status stop(TransactionContext&, const Status));
      OVERRIDE(void   kill(TransactionContext&, const Status));

   private:
      Status startTimer(TransactionContext&);

   private:
      USE_ROLE(RelativeTimer);
      USE_ROLE(SchedAction);
      USE_ROLE(TimerProtActionState);

      ABSTRACT(Status getTimeoutStatus() const);
   };

   struct TimerProtFinalAction : FinalAction
   {
      OVERRIDE(Status exec(TransactionContext&));
      OVERRIDE(Status handleEvent(TransactionContext&, const ev::Event&));
      OVERRIDE(void   kill(TransactionContext&, const Status));

   private:
      USE_ROLE(SchedAction);
      USE_ROLE(TimerProtActionState);
   };
}

TSL_NS_END

#endif /* SCHEDTIMERPROTACTION_H_ */
