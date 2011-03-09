#ifndef MMLTRACKER_TEST_MOCK_PLATFORM_INFO_H
#define MMLTRACKER_TEST_MOCK_PLATFORM_INFO_H

#include "mml-tracker/PlatformInfo.h"

class MockPlatformInfo : public PlatformInfo {
public:
  MockPlatformInfo();

private:
  const static uint32_t NUM_CHANNELS = 3;
  const static uint32_t DEFAULT_TEMPO = 150;
  const static uint32_t DEFAULT_SPEED = 1;
};

#endif // MMLTRACKER_TEST_MOCK_PLATFORM_INFO_H
