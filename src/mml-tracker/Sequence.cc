#include <algorithm>
#include <cassert>

#include "Pattern.h"
#include "Sequence.h"

Sequence::Sequence(
  const TrackBank& _trackBank, uint32_t _numTracks,
  const std::vector<QString>& _trackNames)
  : trackBank(_trackBank), numTracks(_numTracks), trackNames(_trackNames) {
}

void Sequence::addNewPattern(uint32_t position) {
  Pattern* pattern = new Pattern(numTracks);
  patterns.insert(patterns.begin() + position, pattern);
}

void Sequence::removePattern(uint32_t position) {
  patterns.erase(patterns.begin() + position);
}

uint32_t Sequence::getNumPatterns() const {
  return patterns.size();
}

uint32_t Sequence::getNumTracks() const {
  return numTracks;
}

Pattern* Sequence::getPattern(uint32_t index) const {
  if (index >= patterns.size()) {
    return NULL;
  } else {
    return patterns[index];
  }
}

const QString& Sequence::getTrackName(uint32_t index) const {
  assert(index < trackNames.size());

  return trackNames[index];
}

const TrackBank& Sequence::getTrackBank() const {
  return trackBank;
}
