/*
 * StopCause.cc
 *
 * Created on: May 29, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#include "../include/l0-infra/trans-dsl/utils/StopCause.h"

#include "../include/l0-infra/trans-dsl/utils/ActionStatus.h"

TSL_NS_BEGIN

//////////////////////////////////////////////////////////////////////////
StopCause::StopCause() : cause(TSL_FORCE_STOPPED)
{
}

//////////////////////////////////////////////////////////////////////////
StopCause::StopCause(const Status cause)
      : cause(ActionStatus(cause).isFailed() ? cause : TSL_FORCE_STOPPED)
{
}

//////////////////////////////////////////////////////////////////////////
StopCause::operator Status() const
{
   return cause;
}

TSL_NS_END
