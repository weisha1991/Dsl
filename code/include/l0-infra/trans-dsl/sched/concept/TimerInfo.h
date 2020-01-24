/*
 * TimerInfo.h
 *
 * Created on: Apr 22, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef TIMERINFO_H_
#define TIMERINFO_H_

#include <l0-infra/base/BaseTypes.h>
#include <l0-infra/base/dci/InterfaceDef.h>
#include <l0-infra/base/dci/Role.h>

#include "l0-infra/trans-dsl/sched/concept/TimerId.h"

TSL_NS_BEGIN

UNKNOWN_INTERFACE(TimerInfo, 32302582)
{
   ABSTRACT(U32 getTimerLen(const TimerId) const);
};

TSL_NS_END

#endif /* TIMINGINFO_H_ */
