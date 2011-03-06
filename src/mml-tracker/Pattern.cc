#include <assert.h>

#include "Pattern.h"
#include "Track.h"

Pattern::Pattern(uint32_t numTracks) {
  assert(numTracks > 0);

  this->numTracks = numTracks;
  tracks = new Track*[numTracks];

  for (uint64_t i = 0; i < numTracks; i++) {
    tracks[i] = NULL;
  }
}

Pattern::~Pattern() {
  delete[] tracks;
}

void Pattern::setTrack(uint32_t index, Track* track) {
  assert(index < numTracks);
  tracks[index] = track;
}

uint32_t Pattern::getNumTracks() const {
  return numTracks;
}

Track* Pattern::getTrack(uint32_t index) const {
  assert(index < numTracks);
  return tracks[index];
}
