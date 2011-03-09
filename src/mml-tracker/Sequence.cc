#include <algorithm>
#include <cassert>

#include "Pattern.h"
#include "Sequence.h"
#include "PatternFactory.h"

Sequence::Sequence(
  const TrackBank& _trackBank, PatternFactory& _patternFactory)
  : trackBank(_trackBank), patternFactory(_patternFactory)
{}

void Sequence::addNewPatternAfter(Pattern* nextPattern) {
  Pattern* pattern = patternFactory.newPattern();

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
  patterns.push_back(patternFactory.newPattern());
}

void Sequence::removeLastPattern() {
  std::vector<Pattern*>::iterator iter = patterns.end();
  iter--;
  patterns.erase(iter);
}

uint32_t Sequence::getNumPatterns() const {
  return patterns.size();
}

Pattern* Sequence::getPattern(uint32_t index) const {
  if (index >= patterns.size()) {
    return NULL;
  } else {
    return patterns[index];
  }
}
