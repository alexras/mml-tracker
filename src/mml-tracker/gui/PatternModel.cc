#include "Note.h"
#include "PatternModel.h"

Q_DECLARE_METATYPE(Note*)

PatternModel::PatternModel(Pattern* pattern, const PlatformInfo& _platformInfo,
                           QObject* parent)
: QObject(parent), platformInfo(_platformInfo) {
  this->pattern = pattern;
}

Note* PatternModel::getNote(const QModelIndex& index) {
  int row = index.row();

  return getTrack(index)->getNote(row);
}

NoteSubPart PatternModel::getNoteSubPart(const QModelIndex& index) const {
  // Four columns per track: note, instrument, volume, effect

  int subpart = index.column() % NUM_NOTE_SUBPARTS;
}

Track* PatternModel::getTrack(const QModelIndex& index) {
  int column = index.column();
  return pattern->getTrack(column / NUM_NOTE_SUBPARTS);
}

int PatternModel::rowCount(const QModelIndex & parent) const {
  return pattern->getNumNotes();
}

int PatternModel::columnCount(const QModelIndex & parent) const {
  return pattern->getNumTracks() * NUM_NOTE_SUBPARTS;
}

QVariant PatternModel::data(const QModelIndex& index, int role) const {
  Note* note = getNote(index);

  if (note == NULL) {
    return QVariant();
  } else {
    return QVariant::fromValue(note);
  }
}

bool PatternModel::setData(const QModelIndex& index, const QVariant& value,
                           int role) {
  if (!value.canConvert<Note*>()) {
    return false;
  }

  Note* newNote = value.value<Note*>();

  if (newNote == NULL) {
    return false;
  }

  Track* currentTrack = getTrack(index);
  currentTrack->setNote(index.row(), newNote);

  return true;
}

QVariant PatternModel::headerData(int section, Qt::Orientation orientation,
                                  int role) const {
  if (role == Qt::DisplayRole) {
    if (orientation == Qt::Horizontal) {
      return QString("%1").arg(section, 2, 16, QChar('0')).toUpper();
    } else {
      return platformInfo.getChannelName(section);
    }
  } else {
    return QVariant();
  }
}

Qt::ItemFlags PatternModel::flags(const QModelIndex& index) const {

}

