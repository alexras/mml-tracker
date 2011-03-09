#include <QSet>
#include <assert.h>
#include <limits>

#include "SequenceModel.h"
#include "mml-tracker/Pattern.h"
#include "mml-tracker/PlatformInfo.h"
#include "mml-tracker/Sequence.h"
#include "mml-tracker/Track.h"

SequenceModel::SequenceModel(Sequence& _sequence,
                             TrackBank& _trackBank,
                             const PlatformInfo& _platformInfo,
                             QObject* parent)
  : QAbstractTableModel(parent), platformInfo(_platformInfo),
    sequence(_sequence), trackBank(_trackBank) {
}

int SequenceModel::rowCount(const QModelIndex & parent) const {
  Q_UNUSED(parent);

  return sequence.getNumPatterns();
}

int SequenceModel::columnCount(const QModelIndex & parent) const {
  Q_UNUSED(parent);

  // One additional column for the sequence number
  return platformInfo.getNumChannels() + 1;
}

Pattern* SequenceModel::getPattern(const QModelIndex& index) const {
  int row = index.row();

  if (row < 0) {
    return NULL;
  } else {
    return sequence.getPattern(row);
  }
}

Track* SequenceModel::getTrack(const QModelIndex& index) const {
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

QVariant SequenceModel::data(const QModelIndex& index, int role) const {
  if (!index.isValid()) {
    return QVariant();
  }

  if (role == Qt::UserRole) {
    // The view's delegate is asking us for the maximum value for this cell.
    return QVariant(trackBank.getLargestTrackNumber());
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

bool SequenceModel::setData(
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

  Track* newTrack = trackBank.getTrack(trackID);

  if (newTrack == NULL) {
    return false;
  }

  pattern->setTrack(patternTrackNumber, newTrack);
}

QVariant SequenceModel::headerData(
  int section, Qt::Orientation orientation, int role) const {
  return QVariant();
}

Qt::ItemFlags SequenceModel::flags(const QModelIndex& index) const {
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

void SequenceModel::getPatternsFromRowNumbers(
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

void SequenceModel::insertRows(QSet<uint32_t>& rows) {
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

void SequenceModel::removeRows(QSet<uint32_t>& rows) {
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
