#include <QObject>

#include "MockPlatformInfo.h"

MockPlatformInfo::MockPlatformInfo()
  : PlatformInfo(NUM_CHANNELS, DEFAULT_TEMPO, DEFAULT_SPEED) {

  channelNames.push_back(QObject::tr("Track1"));
  channelNames.push_back(QObject::tr("Track2"));
  channelNames.push_back(QObject::tr("Track3"));
}
