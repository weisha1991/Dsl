/*
 * Key.cpp
 *
 *  Created on: 2020年1月31日
 *      Author: zhengbinlong
 */

#include <l0-infra/utils/InstKeyHelper.h>
#include "l4-sched/obj/Key.h"

std::string Key::toStr() const
{
    return make_key(id);
}

void Key::update(U32 newId)
{
    this->id = newId;
}

