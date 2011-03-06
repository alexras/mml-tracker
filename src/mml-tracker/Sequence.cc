#include <algorithm>
#include <cassert>

#include "Pattern.h"
#include "Sequence.h"

Sequence::Sequence(
  const TrackBank& _trackBank, uint32_t _numTracks,
  const std::vector<QString>& _trackNames)
  : trackBank(_trackBank), numTracks(_numTracks), trackNames(_trackNames) {
}

void Sequence::addNewPatternAfter(Pattern* nextPattern) {
  Pattern* pattern = new Pattern(numTracks);

  for (std::vector<Pattern*>::iterator iter = patterns.begin();
       iter != patterns.end(); iter++) {
    if (*iter == nextPattern) {
      patterns.insert(iter + 1, pattern);
      break;
    }
  }
}

void Sequence::removePattern(Pattern* pattern) {
  for (std::vector<Pattern*>::iterator iter = patterns.begin();
       iter != patterns.end(); iter++) {
    if (*iter == pattern) {
      patterns.erase(iter);
      break;
    }
  }
}

void Sequence::addNewPattern() {
  patterns.push_back(new Pattern(numTracks));
}

void Sequence::removeLastPattern() {
  std::vector<Pattern*>::iterator iter = patterns.end();
  iter--;
  patterns.erase(iter);
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
