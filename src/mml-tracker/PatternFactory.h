#ifndef MMLTRACKER_PATTERN_FACTORY_H
#define MMLTRACKER_PATTERN_FACTORY_H

class Pattern;
class PlatformInfo;

class PatternFactory {
public:
  PatternFactory(const PlatformInfo& platformInfo);

  Pattern* newPattern();

private:
  const PlatformInfo& platformInfo;
};

#endif // MMLTRACKER_PATTERN_FACTORY_H
