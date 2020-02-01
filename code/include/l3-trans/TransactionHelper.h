#ifndef CODE_INCLUDE_L3_TRANS_TRANSACTIONHELPER_H_
#define CODE_INCLUDE_L3_TRANS_TRANSACTIONHELPER_H_

#include <l0-infra/base/BaseTypes.h>
#include <l0-infra/trans-dsl/sched/concept/TransactionListener.h>
#include <l0-infra/trans-dsl/sched/trans/GenericTransaction.h>
#include <l0-infra/trans-dsl/tsl.h>
#include "l0-infra/trans-dsl/sched/helper/TransactionHelper.h"
#include "l0-infra/trans-dsl/ext/multi-thread/helper/MultiThreadTransactionHelper.h"

TSL_NS_BEGIN

typedef BYTE TIMER_ID;

template<typename T_ACTION, typename T_CONTEXT,
            typename T_TIMERMANGET,  TIMER_ID TIMERID = 0,
            typename T_LISTENER = NilTransactionListener>
struct GenericSimpleTrans :GenericTransaction<T_CONTEXT, T_LISTENER, T_TIMERMANGET>
{
    GenericSimpleTrans(const InstanceId iid)
                        : GenericTransaction<T_CONTEXT, T_LISTENER, T_TIMERMANGET>(iid)
    {

    }
private:
    __transaction
    (__apply(Trans, __with(TIMERID, T_ACTION))
    ) trans;

    IMPL_ROLE_WITH_OBJ(SchedTransaction, trans);
};


template<typename T_ACTION, typename T_CONTEXT,
            typename T_TIMERMANGET,  TIMER_ID TIMERID = 0,
            typename T_LISTENER = NilTransactionListener>
struct GenericSimpleMtTrans
    : GenericTransaction<T_CONTEXT, T_LISTENER, T_TIMERMANGET>
{
    GenericSimpleMtTrans(const Instance iid)
        : GenericTransaction<T_CONTEXT, T_LISTENER, T_TIMERMANGET>(iid)
    {

    }
private:
    __mt_transaction
    (__apply(Trans, __with(TIMERID, T_ACTION))
    ) trans;

    IMPL_ROLE_WITH_OBJ(SchedTransaction, trans);
};

#define DEF_SIMPLE_TRANS(ClassName, ActionClass, ContextClass, TimrManagerClass, TIMER_ID, ...) \
        typedef GenericSimpleTrans<__apply(ActionClass), ContextClass, ContextClass, TimerManagerClass, TIMER_ID, ##__VA_ARGS__> ClassName

#define DEF_SIMPLE_MT_TRANS(ClassName, ActionClass, ContextClass, TimrManagerClass, TIMER_ID, ...) \
        typedef GenericSimpleMtTrans<__apply(ActionClass), ContextClass, ContextClass, TimerManagerClass, TIMER_ID, ##__VA_ARGS__> ClassName



TSL_NS_END

#endif /* CODE_INCLUDE_L3_TRANS_TRANSACTIONHELPER_H_ */
