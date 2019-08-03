#include "l0-infra/trans-dsl/sched/concept/TransactionListener.h"

TSL_NS_BEGIN

TransactionListener& getNilTransactionListener()
{
    static TransactionListener listener;
    return listener;
}

TSL_NS_END
