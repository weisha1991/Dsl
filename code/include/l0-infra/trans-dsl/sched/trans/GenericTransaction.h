#ifndef H41037034_2B25_4F59_BF43_5B607BAA5DD0
#define H41037034_2B25_4F59_BF43_5B607BAA5DD0

#include <l0-infra/base/dci/Unknown.h>
#include <l0-infra/base/log/log.h>
#include <l0-infra/mem/Placement.h>
#include <l0-infra/trans-dsl/sched/concept/LockableTransaction.h>
#include <l0-infra/trans-dsl/sched/concept/TransactionListener.h>
#include "l0-infra/trans-dsl/sched/trans/SchedTransaction.h"


TSL_NS_BEGIN

struct AbstractTransaction : LockableTransaction
{
    explicit AbstractTransaction(const InstanceId iid);

    OVERRIDE(Status start());
    OVERRIDE(Status handleEvent(const ev::Event&));
    OVERRIDE(Status stop(const StopCause& = StopCause()));
    OVERRIDE(void   kill(const StopCause& = StopCause()));

    OVERRIDE(void updateMutexScheduler(TransMutexScheduler&));
    OVERRIDE(void updateSignalScheduler(TransSignalScheduler&));
    OVERRIDE(void init(const InstanceId&));

    void resetTransactionListener();
    void resetUserContext();

private:
    struct AutoSwitch;
private:
    void updateUserContext();
    void cleanupUserContext();
    Status final(const Status);
protected:
    InstanceId iid;
private:
    USE_ROLE(SchedTransaction);
    ABSTRACT(TransactionListener* getListener());
    ABSTRACT(dci::Unknown* getUserContext());
    ABSTRACT(const TimerInfo* getTimerInfo());
};

template<typename T_LISTENER>
struct ListenerWrap
{
    T_LISTENER listener;
};

template<typename T_LISTENER>
struct TransactionListenerTraits
{
    TransactionListener* cons(const InstanceId iid)
    {
        listener.init();
        return &listener.getRef().listener;
    }

    void destroy()
    {
        listener.destroy();
    }
private:
    using ListenerType = ListenerWrap<T_LISTENER>;
    DefaultPlacement<ListenerType> listener;
};

template<>
struct TransactionListenerTraits<NilTransactionListener>
{
    TransactionListener* cons(const InstanceId iid)
    {
        return &NilTransactionListener::getInstance();
    }

    void destroy()
    {
    }
};


template<typename T_CONTEXT, typename T_LISTENER, typename T_TIMERMANAGER>
struct GenericTransaction : AbstractTransaction
{
private:
    void doInit()
    {
        context.init();
        timer.init();
        p_listener = listener.cons(getIID());
    }

    void doDestroy()
    {
        if(initialized)
        {
            p_listener = nullptr;
            initialized = false;
            context.destroy();
            timer.destroy();
            listener.destroy();
        }
    }
public:
    GenericTransaction(const InstanceId iid): AbstractTransaction(iid),
                                                p_listener(nullptr),
                                                initialized(true)
    {
        doInit();
    }

    ~GenericTransaction()
    {
        doDestroy();
    }

    OVERRIDE(void init(const InstanceId &iid))
    {
        if(!initialized)
        {
            AbstractTransaction::init(iid);
            doInit();
            initialized = true;
        }
    }

    OVERRIDE(void destroy())
    {
        doDestroy();
    }

    OVERRIDE(TransactionListener* getListener())
    {
        return p_listener;
    }

public:

    dci::Unknown* getUserContext()
    {
       return context.getObject();
    }

    const TimerInfo* getTimerInfo()
    {
        timer.getObject()->load();
        return timer.getObject();
    }

    T_CONTEXT& getContext() const
    {
        return context.getRef();
    }

    const InstanceId getIID()const
    {
        return iid;
    }


private:
    DefaultPlacement<T_CONTEXT> context;
    DefaultPlacement<T_TIMERMANAGER> timer;
    TransactionListenerTraits<T_LISTENER> listener;
    TransactionListener *p_listener;
    bool initialized;
};

TSL_NS_END

#endif /* H41037034_2B25_4F59_BF43_5B607BAA5DD0 */
