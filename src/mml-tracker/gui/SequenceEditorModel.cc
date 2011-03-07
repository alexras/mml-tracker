#include <QSet>
#include <assert.h>
#include <limits>

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

  // One additional column for the sequence number
  return sequence.getNumTracks() + 1;
}

Pattern* SequenceEditorModel::getPattern(const QModelIndex& index) const {
  int row = index.row();

  if (row < 0) {
    return NULL;
  } else {
    return sequence.getPattern(row);
  }
}

Track* SequenceEditorModel::getTrack(const QModelIndex& index) const {
  int col = index.column() - 1;

  if (col < 0) {
    return NULL;
  }

  Pattern* pattern = getPattern(index);

  if (pattern == NULL) {
    return NULL;
  } else {
    return pattern->getTrack(col);
  }
}

QVariant SequenceEditorModel::data(const QModelIndex& index, int role) const {
  if (!index.isValid()) {
    return QVariant();
  }

  if (role == Qt::UserRole) {
    // The view's delegate is asking us for the maximum value for this cell.
    return QVariant(sequence.getTrackBank().getLargestTrackNumber());
  } else if (role != Qt::DisplayRole && role != Qt::EditRole) {
    return QVariant();
  }

  if (index.column() == 0) {
    return QString("%1").arg(index.row(), 2, 16, QChar('0')).toUpper();
  }

  Track* track = getTrack(index);
  if (track == NULL) {
    return QVariant();
  } else {
    return QString("%1").arg(track->getTrackID(), 2, 16, QChar('0')).toUpper();
  }
}

bool SequenceEditorModel::setData(
  const QModelIndex& index, const QVariant& value, int role) {

  if (role != Qt::EditRole) {
    return false;
  }

  bool conversionSuccessful = false;
  uint32_t trackID = value.toUInt(&conversionSuccessful);

  if (!conversionSuccessful) {
    return false;
  }

  Pattern* pattern = getPattern(index);

  if (pattern == NULL) {
    return false;
  }

  int patternTrackNumber = index.column() - 1;

  Track* newTrack = sequence.getTrackBank().getTrack(trackID);

  if (newTrack == NULL) {
    return false;
  }

  pattern->setTrack(patternTrackNumber, newTrack);
}

QVariant SequenceEditorModel::headerData(
  int section, Qt::Orientation orientation, int role) const {
  // // If you're not displaying, I don't care.
  // if (role != Qt::DisplayRole) {
  //   return QVariant();
  // }

  // if (orientation == Qt::Horizontal) {
  //   if (section >= sequence.getNumTracks() + 1) {
  //     return QVariant();
  //   } else {
  //     if (section == 0) {
  //       return QString("");
  //     } else {
  //       return QString(sequence.getTrackName(section - 1));
  //     }
  //   }
  // } else {
  //   return QVariant();
  // }
  return QVariant();
}

Qt::ItemFlags SequenceEditorModel::flags(const QModelIndex& index) const {
  if (!index.isValid()) {
    // If the index is invalid, return some dummy flag
    return Qt::ItemIsEnabled;
  } else {
    // Pattern headers aren't selectable but not editable
    if (index.column() == 0) {
      return Qt::ItemIsEnabled;
    } else {
      // Otherwise, note that the item is editable.
      return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
    }
  }
}

void SequenceEditorModel::getPatternsFromRowNumbers(
  QSet<uint32_t>& rows, QSet<Pattern*>& patterns, uint32_t& minRow,
  uint32_t& maxRow) {

  minRow = std::numeric_limits<uint32_t>::max();
  maxRow = 0;

  for (QSet<uint32_t>::iterator iter = rows.begin(); iter != rows.end();
       iter++) {
    uint32_t currentRow = *iter;

    minRow = std::min<uint32_t>(currentRow, minRow);
    maxRow = std::max<uint32_t>(currentRow, maxRow);

    Pattern* pattern = sequence.getPattern(currentRow);
    assert(pattern != NULL);
    patterns.insert(pattern);
  }
}

void SequenceEditorModel::insertRows(QSet<uint32_t>& rows) {
  if (rows.size() == 0) {
    uint32_t lastRow = sequence.getNumPatterns() - 1;

    beginInsertRows(QModelIndex(), lastRow, lastRow);
    sequence.addNewPattern();
    endInsertRows();
  } else {
    QSet<Pattern*> patterns;
    uint32_t minRow;
    uint32_t maxRow;

    getPatternsFromRowNumbers(rows, patterns, minRow, maxRow);

    beginInsertRows(QModelIndex(), minRow, maxRow);

    for (QSet<Pattern*>::iterator iter = patterns.begin();
         iter != patterns.end(); iter++) {

      sequence.addNewPatternAfter(*iter);
    }

    endInsertRows();
  }
}

void SequenceEditorModel::removeRows(QSet<uint32_t>& rows) {
  if (rows.size() == 0) {
    uint32_t lastRow = sequence.getNumPatterns() - 1;

    beginRemoveRows(QModelIndex(), lastRow, lastRow);
    sequence.removeLastPattern();
    endRemoveRows();
  } else {
    QSet<Pattern*> patterns;
    uint32_t minRow;
    uint32_t maxRow;

    getPatternsFromRowNumbers(rows, patterns, minRow, maxRow);

    beginRemoveRows(QModelIndex(), minRow, maxRow);

    for (QSet<Pattern*>::iterator iter = patterns.begin();
         iter != patterns.end(); iter++) {
      sequence.removePattern(*iter);
    }

    endRemoveRows();
  }
}
