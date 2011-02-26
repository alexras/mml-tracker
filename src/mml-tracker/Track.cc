#include <assert.h>

#include "Track.h"

Track::Track() {
  uint64_t length = 0;
}

void Track::setLength(uint64_t length) {
  this->length = length;
}

uint64_t Track::getLength() const {
  return length;
}

void Track::addNote(Note* note, uint64_t position) {
  assert(position < length);
  notes[position] = note;
}
