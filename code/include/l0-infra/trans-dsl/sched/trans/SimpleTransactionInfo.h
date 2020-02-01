/*
 * SimpleTransactionInfo.h
 *
 * Created on: Apr 23, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef SIMPLETRANSACTIONINFO_H_
#define SIMPLETRANSACTIONINFO_H_

#include "l0-infra/trans-dsl/sched/concept/TransactionInfo.h"

TSL_NS_BEGIN

struct RuntimeContextInfo;

struct SimpleTransactionInfo : TransactionInfo
{
   explicit SimpleTransactionInfo(InstanceId iid = InstanceId(0));

   OVERRIDE(InstanceId getInstanceId() const);
   OVERRIDE(Status getStatus() const);
   OVERRIDE(dci::Unknown* getUserContext() const);

   void updateUserContext(dci::Unknown*);
   void updateInstanceId(InstanceId iid);

private:
   InstanceId iid = InstanceId(0);
   dci::Unknown* userContext = nullptr;

private:
   USE_ROLE(RuntimeContextInfo);
};

TSL_NS_END

#endif /* SIMPLETRANSACTIONINFO_H_ */
