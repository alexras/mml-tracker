#ifndef MMLTRACKER_SEQUENCE_EDITOR_H
#define MMLTRACKER_SEQUENCE_EDITOR_H

#include <QWidget>
#include <stdint.h>

class QTableView;
class Sequence;
class SequenceEditorModel;

class SequenceEditor : public QWidget {
Q_OBJECT

public:
  SequenceEditor(Sequence& sequence, QWidget* parent = NULL);

public slots:
  void addSequence();
  void removeSequence();

private:
  Sequence& sequence;

  QTableView* tableView;
  SequenceEditorModel* model;

  void getSelectedRows(QSet<uint32_t>& rowSet);
};

#endif // MMLTRACKER_SEQUENCE_EDITOR_H
