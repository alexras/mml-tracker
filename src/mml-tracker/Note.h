#ifndef MMLTRACKER_NOTE_H
#define MMLTRACKER_NOTE_H

#include <list>
#include <stdint.h>

class Instrument;
class Effect;

class Note {
public:
  Note();

  void setOctave(uint64_t octave);
  uint64_t getOctave() const;

  void setPitch(uint8_t pitch);
  uint8_t getPitch() const;

  void setVolume(uint64_t volume);
  uint64_t getVolume() const;

  void setInstrument(Instrument* instrument);
  const Instrument* getInstrument() const;

  void addEffect(Effect* effect);
private:
  uint64_t octave;
  uint8_t pitch;
  uint64_t volume;

  Instrument* instrument;
  std::list<Effect*> effects;
};

#endif // MMLTRACKER_NOTE_H
