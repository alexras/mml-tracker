#ifndef MMLTRACKER_TRACK_BANK_H
#define MMLTRACKER_TRACK_BANK_H

#include <stdint.h>
#include <vector>

// This class stores all tracks and provides a GUID for track IDs

class Track;

class TrackBank {
public:
  TrackBank();

  Track* newTrack();

  Track* getTrack(uint32_t id) const;

  uint32_t getLargestTrackNumber() const;
private:
  uint32_t guid;
  std::vector<Track*> tracks;
};

#endif // MMLTRACKER_TRACK_BANK_H
