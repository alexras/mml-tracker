#include <QPushButton>

#include "MyButton.h"

MyButton::MyButton(QWidget* parent)
  : QWidget(parent) {

  int width = 250;
  int height = 150;
  setFixedSize(width, height);

  QPushButton* quit = new QPushButton("Quit", this);
  quit->setGeometry(50, 40, 75, 30);
  connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
}
