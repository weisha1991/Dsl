#ifndef CODE_INCLUDE_L0_INFRA_TRANS_DSL_ROLE_ASYNCROLE_H_
#define CODE_INCLUDE_L0_INFRA_TRANS_DSL_ROLE_ASYNCROLE_H_

#include <l0-infra/base/Status.h>
#include <l0-infra/event/concept/Event.h>
#include "l0-infra/base/dci/Role.h"

using ev::Event;

TSL_NS_BEGIN

DEFINE_ROLE(AsyncRole)
{
    ABSTRACT(Status handleEvent(const Event &event));
    ABSTRACT(void stop());
};

TSL_NS_END

#endif /* CODE_INCLUDE_L0_INFRA_TRANS_DSL_ROLE_ASYNCROLE_H_ */
