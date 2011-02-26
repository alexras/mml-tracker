#include "Pattern.h"
#include "Sequence.h"

Sequence::Sequence() {

}

void Sequence::addPattern(Pattern* pattern) {
  patterns.push_back(pattern);
}
