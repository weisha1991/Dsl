/*
 * main.cpp
 *
 *  Created on: 2019Äê8ÔÂ3ÈÕ
 *      Author: zhengbinlong
 */

#include <l3-trans/testTrans.h>
#include "l3-trans/AddTrans.h"

#include <iostream>
#include "l0-infra/trans-dsl/sched/helper/TransactionHelper.h"

using namespace tsl;
using namespace ev;
namespace
{

	struct EntryInst: transExample
	{


	};

	EntryInst mccInst;

}

int main()
{

	std::cout << "StartTrans" <<std::endl;
	mccInst.handleEvent(SimpleEventInfo(1));
}


