/*
 * SimpleTransactionScheduler.cc
 *
 * Created on: Jun 11, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#include"l0-infra/trans-dsl/sched/trans/SimpleTransactionScheduler.h"

#include"l0-infra/trans-dsl/sched/action/ActionThread.h"

TSL_NS_BEGIN



///////////////////////////////////////////////////////////////////////////////
SimpleTransactionScheduler::SimpleTransactionScheduler(InstanceId iid)
      : BaseTransactionScheduler(iid)
      , thread(0)
{
}

///////////////////////////////////////////////////////////////////////////////
SimpleTransactionScheduler::SimpleTransactionScheduler
      ( RuntimeContext& runtimeContext
      , InstanceId iid)
      : BaseTransactionScheduler(runtimeContext, iid)
      , thread(0)
{
}

///////////////////////////////////////////////////////////////////////////////
Status SimpleTransactionScheduler::start(ActionThread& thread)
{
   this->thread = &thread;
   return thread.exec(*this);
}

///////////////////////////////////////////////////////////////////////////////
Status SimpleTransactionScheduler::handleEvent(const ev::Event& event)
{
   return thread->handleEvent(*this, event);
}

///////////////////////////////////////////////////////////////////////////////
Status SimpleTransactionScheduler::actualStop(const Status cause)
{
   return thread->stop(*this, cause);
}

///////////////////////////////////////////////////////////////////////////////
bool SimpleTransactionScheduler::isWorking() const
{
   return thread->isWorking();
}

///////////////////////////////////////////////////////////////////////////////
void SimpleTransactionScheduler::kill(const Status cause)
{
   thread->kill(*this, cause);
}

TSL_NS_END
