#include "../include/mock_status.hh"

namespace cavimodule::_testing {

MockLaunchStatus::MockLaunchStatus()
  : ARM{ 0 }
  , ABORT{ 0 }
  , LAUNCH{ 0 }
  , QDM{ 0 }
  , STABILIZE{ 0 }
{
}

MockLaunchStatus::~MockLaunchStatus() {}

void
MockLaunchStatus::reset()
{
  ARM = 0;
  ABORT = 0;
  LAUNCH = 0;
  QDM = 0;
  STABILIZE = 0;
}

}