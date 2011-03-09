#ifndef MMLTRACKER_SEQUENCE_H
#define MMLTRACKER_SEQUENCE_H

#include <QString>
#include <list>
#include <stdint.h>
#include <vector>

#include "TrackBank.h"

class Pattern;
class PatternFactory;

class Sequence {
public:
  Sequence(const TrackBank& trackBank, PatternFactory& patternFactory);

  void addNewPatternAfter(Pattern* nextPattern);
  void removePattern(Pattern* pattern);

  // Adds a new pattern to the end of the pattern list
  void addNewPattern();

  // Removes the last pattern from the pattern list
  void removeLastPattern();

  uint32_t getNumPatterns() const;

  Pattern* getPattern(uint32_t index) const;

private:
  const TrackBank& trackBank;
  PatternFactory& patternFactory;

  std::vector<Pattern*> patterns;
};


#endif // MMLTRACKER_SEQUENCE_H
