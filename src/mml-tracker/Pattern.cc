#include "Pattern.h"
#include "Track.h"

Pattern::Pattern(uint32_t numTracks) {
  tracks = new Track*[numTracks];
}

Pattern::~Pattern() {
  delete[] tracks;
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
