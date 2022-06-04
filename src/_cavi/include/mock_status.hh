#include <cstdint>

namespace cavimodule::_testing {

class MockLaunchStatus
{
  /*
  Very basic status structure, presumably will be
  relaced when the code is actually reading from
  GPIO pins or getting actual data from the LS

  i.e. TODO: Remove this when able
  */

public:
  uint32_t ARM;
  uint32_t ABORT;
  uint32_t QDM;
  uint32_t LAUNCH;
  uint32_t STABILIZE;

  MockLaunchStatus();
  ~MockLaunchStatus();
  void reset();
};

}