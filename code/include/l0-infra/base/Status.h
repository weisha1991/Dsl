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

#define DEF_SIMPLE_STATUS(status, value) \
    const Status status = value

#define DEF_STATUS(status, value )\
        DEF_SIMPLE_STATUS(USI_##status, value);

#define DEF_SUCC_STATUS(status, val) DEF_STATUS(status, val)

DEF_SUCC_STATUS(SUCCESS, 0);
DEF_SUCC_STATUS(CONTINUE, 1);
DEF_SUCC_STATUS(UNKNOWN, 2);
DEF_SUCC_STATUS(RESTART_REQUIED, 3);
DEF_SUCC_STATUS(STOP, 4);

#define FAILED_STATUS_VALUE(value) ((0x80000000) | (value))

#define DEF_SIMPLE_FAILED_STATUS(status ,value) \
    DEF_SIMPLE_STATUS(status, value)
#define DEF_FAILED_STATUS(status, value) \
        DEF_SIMPLE_STATUS(USI_##status, FAILED_STATUS_VALUE(value))

DEF_FAILED_STATUS(FAILED, 0);
DEF_FAILED_STATUS(FATAL_BUG, 1);
DEF_FAILED_STATUS(TIMEOUT, 2);

const Status INTETNAL_ERROR_START = 0x00010000;

#define DEF_COMMON_ERROR(errorcode, index)\
        DEF_SIMPLE_FAILED_STATUS(errorcode, (INTETNAL_ERROR_START + index))



#endif
