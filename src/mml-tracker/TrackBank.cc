#include <assert.h>

#include "Track.h"
#include "TrackBank.h"

TrackBank::TrackBank() {
  guid = 0;
}

Track* TrackBank::newTrack() {
  Track* track = new Track(guid++);
  tracks.push_back(track);
  return track;
}

Track* TrackBank::getTrack(uint32_t id) const {
  if (id >= guid) {
    return NULL;
  } else {
    return tracks[id];
  }
}

uint32_t TrackBank::getLargestTrackNumber() const {
  assert(guid > 0);
  return guid - 1;
}
