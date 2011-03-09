#ifndef MMLTRACKER_SONG_H
#define MMLTRACKER_SONG_H

#include <QString>
#include <stdint.h>
#include <string>
#include <vector>

class Effect;
class Instrument;
class PlatformInfo;
class Sequence;
class TrackBank;

class Song {
public:
  Song(const PlatformInfo& platformInfo);
  virtual ~Song();

  const PlatformInfo& getPlatformInfo() const;

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
  Sequence* getSequence() const;

  void setTrackBank(TrackBank* tracks);
  TrackBank* getTrackBank() const;
private:
  const PlatformInfo& platformInfo;

  // The sequence of patterns making up the song
  Sequence* sequence;

  // Bank of all tracks used in the song
  TrackBank* tracks;

  // Name of the song
  QString title;

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
