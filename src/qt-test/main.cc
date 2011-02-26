#include <QApplication>
#include <QWidget>

#include "MyButton.h"

int main(int argc, char*argv[]) {
  QApplication app(argc, argv);

  MyButton window;
  window.setWindowTitle("button");
  window.show();

  return app.exec();
}
