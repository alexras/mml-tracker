#include <QObject>
#include <QString>

#include "PlatformInfo.h"
#include "Sequence.h"
#include "Song.h"

Song::Song(const PlatformInfo& _platformInfo)
  : platformInfo(_platformInfo), title(QObject::tr("Song Name")),
    artist(QObject::tr("Artist")), maker(QObject::tr("Maker")) {

  tempo = platformInfo.getDefaultTempo();
  speed = platformInfo.getDefaultSpeed();
  sequence = NULL;
  tracks = NULL;
}

Song::~Song() {
  if (sequence != NULL) {
    delete sequence;
  }

  if (tracks != NULL) {
    delete tracks;
  }
}

void Song::setSongName(const QString& songName) {
  title = songName;
}

const QString& Song::getSongName() const {
  return title;
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

Sequence* Song::getSequence() const {
  return sequence;
}

void Song::setTrackBank(TrackBank* tracks) {
  this->tracks = tracks;
}

TrackBank* Song::getTrackBank() const {
  return tracks;
}
