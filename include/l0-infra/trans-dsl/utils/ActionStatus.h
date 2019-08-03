/*
 * ActionStatus.h
 *
 * Created on: Apr 21, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef ACTIONSTATUS_H_
#define ACTIONSTATUS_H_

#include "l0-infra/trans-dsl/TslStatus.h"

TSL_NS_BEGIN

struct ActionStatus
{
   ActionStatus(Status status);

   bool isWorking() const;
   bool isFailed() const;
   bool isDone() const;
   bool eventAccepted() const;
   bool eventNotAccepted() const;
   bool isNothingChanged() const;

   operator Status() const;

private:
   Status status;
};

TSL_NS_END

#endif /* ACTIONSTATUS_H_ */
