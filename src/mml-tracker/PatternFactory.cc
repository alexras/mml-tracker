#include "PatternFactory.h"
#include "Pattern.h"
#include "PlatformInfo.h"

PatternFactory::PatternFactory(const PlatformInfo& _platformInfo)
  : platformInfo(_platformInfo) {
}

Pattern* PatternFactory::newPattern() {
  return new Pattern(platformInfo.getNumChannels());
}
