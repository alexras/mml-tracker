#include "sequenceeditormodel.h"

SequenceEditorModel::SequenceEditorModel(SequenceTable *sequenceTable, 
                                         QObject *parent) :
    QAbstractTableModel(parent) {
}

int SequenceEditorModel::rowCount(const QModelIndex &parent) const {
  return sequenceTable->getNumRows();
}

int SequenceEditorModel::columnCount(const QModelIndex &parent) const {
  return sequenceTable->getNumColumns();
}

QVariant SequenceEditorModel::data(const QModelIndex &index, int role) const {
  int* datum = sequenceTable->getDataItem(index.row(), index.column());
  
  if (datum == NULL) {
    return QVariant();
  } else {
    return QVariant(*datum);
  }
}
