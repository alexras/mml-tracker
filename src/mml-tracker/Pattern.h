#ifndef MMLTRACKER_PATTERN_H
#define MMLTRACKER_PATTERN_H

#include "Track.h"

class Pattern {
public:
  Pattern(uint64_t numTracks);
  virtual ~Pattern();
  
private:
  Track** tracks;
};

#endif // MMLTRACKER_PATTERN_H
