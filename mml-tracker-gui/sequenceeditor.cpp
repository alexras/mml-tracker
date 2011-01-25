#include "sequenceeditor.h"
#include "ui_sequenceeditor.h"

SequenceEditor::SequenceEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SequenceEditor)
{
    ui->setupUi(this);
}

SequenceEditor::~SequenceEditor()
{
    delete ui;
}
