/*
 * TransMutexScheduler.h
 *
 * Created on: Aug 7, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef TRANSMUTEXSCHEDULER_H_
#define TRANSMUTEXSCHEDULER_H_

#include <l0-infra/base/Status.h>
#include <l0-infra/base/dci/InterfaceDef.h>
#include <l0-infra/base/dci/Role.h>

#include "l0-infra/trans-dsl/ext/mutex/concept/TransMutextId.h"

TSL_NS_BEGIN

UNKNOWN_INTERFACE(TransMutexScheduler, 34427421)
{
   ABSTRACT(Status lock(TransMutexId));
   ABSTRACT(void unlock(TransMutexId));
};

TSL_NS_END

#endif /* TRANSMUTEXSCHEDULER_H_ */
