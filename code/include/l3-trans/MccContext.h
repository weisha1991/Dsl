#ifndef CODE_INCLUDE_L3_TRANS_MCCCONTEXT_H_
#define CODE_INCLUDE_L3_TRANS_MCCCONTEXT_H_


#include <l1-domain/CellState.h>
#include "l0-infra/base/dci/Unknown.h"
#include "l0-infra/base/Keywords.h"

struct MccContext: dci::Unknown
                   , CellState
{

    BEGIN_INTERFACE_TABLE()
        __HAS_INTERFACE(CellState)
    END_INTERFACE_TABLE()
};


#endif /* CODE_INCLUDE_L3_TRANS_MCCCONTEXT_H_ */
