#include <cstdint>

namespace cavimodule::_testing {

class MockLaunchStatus
{
  /*
  Very basic status structure that acts as 
  abstraction layer for testing when not running
  directly on the launch hardware.
  
  i.e. This class should be ignored when the code 
  is actually reading from GPIO pins or sensors
  durring a production run.
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