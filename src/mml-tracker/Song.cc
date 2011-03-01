#include <QObject>
#include <QString>

#include "Sequence.h"
#include "Song.h"

Song::Song()
  : song(QObject::tr("Song Name")), artist(QObject::tr("Artist")),
    maker(QObject::tr("Maker")) {
}

void Song::setSongName(const QString& songName) {
  song = songName;
}

const QString& Song::getSongName() const {
  return song;
}

void Song::setArtist(const QString& artist) {
  this->artist = artist;
}

const QString& Song::getArtist() const {
  return artist;
}

void Song::setMaker(const QString& maker) {
  this->maker = maker;
}

const QString& Song::getMaker() const {
  return maker;
}

void Song::setTempo(uint32_t tempo) {
  this->tempo = tempo;
}

uint32_t Song::getTempo() const {
  return tempo;
}

void Song::setSpeed(uint32_t speed) {
  this->speed = speed;
}

uint32_t Song::getSpeed() const {
  return speed;
}

void Song::setSequence(Sequence* sequence) {
  this->sequence = sequence;
}

const Sequence* Song::getSequence() const {
  return sequence;
}
