/*
 * ActionHelper.h
 *
 * Created on: Apr 24, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef ACTIONHELPER_H_
#define ACTIONHELPER_H_

#include <l0-infra/base/Keywords.h>
#include "l0-infra/trans-dsl/sched/concept/SchedAction.h"

TSL_NS_BEGIN

namespace details
{
    template<typename T_ASYN_ACTION>
    struct ASYN__ : SchedAction
    {
        OVERRIDE(Status exec(TransactionContext &context))
        {
            action.reset();
            return action.exec(context);
        }

        OVERRIDE(Status handleEvent(TransactionContext &context, const ev::Event &event))
        {
            return action.handleEvent(context, event);
        }

        OVERRIDE(Status stop(TransactionContext &context, const Status status))
        {
            action.kill(context, status);
            return status;
        }

        OVERRIDE(void kill(TransactionContext &context, const Status status))
        {
            action.kill(context, status);
        }

    private:
        T_ASYN_ACTION action;
    };

    template<typename T_SYNC_ACTION>
    struct SYNC__ : SchedAction
    {
        OVERRIDE(Status exec(TransactionContext &context))
        {
            return action.exec(context);
        }

        OVERRIDE(Status handleEvent(TransactionContext &context, const ev::Event &event))
        {
            return USI_UNKNOWN;
        }

        OVERRIDE(Status stop(TransactionContext &context, const Status status))
        {
            return status;
        }

        OVERRIDE(void kill(TransactionContext &context, const Status status))
        {

        }
    private:
        T_SYNC_ACTION action;
    };

}

TSL_NS_END

////////////////////////////////////////////////////////////////////////
#define __asyn(action, ...) \
       TSL_NS::details::ASYN__< action, ##__VA_ARGS__>

#define __sync(action, ...) \
       TSL_NS::details::SYNC__< action, ##__VA_ARGS__>

////////////////////////////////////////////////////////////////////////
#define __ind(...)  __sync(__VA_ARGS__)
#define __call(...) __sync(__VA_ARGS__)
#define __req(...)  __asyn(__VA_ARGS__)
#define __rsp(...)  __sync(__VA_ARGS__)

#define __onto(actor)    < actor >
////////////////////////////////////////////////////////////////////////

#endif /* ACTIONHELPER_H_ */
