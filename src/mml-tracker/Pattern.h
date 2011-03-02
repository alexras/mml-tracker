#ifndef MMLTRACKER_PATTERN_H
#define MMLTRACKER_PATTERN_H

#include <stdint.h>

class Track;

class Pattern {
public:
  Pattern(uint32_t numTracks);
  virtual ~Pattern();

  uint32_t getNumTracks() const;

  void setTrack(uint32_t index,
Track* track);

  Track* getTrack(uint32_t index) const;
private:
  uint32_t numTracks;
  Track** tracks;
};

#endif // MMLTRACKER_PATTERN_H
