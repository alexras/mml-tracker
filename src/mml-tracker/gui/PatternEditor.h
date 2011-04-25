#ifndef MMLTRACKER_PATTERN_EDITOR_H
#define MMLTRACKER_PATTERN_EDITOR_H

#include <QWidget>
#include <QTableView>
#include <stdint.h>

#include "mml-tracker/gui/PatternModel.h"

class PatternEditor : public QWidget {
Q_OBJECT

public:
  PatternEditor(PatternModel* model, QWidget* parent = NULL);

public slots:
  void loadPattern(Pattern* pattern);
private:
  QTableView* tableView;
  PatternModel* model;
};

#endif // MMLTRACKER_PATTERN_EDITOR_H
