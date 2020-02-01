#ifndef CODE_INCLUDE_L4_SCHED_OBJ_KEY_H_
#define CODE_INCLUDE_L4_SCHED_OBJ_KEY_H_

#include <l0-infra/base/BaseTypes.h>
#include <string>

struct Key
{
    std::string toStr() const;
    void update(U32 id);
    U32 id;
};


#endif /* CODE_INCLUDE_L4_SCHED_OBJ_KEY_H_ */
