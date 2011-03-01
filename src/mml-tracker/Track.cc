#include <assert.h>

#include "Track.h"

Track::Track(uint32_t _trackID) : trackID(_trackID) {
  length = 0;
}

void Track::setLength(uint32_t length) {
  this->length = length;
}

uint32_t Track::getLength() const {
  return length;
}

void Track::addNote(Note* note, uint32_t position) {
  assert(position < length);
  notes[position] = note;
}

uint32_t Track::getTrackID() const {
  return trackID;
}
