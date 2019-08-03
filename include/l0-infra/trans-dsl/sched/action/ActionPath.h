/*
 * ActionPath.h
 *
 * Created on: Apr 22, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef ACTIONPATH_H_
#define ACTIONPATH_H_

#include <l0-infra/base/dci/ListBasedRole.h>

#include "l0-infra/trans-dsl/tsl.h"

TSL_NS_BEGIN

struct TransactionInfo;
struct SchedAction;

DEFINE_ROLE(ActionPath) EXTENDS(ListElem<ActionPath>)
{
   ABSTRACT(bool shouldExecute(const TransactionInfo&));
   ABSTRACT(SchedAction& getAction());
};

TSL_NS_END

#endif /* ACTIONPATH_H_ */
