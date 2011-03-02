#include <QApplication>
#include <QString>
#include <QTableView>

#include "mml-tracker/Pattern.h"
#include "mml-tracker/Sequence.h"
#include "mml-tracker/TrackBank.h"
#include "mml-tracker/gui/ItemSpinBoxDelegate.h"
#include "mml-tracker/gui/SequenceEditorModel.h"

int main(int argc, char** argv) {
  QApplication app(argc, argv);

  std::vector<QString> trackNames;
  trackNames.push_back(QObject::tr("Track1"));
  trackNames.push_back(QObject::tr("Track2"));
  trackNames.push_back(QObject::tr("Track3"));

  TrackBank trackBank;

  Sequence sequence(trackBank, 3, trackNames);
  sequence.addNewPattern(0);

  sequence.addNewPattern(0);

  for (uint32_t i = 0; i < sequence.getNumPatterns(); i++) {
    Pattern* pattern = sequence.getPattern(i);

    for (uint32_t j = 0; j < sequence.getNumTracks(); j++) {
      pattern->setTrack(j, trackBank.newTrack());
    }
  }

  QTableView tableView;

  SequenceEditorModel model(sequence);
  tableView.setModel(&model);

  ItemSpinBoxDelegate delegate;
  tableView.setItemDelegate(&delegate);

  tableView.setWindowTitle(QObject::tr("Sequence Editor Test"));
  tableView.show();
  return app.exec();
}
