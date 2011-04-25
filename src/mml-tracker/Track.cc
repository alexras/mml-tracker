#include <assert.h>

#include "Note.h"
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

void Track::setNote(Note* note, uint32_t position) {
  assert(position < length);

  Note* oldNote = notes[position];

  if (oldNote != NULL) {
    delete oldNote;
  }

  notes[position] = note;
}

uint32_t Track::getTrackID() const {
  return trackID;
}

const Note* Track::getNote(uint32_t index) const {
  return notes[index];
}
