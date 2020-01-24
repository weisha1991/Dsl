/*
 * LinkedActionThread.h
 *
 * Created on: Apr 22, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef LINKEDACTIONTHREAD_H_
#define LINKEDACTIONTHREAD_H_

#include <l0-infra/repo/list/ListElem.h>

#include "l0-infra/trans-dsl/sched/action/ActionThread.h"

TSL_NS_BEGIN

struct LinkedActionThread
         : ActionThread
         , ListElem<LinkedActionThread>
{
private:
   USE_ROLE(SchedAction);
};

TSL_NS_END

#endif /* LINKEDACTIONTHREAD_H_ */
