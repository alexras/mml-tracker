#ifndef MMLTRACKER_SEQUENCE_H
#define MMLTRACKER_SEQUENCE_H

#include <vector>

class Pattern;

class Sequence {
public:
  Sequence();

  void addPattern(Pattern* pattern);

private:
  std::vector<Pattern*> patterns;
};


#endif // MMLTRACKER_SEQUENCE_H
