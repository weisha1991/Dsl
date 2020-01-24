#ifndef INCLUDE_CUB_DCI_LISTBASEDROLE_H_
#define INCLUDE_CUB_DCI_LISTBASEDROLE_H_

#include <l0-infra/base/dci/Role.h>
#include <l0-infra/repo/list/ListElem.h>

#define DEFINE_LIST_BASED_ROLE(role) \
   DEFINE_ROLE(role) EXTENDS(ListElem<role>)

#endif /* INCLUDE_CUB_DCI_LISTBASEDROLE_H_ */
