#ifndef MMLTRACKER_SONG_H
#define MMLTRACKER_SONG_H

#include <stdint.h>
#include <string>

class Sequence;

class Song {
public:
  Song();

  void setSongName(const std::string& songName);
  const std::string& getSongName() const;

  void setArtist(const std::string& artist);
  const std::string& getArtist() const;

  void setMaker(const std::string& maker);
  const std::string& getMaker() const;

  void setTempo(uint64_t tempo);
  uint64_t getTempo() const;

  void setSpeed(uint64_t speed);
  uint64_t getSpeed() const;

  const Sequence& getSequence() const;
private:
  Sequence sequence;

  // Name of the song
  std::string song;

  // Name of the artist
  std::string artist;

  // "Maker" information - app used, copyright date, etc.
  std::string maker;

  // Multiplier on tempo
  uint64_t speed;

  // Tempo of the song
  uint64_t tempo;
};

#endif // MMLTRACKER_SONG_H
