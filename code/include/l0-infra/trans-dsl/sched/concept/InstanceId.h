/*
 * InstanceId.h
 *
 * Created on: Apr 21, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef INSTANCEID_H_
#define INSTANCEID_H_

#include "l0-infra/trans-dsl/tsl.h"

TSL_NS_BEGIN

struct InstanceId
{
    enum
    {
        INVALID_IID = 0xFFFFFFFF
    };

    InstanceId()
    {
        u.value = INVALID_IID;
    }

    explicit InstanceId(const WORD32 value)
    {
        u.value = value;
    }


    explicit InstanceId(const S32 value)
    {
        u.value = value;
    }


    explicit InstanceId(void *p)
    {
        u.p = p;
    }

    template<typename T>
    explicit InstanceId(T *p)
    {
        u.p = (void*)p;
    }

    InstanceId(const InstanceId &rhs)
    {
        u.p = rhs.u.p;
    }

    operator WORD32() const
    {
        return u.value;
    }

    bool operator==(const InstanceId &rhs) const
    {
        return rhs.u.p == u.p;
    }

    bool operator !=(const InstanceId &rhs) const
    {
        return !(*this == rhs);
    }

    InstanceId& operator=(const InstanceId &rhs)
    {
        u.p = rhs.u.p;
        return *this;
    }

    bool isValid() const
    {
        return u.value != INVALID_IID;
    }

    template<typename T>
    T* toPointer() const
    {
        return isValid() ? (T*)(u.p) : 0;
    }

private:
    union
    {
        WORD32 value;
        void *p;
    }u;

};
TSL_NS_END

#endif /* INSTANCEID_H_ */
