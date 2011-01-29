#ifndef SEQUENCEEDITOR_H
#define SEQUENCEEDITOR_H

#include <QWidget>

#include "sequenceeditormodel.h"
#include "sequencetable.h"

namespace Ui {
    class SequenceEditor;
}

class SequenceEditor : public QWidget
{
    Q_OBJECT

public:
    explicit SequenceEditor(QWidget *parent = 0);
    ~SequenceEditor();

public slots:
  void addRow();
  void removeRow();

private:
  Ui::SequenceEditor *ui;
  SequenceEditorModel* sequenceEditorModel;
  SequenceTable* sequenceTable;
};

#endif // SEQUENCEEDITOR_H
