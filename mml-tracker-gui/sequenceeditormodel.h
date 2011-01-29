#ifndef SEQUENCEEDITORMODEL_H
#define SEQUENCEEDITORMODEL_H

#include <QAbstractTableModel>
#include <vector>
#include "sequencetable.h"

class SequenceEditorModel : public QAbstractTableModel {
  Q_OBJECT
public:
  explicit SequenceEditorModel(SequenceTable* sequenceTable, 
                               QObject *parent = 0);

  int rowCount(const QModelIndex &parent) const;
  int columnCount(const QModelIndex &parent) const;
  QVariant data(const QModelIndex &index, int role) const;
  
signals:
    
public slots:
  
private:
  SequenceTable* sequenceTable;
};

#endif // SEQUENCEEDITORMODEL_H
