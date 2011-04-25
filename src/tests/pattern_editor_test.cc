#include <QApplication>
#include <QString>

#include "MockPlatformInfo.h"

int main(int argc, char** argv) {
  QApplication app(argc, argv);

  MockPlatformInfo platformInfo;

  PatternFactory patternFactory(platformInfo);

  PatternEditor patternEditor;


  return app.exec();
}

