#ifndef H38247538_297F_4A80_94D3_8A289788462A
#define H38247538_297F_4A80_94D3_8A289788462A

#include <l0-infra/mem/MsgNewOperator.h>
#include <l0-infra/mem/MsgAllocator.h>



template <typename MSG, typename MSG_ALLOCATOR>
struct GenericMsg : MSG, MsgNewOperator<MSG_ALLOCATOR>
{
};

template <typename MSG, typename MSG_ALLOCATOR = MsgAllocator>
struct AutoMsg
{
    AutoMsg()
    {
        msg = new GenericMsg<MSG, MSG_ALLOCATOR>;        
    }

    ~AutoMsg()
    {
        if(msg != 0)
        {
            msg->operator delete((void*)msg);
            msg = 0;
        }
    }

    MSG* operator->()
    {
        return msg;
    }

    const MSG* getPointer() const
    {
        return msg;
    }

    MSG* getPointer()
    {
        return msg;
    }

    const MSG& getRef() const
    {
        return *msg;
    }

    MSG& getRef()
    {
        return *msg;
    }

private:
    GenericMsg<MSG, MSG_ALLOCATOR>* msg;
};



#endif

