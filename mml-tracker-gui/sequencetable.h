#ifndef SEQUENCETABLE_H
#define SEQUENCETABLE_H

#include <vector>

class SequenceTable {
public:
  SequenceTable();

  void addRow();
  void addColumn();
  void removeRow();
  void removeColumn();
  
  int getNumRows() const;
  int getNumColumns() const;
  int* getDataItem(int row, int col);
private:
  int rows;
  int cols;
  std::vector< std::vector<int> > table;

  void changeRowCount();
  void changeColumnCount();
};

#endif // SEQUENCETABLE_H
