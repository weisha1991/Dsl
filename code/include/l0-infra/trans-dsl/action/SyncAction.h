/*
 * SyncAction.h
 *
 * Created on: Apr 24, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef SYNCACTION_H_
#define SYNCACTION_H_

#include <l0-infra/base/dci/Role.h>
#include <l0-infra/base/Status.h>

#include "l0-infra/trans-dsl/tsl.h"

TSL_NS_BEGIN

///////////////////////////////////////////////////////////////////
struct TransactionInfo;

DEFINE_ROLE(SyncAction)
{
	ABSTRACT(Status exec(const TransactionInfo&));
};

///////////////////////////////////////////////////////////////////
#define DEF_SIMPLE_SYNC_ACTION(p_name)                 \
struct p_name : TSL_NS::SyncAction                     \
{                                                      \
    Status exec(const TSL_NS::TransactionInfo&);  \
}

///////////////////////////////////////////////////////////////////
#define DEF_ACTION_EXEC(p_class_name)     \
    Status p_class_name::exec(const TSL_NS::TransactionInfo& trans)


TSL_NS_END

#endif /* SYNCACTION_H_ */
