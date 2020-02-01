#ifndef CODE_INCLUDE_L0_INFRA_TRANS_DSL_ROLE_SIMPLEASYNCROLE_H_
#define CODE_INCLUDE_L0_INFRA_TRANS_DSL_ROLE_SIMPLEASYNCROLE_H_

#include <l0-infra/base/Keywords.h>
#include <l0-infra/event/concept/EventId.h>
#include <l0-infra/trans-dsl/role/AsyncRole.h>
#include <l0-infra/trans-dsl/utils/EventHandlerRegistry.h>

using ev::EventId;
using tsl::EventHandlerRegistry;

TSL_NS_BEGIN

struct SimpleAsyncRole: AsyncRole
{
    OVERRIDE(Status handleEvent(const Event &));
    OVERRIDE(void stop());

    template<typename T>
    Status waitOn(const EventId eventId, T* thisPointer,
                      Status (T::*handler)(const Event&), bool = false)
    {
        return registry.addHandler(eventId, thisPointer, handler, false);
    }

    Status waitUntouchEvent(const EventId event);
private:
    virtual void doStop() {}

private:
    EventHandlerRegistry registry;
};

TSL_NS_END

#endif /* CODE_INCLUDE_L0_INFRA_TRANS_DSL_ROLE_SIMPLEASYNCROLE_H_ */
