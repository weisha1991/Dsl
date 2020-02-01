#ifndef CODE_INCLUDE_L0_INFRA_UTILS_INSTANCEIDHELPER_H_
#define CODE_INCLUDE_L0_INFRA_UTILS_INSTANCEIDHELPER_H_

#include <functional>
#include "l0-infra/base/dci/Unknown.h"

struct InstFunc
{
    std::function<void(dci::Unknown*)> updateContext;
    dci::Unknown *commIf;
};



#endif /* CODE_INCLUDE_L0_INFRA_UTILS_INSTANCEIDHELPER_H_ */
