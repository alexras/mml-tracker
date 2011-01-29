#include "sequenceeditor.h"
#include "ui_sequenceeditor.h"

SequenceEditor::SequenceEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SequenceEditor)
{
  sequenceTable = new SequenceTable();
  sequenceTable->addColumn();
  sequenceTable->addColumn();
  sequenceTable->addColumn();
  sequenceTable->addRow();
  
  sequenceEditorModel = new SequenceEditorModel(sequenceTable);
  ui->setupUi(this);
}

SequenceEditor::~SequenceEditor()
{
    delete ui;
}

void SequenceEditor::addRow() {
  sequenceTable->addRow();
}

void SequenceEditor::removeRow() {
  sequenceTable->removeRow();
}
