#include "Pattern.h"
#include "Track.h"

Pattern::Pattern(uint32_t numTracks) {
  tracks = new Track*[numTracks];

  for (uint64_t i = 0; i < numTracks; i++) {
    tracks[i] = NULL;
  }
}

Pattern::~Pattern() {
  delete[] tracks;
}

void Pattern::setTrack(uint32_t index, Track* track) {
  tracks[index] = track;
}

uint32_t Pattern::getNumTracks() const {
  return numTracks;
}

Track* Pattern::getTrack(uint32_t index) const {
  if (index >= numTracks) {
    return NULL;
  } else {
    return tracks[index];
  }
}
