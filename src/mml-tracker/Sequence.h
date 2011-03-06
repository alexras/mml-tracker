#ifndef MMLTRACKER_SEQUENCE_H
#define MMLTRACKER_SEQUENCE_H

#include <QString>
#include <list>
#include <stdint.h>
#include <vector>

#include "TrackBank.h"

class Pattern;

class Sequence {
public:
  Sequence(const TrackBank& trackBank, uint32_t numTracks,
           const std::vector<QString>& trackNames);

  void addNewPatternAfter(Pattern* nextPattern);
  void removePattern(Pattern* pattern);

  // Adds a new pattern to the end of the pattern list
  void addNewPattern();

  // Removes the last pattern from the pattern list
  void removeLastPattern();

  uint32_t getNumPatterns() const;
  uint32_t getNumTracks() const;

  Pattern* getPattern(uint32_t index) const;

  const QString& getTrackName(uint32_t index) const;

  const TrackBank& getTrackBank() const;
private:
  const uint32_t numTracks;
  const std::vector<QString>& trackNames;

  std::vector<Pattern*> patterns;
  const TrackBank& trackBank;
};


#endif // MMLTRACKER_SEQUENCE_H
