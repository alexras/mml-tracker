#include <assert.h>
#include "PlatformInfo.h"

PlatformInfo::PlatformInfo(uint32_t _numChannels, uint32_t _defaultTempo,
                           uint32_t _defaultSpeed)
  : numChannels(_numChannels),
    defaultTempo(_defaultTempo),
    defaultSpeed(_defaultSpeed)
{}

uint32_t PlatformInfo::getNumChannels() const {
  return numChannels;
}

const QString& PlatformInfo::getChannelName(uint32_t id) const {
  assert(id < numChannels);
  return channelNames.at(id);
}

uint32_t PlatformInfo::getDefaultTempo() const {
  return defaultTempo;
}

uint32_t PlatformInfo::getDefaultSpeed() const {
  return defaultSpeed;
}
