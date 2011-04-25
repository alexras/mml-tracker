#include "PatternEditor.h"

PatternEditor::PatternEditor(PatternModel* model, QWidget* parent = NULL)
  : QWidget(parent) {
  this->model = model;
  tableView = new QTableView(this);
  tableView->setModel(model);
}

void PatternEditor::loadPattern(Pattern* pattern) {
  model->loadPattern(pattern);
}
