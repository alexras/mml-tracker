#ifndef MMLTRACKER_PATTERN_H
#define MMLTRACKER_PATTERN_H

#include <stdint.h>
#include <string>

class Track;

class Pattern {
public:
  Pattern(uint32_t numTracks, uint32_t numNotes);
  virtual ~Pattern();

  uint32_t getNumNotes() const;
  uint32_t getNumTracks() const;

  void setTrack(uint32_t index,
Track* track);

  Track* getTrack(uint32_t index) const;
private:
  uint32_t numTracks;
  uint32_t numNotes;
  Track** tracks;
};

#endif // MMLTRACKER_PATTERN_H
