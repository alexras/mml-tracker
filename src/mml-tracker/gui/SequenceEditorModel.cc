#include "SequenceEditorModel.h"
#include "mml-tracker/Pattern.h"
#include "mml-tracker/Sequence.h"
#include "mml-tracker/Track.h"

SequenceEditorModel::SequenceEditorModel(Sequence& _sequence,
                                         QObject* parent)
  : QAbstractTableModel(parent), sequence(_sequence) {
}

int SequenceEditorModel::rowCount(const QModelIndex & parent) const {
  Q_UNUSED(parent);

  return sequence.getNumPatterns();
}

int SequenceEditorModel::columnCount(const QModelIndex & parent) const {
  Q_UNUSED(parent);

  return sequence.getNumTracks();
}

QVariant SequenceEditorModel::data(const QModelIndex& index, int role) const {
  if (!index.isValid()) {
    return QVariant();
  }

  int row = index.row();
  int col = index.column();

  if (row < 0 || col < 0) {
    return QVariant();
  }

  Pattern* pattern = sequence.getPattern(row);

  if (pattern == NULL) {
    return QVariant();
  }

  Track* track = pattern->getTrack(col);

  if (track == NULL) {
    return QVariant();
  }

  return QString(track->getTrackID());
}

QVariant SequenceEditorModel::headerData(
  int section, Qt::Orientation orientation, int role) const {

  // If you're not displaying, I don't care.
  if (role != Qt::DisplayRole) {
    return QVariant();
  }

  if (section >= sequence.getNumTracks()) {
    return QVariant();
  }

  if (orientation == Qt::Horizontal) {
    // tr() == translate
    return QString(sequence.getTrackName(section));
  } else {
    return QVariant();
  }
}

Qt::ItemFlags SequenceEditorModel::flags(const QModelIndex& index) const {
  if (!index.isValid()) {
    // If the index is invalid, return some dummy flag
    return Qt::ItemIsEnabled;
  } else {
    // Otherwise, note that the item is editable.
    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
  }
}

bool SequenceEditorModel::insertRows(int position, int rows,
                                     const QModelIndex& index) {
  Q_UNUSED(index);

  // Make sure connected views are aware that we are adding rows

  // FIXME: Not sure I shouldn't be using 'index' instead of creating a new
  // object here
  beginInsertRows(QModelIndex(), position, position + rows - 1);

  for (int row = 0; row < rows; row++) {
    sequence.addNewPattern(position);
  }

  endInsertRows();
  return true;
}

bool SequenceEditorModel::removeRows(int position, int rows,
                                     const QModelIndex& index) {
  Q_UNUSED(index);

  // FIXME: Not sure I shouldn't be using 'index' instead of creating a new
  // object here
  beginRemoveRows(QModelIndex(), position, position + rows - 1);

  for (int row = 0; row < rows; row++) {
    sequence.removePattern(position);
  }

  endRemoveRows();
  return true;
}
