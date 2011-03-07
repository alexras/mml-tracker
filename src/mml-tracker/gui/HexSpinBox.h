#include <QSpinBox>

class HexSpinBox : public QSpinBox {
Q_OBJECT

public:
  HexSpinBox(QWidget* parent = NULL);

protected:
  int valueFromText(const QString& text) const;
  QString textFromValue(int value) const;
  QValidator::State validate(QString& input, int& pos) const;
};
