/*
 * TransactionContext.h
 *
 * Created on: Apr 21, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef TRANSACTIONCONTEXT_H_
#define TRANSACTIONCONTEXT_H_

#include <l0-infra/base/dci/Role.h>
#include <l0-infra/base/Status.h>
#include <l0-infra/base/dci/Unknown.h>

#include "l0-infra/trans-dsl/tsl.h"

TSL_NS_BEGIN

struct TransactionInfo;
struct TransactionListener;
struct TransactionMode;

struct TransactionContext : com::Unknown
{
   HAS_ROLE(TransactionInfo);
   HAS_ROLE(TransactionListener);
   HAS_ROLE(TransactionMode);
};

TSL_NS_END

#endif /* TRANSACTIONCONTEXT_H_ */
