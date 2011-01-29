#include "sequencetable.h"

SequenceTable::SequenceTable() {
  rows = 0;
  cols = 0;
}

void SequenceTable::changeRowCount() {
  table.resize(rows);
}

void SequenceTable::changeColumnCount() {
  for (int i = 0; i < rows; i++) {
    table[i].resize(cols);
  }
}

void SequenceTable::addRow() {
  rows += 1;
  changeRowCount();
}

void SequenceTable::addColumn() {
  cols += 1;
  changeColumnCount();
}

void SequenceTable::removeRow() {
  rows -= 1;
  changeRowCount();
}

void SequenceTable::removeColumn() {
  cols -= 1;
  changeColumnCount();
}

int SequenceTable::getNumRows() const {
  return rows;
}

int SequenceTable::getNumColumns() const {
  return cols;
}

int* SequenceTable::getDataItem(int row, int col) {
  if (row < rows && col < cols) {
    return &(table[row][col]);
  } else {
    return NULL;
  }
}
