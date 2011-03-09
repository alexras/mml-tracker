#include <QBoxLayout>
#include <QHeaderView>
#include <QPushButton>
#include <QSpacerItem>
#include <QTableView>
#include <QVBoxLayout>

#include "SequenceEditor.h"
#include "mml-tracker/Sequence.h"
#include "mml-tracker/gui/ItemSpinBoxDelegate.h"
#include "mml-tracker/gui/SequenceModel.h"

SequenceEditor::SequenceEditor(SequenceModel* model, QWidget* parent)
  : QWidget(parent) {

  this->model = model;
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
  model->insertRows(rowSet);
}

void SequenceEditor::removeSequence() {
  QSet<uint32_t> rowSet;
  getSelectedRows(rowSet);
  model->removeRows(rowSet);
}

