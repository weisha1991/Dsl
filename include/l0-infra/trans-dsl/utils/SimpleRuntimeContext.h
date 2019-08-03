/*
 * SimpleRuntimeContext.h
 *
 * Created on: Apr 22, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef SIMPLERUNTIMECONTEXT_H_
#define SIMPLERUNTIMECONTEXT_H_

#include "l0-infra/trans-dsl/sched/concept/RuntimeContext.h"
#include "l0-infra/trans-dsl/TslStatus.h"
#include "l0-infra/base/Keywords.h"

TSL_NS_BEGIN

struct SimpleRuntimeContext : RuntimeContext
{
   explicit SimpleRuntimeContext(Status parentStatus = TSL_SUCCESS);

   OVERRIDE(void reportFailure(Status));
   OVERRIDE(Status getStatus() const);

protected:
   RuntimeContext* parent;
   Status objectStatus;

private:
   virtual bool shouldReportParent() const { return true; }
};

TSL_NS_END

#endif /* SIMPLERUNTIMECONTEXT_H_ */
