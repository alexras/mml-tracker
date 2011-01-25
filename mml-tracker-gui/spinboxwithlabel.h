#ifndef SPINBOXWITHLABEL_H
#define SPINBOXWITHLABEL_H

#include <QWidget>

namespace Ui {
    class SpinBoxWithLabel;
}

class SpinBoxWithLabel : public QWidget
{
    Q_OBJECT

public:
    explicit SpinBoxWithLabel(QWidget *parent = 0);
    ~SpinBoxWithLabel();

private:
    Ui::SpinBoxWithLabel *ui;
};

#endif // SPINBOXWITHLABEL_H
