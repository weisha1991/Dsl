/*
 * ActionStatus.cc
 *
 * Created on: Apr 21, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#include "l0-infra/trans-dsl/utils/ActionStatus.h"

TSL_NS_BEGIN

///////////////////////////////////////////////////////////////////
ActionStatus::ActionStatus(Status status)
   : status(status)
{
}

///////////////////////////////////////////////////////////////////
bool ActionStatus::isWorking() const
{
   return status == TSL_CONTINUE || status == TSL_UNKNOWN_EVENT;
}

///////////////////////////////////////////////////////////////////
bool ActionStatus::isFailed() const
{
   return isFailStatus(status);
}

///////////////////////////////////////////////////////////////////
bool ActionStatus::eventAccepted() const
{
   return status != TSL_UNKNOWN_EVENT;
}

///////////////////////////////////////////////////////////////////
bool ActionStatus::eventNotAccepted() const
{
   return !eventAccepted();
}

///////////////////////////////////////////////////////////////////
ActionStatus::operator Status() const
{
   return status;
}

///////////////////////////////////////////////////////////////////
bool ActionStatus::isNothingChanged() const
{
    return status == TSL_NOTHING_CHANGED;
}

///////////////////////////////////////////////////////////////////
bool ActionStatus::isDone() const
{
   return status == TSL_SUCCESS;
}

TSL_NS_END


