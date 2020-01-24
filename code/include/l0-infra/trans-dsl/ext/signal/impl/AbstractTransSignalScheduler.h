#ifndef HDB63EDCC_81C9_4912_8D36_8FC159BC5AC5
#define HDB63EDCC_81C9_4912_8D36_8FC159BC5AC5

#include <l0-infra/base/Status.h>

#include "l0-infra/trans-dsl/ext/signal/concept/TransSignalScheduler.h"

TSL_NS_BEGIN

struct AbstractTransSignalScheduler
    : TransSignalScheduler
{
    AbstractTransSignalScheduler();

    TransSignalId fetchSignal()
    {
        if(signalBitmap == 0) return 0xFF;

        return doFetchSignal();
    }

private:
    OVERRIDE(Status broadcast(const TransSignalId));
    TransSignalId doFetchSignal();

protected:
    U32 signalBitmap;
};

TSL_NS_END

#endif /* HDB63EDCC_81C9_4912_8D36_8FC159BC5AC5 */
