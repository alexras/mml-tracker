#include <QApplication>
#include <QString>
#include <QTableView>

#include "MockPlatformInfo.h"
#include "mml-tracker/Pattern.h"
#include "mml-tracker/PatternFactory.h"
#include "mml-tracker/Sequence.h"
#include "mml-tracker/TrackBank.h"
#include "mml-tracker/gui/SequenceEditor.h"
#include "mml-tracker/gui/SequenceModel.h"

int main(int argc, char** argv) {
  QApplication app(argc, argv);

  MockPlatformInfo platformInfo;

  PatternFactory patternFactory(platformInfo);

  TrackBank trackBank;
  Sequence sequence(trackBank, patternFactory);
  sequence.addNewPattern();
  sequence.addNewPattern();
  sequence.addNewPattern();
  sequence.addNewPattern();

  for (uint32_t i = 0; i < sequence.getNumPatterns(); i++) {
    Pattern* pattern = sequence.getPattern(i);

    for (uint32_t j = 0; j < platformInfo.getNumChannels(); j++) {
      pattern->setTrack(j, trackBank.newTrack());
    }
  }
  SequenceModel sequenceModel(sequence, trackBank, platformInfo);
  SequenceEditor sequenceEditor(&sequenceModel);
  sequenceEditor.setWindowTitle(QObject::tr("Sequence Editor Test"));
  sequenceEditor.show();
  return app.exec();
}
