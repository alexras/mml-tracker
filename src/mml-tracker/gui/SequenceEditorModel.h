#ifndef MMLTRACKER_SEQUENCE_EDITOR_MODEL_H
#define MMLTRACKER_SEQUENCE_EDITOR_MODEL_H

#include <QAbstractTableModel>
#include <stdint.h>

class Pattern;
class Sequence;
class Track;

class SequenceEditorModel : public QAbstractTableModel {
Q_OBJECT

public:
  SequenceEditorModel(Sequence& sequence, QObject* parent = NULL);
  int rowCount(const QModelIndex & parent) const;
  int columnCount(const QModelIndex & parent) const;
  QVariant data(const QModelIndex& index, int role) const;
  bool setData(const QModelIndex& index, const QVariant& value, int role);
  QVariant headerData(int section, Qt::Orientation orientation, int role) const;

  // Returns any flags on the given item
  Qt::ItemFlags flags(const QModelIndex& index) const;

  bool insertRow(uint32_t row);
  bool removeRow(uint32_t row);

private:
  Sequence& sequence;

  // Gets the pattern corresponding to the row referenced by the index
  Pattern* getPattern(const QModelIndex& index) const;

  // Gets the track corresponding to the row and column referenced by theindex
  Track* getTrack(const QModelIndex& index) const;
};

#endif // MMLTRACKER_SEQUENCE_EDITOR_MODEL_H
