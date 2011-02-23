#include "Pattern.h"

Pattern::Pattern(uint64_t numTracks) {
  tracks = new Track*[numTracks];
}

Pattern::~Pattern() {
  delete[] tracks;
}
