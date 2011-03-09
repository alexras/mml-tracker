#ifndef MMLTRACKER_SEQUENCE_EDITOR_H
#define MMLTRACKER_SEQUENCE_EDITOR_H

#include <QWidget>
#include <stdint.h>

class QTableView;
class SequenceModel;

class SequenceEditor : public QWidget {
Q_OBJECT

public:
  SequenceEditor(SequenceModel* model, QWidget* parent = NULL);

public slots:
  void addSequence();
  void removeSequence();

private:
  QTableView* tableView;
  SequenceModel* model;

  void getSelectedRows(QSet<uint32_t>& rowSet);
};

#endif // MMLTRACKER_SEQUENCE_EDITOR_H
