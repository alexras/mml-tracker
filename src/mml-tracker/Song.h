#ifndef MMLTRACKER_SONG_H
#define MMLTRACKER_SONG_H

#include <QString>
#include <stdint.h>
#include <string>

class Effect;
class Instrument;
class Sequence;

class Song {
public:
  Song();

  void setSongName(const QString& songName);
  const QString& getSongName() const;

  void setArtist(const QString& artist);
  const QString& getArtist() const;

  void setMaker(const QString& maker);
  const QString& getMaker() const;

  void setTempo(uint32_t tempo);
  uint32_t getTempo() const;

  void setSpeed(uint32_t speed);
  uint32_t getSpeed() const;

  void setSequence(Sequence* sequence);
  const Sequence* getSequence() const;
private:
  Sequence* sequence;

  // Name of the song
  QString song;

  // Name of the artist
  QString artist;

  // "Maker" information - app used, copyright date, etc.
  QString maker;

  // Multiplier on tempo
  uint32_t speed;

  // Tempo of the song
  uint32_t tempo;

  // All effects used in the song
  std::vector<Effect*> effects;

  // All instruments used in the song
  std::vector<Instrument*> instruments;
};

#endif // MMLTRACKER_SONG_H
