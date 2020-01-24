#include <l0-infra/base/BaseTypes.h>
#include <l0-infra/base/log/log.h>
#include <l0-infra/event/concept/EventId.h>
#include "gtest/gtest.h"

extern "C" void MccEntry(U32 msgId, void *msg, U32 msgSize);

namespace
{
    class MccPower : public ::testing::Test
    {
    public:
        MccPower() {
      }

      virtual ~MccPower() {
      }

      virtual void SetUp() override
      {
          DBG_LOG("Setup");
      }

      virtual void TearDown() override
      {

      }
    };

}


TEST_F(MccPower, should_mcc_power_up)
{
    U32 msg = 4;
    MccEntry(9, &msg, sizeof(msg));
    MccEntry(4, &msg, sizeof(msg));
}


