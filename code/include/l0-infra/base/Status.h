#ifndef H5712E60C_DEF5_4A3B_93C0_C074CD80C63B
#define H5712E60C_DEF5_4A3B_93C0_C074CD80C63B

#include <l0-infra/base/BaseTypes.h>



typedef U32 Status;

enum : Status
{
    CUB_RESERVED_FAILURE = 0x80000000
};

inline bool isSuccStatus(Status status)
{
    return (status & CUB_RESERVED_FAILURE) == 0;
}

inline bool isFailStatus(Status status)
{
    return !isSuccStatus(status);
}

inline constexpr Status succStatus(const U32 status)
{
    return status;
}

inline constexpr Status failStatus(const U32 status)
{
    return status | CUB_RESERVED_FAILURE;
}



enum : U16
{
    CUB_INVALID_U16 = 0xFFFF
};

enum : U32
{
    CUB_INVALID_U32 = 0xFFFFFFFF
};

/////////////////////////////////////////////////////////////////

enum CubStatus:Status
{
    CUB_SUCCESS =succStatus(0),

    CUB_FATAL_BUG =failStatus(0x7FFFFFFE),
    CUB_FAILURE   =failStatus(0x7FFFFFFF)
};

/////////////////////////////////////////////////////////////////
#define __CUB_FAILED(result)  isFailStatus(result)

#define CUB_IS_SUCC_STATUS(status)isSuccStatus(status)


#endif
