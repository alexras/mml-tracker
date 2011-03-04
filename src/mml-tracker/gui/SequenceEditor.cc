#include <QBoxLayout>
#include <QHeaderView>
#include <QPushButton>
#include <QSpacerItem>
#include <QTableView>
#include <QVBoxLayout>
#include <iostream>

#include "SequenceEditor.h"
#include "mml-tracker/Sequence.h"
#include "mml-tracker/gui/ItemSpinBoxDelegate.h"
#include "mml-tracker/gui/SequenceEditorModel.h"

SequenceEditor::SequenceEditor(Sequence& _sequence, QWidget* parent)
  : QWidget(parent), sequence(_sequence) {

  model = new SequenceEditorModel(sequence);
  ItemSpinBoxDelegate* delegate = new ItemSpinBoxDelegate(this);

  tableView = new QTableView(this);
  tableView->setModel(model);
  tableView->setItemDelegate(delegate);
  tableView->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
  tableView->horizontalHeader()->hide();
  tableView->verticalHeader()->hide();

  QPushButton* addButton = new QPushButton("+", this);
  QPushButton* removeButton = new QPushButton("-", this);
  QSpacerItem* buttonSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding);

  QObject::connect(addButton, SIGNAL(clicked(bool)), this,
                   SLOT(addSequence()));
  QObject::connect(removeButton, SIGNAL(clicked(bool)), this,
                   SLOT(removeSequence()));

  QHBoxLayout* buttonLayout = new QHBoxLayout();
  buttonLayout->addWidget(addButton);
  buttonLayout->addWidget(removeButton);
  buttonLayout->addSpacerItem(buttonSpacer);
  QVBoxLayout* layout = new QVBoxLayout(this);
  layout->addWidget(tableView);
  layout->addLayout(buttonLayout);
  setLayout(layout);
}

void SequenceEditor::getSelectedRows(QSet<uint32_t>& rowSet) {
  QItemSelectionModel* itemSelectionModel = tableView->selectionModel();
  QModelIndexList indices = itemSelectionModel->selectedIndexes();

  for (QModelIndexList::iterator iter = indices.begin(); iter != indices.end();
       iter++) {
    rowSet.insert(iter->row());
  }
}

void SequenceEditor::addSequence() {
  QSet<uint32_t> rowSet;
  getSelectedRows(rowSet);

  if (rowSet.size() == 0) {
    uint32_t patternID = sequence.getNumPatterns();
    model->insertRow(patternID);
  } else {
    for (QSet<uint32_t>::iterator iter = rowSet.begin(); iter != rowSet.end();
         iter++) {
      model->insertRow(*iter);
    }
  }
}

void SequenceEditor::removeSequence() {
  QSet<uint32_t> rowSet;
  getSelectedRows(rowSet);

  if (rowSet.size() == 0) {
    // No indices selected; just remove the last row
    uint32_t patternID = sequence.getNumPatterns() - 1;
    model->removeRow(patternID);
  } else {
    for (QSet<uint32_t>::iterator iter = rowSet.begin(); iter != rowSet.end();
         iter++) {
      model->removeRow(*iter);
    }
  }
}

