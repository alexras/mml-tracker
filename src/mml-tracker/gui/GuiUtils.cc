#include "GuiUtils.h"

void getSelectedRows(QTableView& tableView, QSet<uint32_t>& rowSet) {
  QItemSelectionModel* itemSelectionModel = tableView.selectionModel();
  QModelIndexList indices = itemSelectionModel->selectedIndexes();

  for (QModelIndexList::iterator iter = indices.begin(); iter != indices.end();
       iter++) {
    rowSet.insert(iter->row());
  }
}
