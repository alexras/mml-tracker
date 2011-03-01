#ifndef MMLTRACKER_SEQUENCE_H
#define MMLTRACKER_SEQUENCE_H

#include <QString>
#include <stdint.h>
#include <vector>

class Pattern;

class Sequence {
public:
  Sequence(uint32_t numTracks, const std::vector<QString>& trackNames);

  void addNewPattern(uint32_t position);
  void removePattern(uint32_t position);

  uint32_t getNumPatterns() const;
  uint32_t getNumTracks() const;

  Pattern* getPattern(uint32_t index) const;

  const QString& getTrackName(uint32_t index) const;
private:
  const uint32_t numTracks;
  const std::vector<QString>& trackNames;

  std::vector<Pattern*> patterns;
};


#endif // MMLTRACKER_SEQUENCE_H
