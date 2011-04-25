#ifndef MMLTRACKER_PLATFORM_INFO_H
#define MMLTRACKER_PLATFORM_INFO_H

#include <QString>
#include <stdint.h>
#include <vector>

class PlatformInfo {
public:
  PlatformInfo(uint32_t numChannels, uint32_t defaultNotesPerPattern,
               uint32_t defaultTempo, uint32_t defaultSpeed);

  uint32_t getNumChannels() const;
  uint32_t getDefaultNumNotesPerPattern() const;
  const QString& getChannelName(uint32_t id) const;
  uint32_t getDefaultTempo() const;
  uint32_t getDefaultSpeed() const;

protected:
  const uint32_t numChannels;
  const uint32_t defaultNotesPerPattern;
  const uint32_t defaultTempo;
  const uint32_t defaultSpeed;
  std::vector<QString> channelNames;
};

#endif // MMLTRACKER_PLATFORM_INFO_H
