#ifndef CODE_INCLUDE_L1_DOMAIN_CELLSTATE_H_
#define CODE_INCLUDE_L1_DOMAIN_CELLSTATE_H_

#include "l0-infra/base/dci/InterfaceDef.h"

UNKNOWN_INTERFACE(CellState, 0x20200132)
{
    bool isCelSetup() const {return state == CELL_SETUP; }
private:
    enum {CELL_SETUP, CELL_RELEASE} state = CELL_SETUP;
};

#endif /* CODE_INCLUDE_L1_DOMAIN_CELLSTATE_H_ */
