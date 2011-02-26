#include "Sequence.h"
#include "Song.h"

Song::Song()
  : song("Song Name"), artist("Artist"), maker("Maker") {
}

void Song::setSongName(const std::string& songName) {
  song.assign(songName);
}

const std::string& Song::getSongName() const {
  return song;
}

void Song::setArtist(const std::string& artist) {
  this->artist.assign(artist);
}

const std::string& Song::getArtist() const {
  return artist;
}

void Song::setMaker(const std::string& maker) {
  this->maker.assign(maker);
}

const std::string& Song::getMaker() const {
  return maker;
}

void Song::setTempo(uint64_t tempo) {
  this->tempo = tempo;
}

uint64_t Song::getTempo() const {
  return tempo;
}

void Song::setSpeed(uint64_t speed) {
  this->speed = speed;
}

uint64_t Song::getSpeed() const {
  return speed;
}

const Sequence& Song::getSequence() const {
  return sequence;
}
