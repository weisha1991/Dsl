/*
 * RuntimeContext.h
 *
 * Created on: Apr 21, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef RUNTIMECONTEXT_H_
#define RUNTIMECONTEXT_H_

#include <l0-infra/base/dci/Role.h>
#include <l0-infra/base/Status.h>
#include "l0-infra/base/Keywords.h"
#include "l0-infra/trans-dsl/tsl.h"

TSL_NS_BEGIN

DEFINE_ROLE(RuntimeContext)
{
   ABSTRACT(void reportFailure(Status));
   ABSTRACT(Status getStatus() const);
};

TSL_NS_END

#endif /* RUNTIMECONTEXT_H_ */
