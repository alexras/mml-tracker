#ifndef MMLTRACKER_GUI_UTILS_H
#define MMLTRACKER_GUI_UTILS_H

#include <QSet>
#include <QTableView>
#include <stdint.h>

void getSelectedRows(QTableView& tableView, QSet<uint32_t>& rowSet);

#endif // MMLTRACKER_GUI_UTILS_H
