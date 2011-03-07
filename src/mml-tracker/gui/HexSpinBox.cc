#include "HexSpinBox.h"

HexSpinBox::HexSpinBox(QWidget* parent) : QSpinBox(parent) {
}

int HexSpinBox::valueFromText(const QString& text) const {
  bool ok = false;

  int val = text.toInt(&ok, 16);
  return val;
}

QString HexSpinBox::textFromValue(int value) const {
  return QString("%1").arg(value, 2, 16, QChar('0')).toUpper();
}

QValidator::State HexSpinBox::validate(QString& input, int& pos) const {
  bool ok = false;
  QString substr = input.left(pos);

  if (substr.size() == 0) {
    return QValidator::Intermediate;
  }

  int val = substr.toInt(&ok, 16);

  if (!ok) {
    return QValidator::Invalid;
  } else if (val < minimum() || val > maximum()) {
    return QValidator::Invalid;
  } else {
    return QValidator::Acceptable;
  }
}
