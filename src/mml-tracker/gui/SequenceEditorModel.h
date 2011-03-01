#ifndef MMLTRACKER_SEQUENCE_EDITOR_MODEL_H
#define MMLTRACKER_SEQUENCE_EDITOR_MODEL_H

#include <QAbstractTableModel>

class Sequence;

class SequenceEditorModel : public QAbstractTableModel {
Q_OBJECT

public:
  SequenceEditorModel(Sequence& sequence, QObject* parent = NULL);
  int rowCount(const QModelIndex & parent) const;
  int columnCount(const QModelIndex & parent) const;
  QVariant data(const QModelIndex& index, int role) const;
  QVariant headerData(int section, Qt::Orientation orientation, int role) const;

  // Returns any flags on the given item
  Qt::ItemFlags flags(const QModelIndex& index) const;

  bool insertRows(int position, int rows,
                  const QModelIndex& index=QModelIndex());
  bool removeRows(int position, int rows,
                  const QModelIndex& index=QModelIndex());

private:
  Sequence& sequence;
};

#endif // MMLTRACKER_SEQUENCE_EDITOR_MODEL_H
