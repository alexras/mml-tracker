#include "Note.h"

Note::Note() {
  octave = 0;
  pitch = 0;
  volume = 0;
  silence = false;
  instrument = NULL;
}

Note::Note(const Note& note) {
  octave = note.octave;
  pitch = note.pitch;
  volume = note.volume;
  silence = note.silence;
  instrument = note.instrument;
}

void Note::setOctave(uint64_t octave) {
  this->octave = octave;
}

uint64_t Note::getOctave() const {
  return octave;
}

void Note::setPitch(uint8_t pitch) {
  this->pitch = pitch;
}

uint8_t Note::getPitch() const {
  return pitch;
}

void Note::setVolume(uint64_t volume) {
  this->volume = volume;
}

uint64_t Note::getVolume() const {
  return volume;
}

void Note::setInstrument(Instrument* instrument) {
  this->instrument = instrument;
}

const Instrument* Note::getInstrument() const {
  return instrument;
}

void Note::addEffect(Effect* effect) {
  effects.push_back(effect);
}
