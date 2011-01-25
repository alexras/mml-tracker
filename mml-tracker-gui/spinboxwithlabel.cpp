#include "spinboxwithlabel.h"
#include "ui_spinboxwithlabel.h"

SpinBoxWithLabel::SpinBoxWithLabel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SpinBoxWithLabel)
{
    ui->setupUi(this);
}

SpinBoxWithLabel::~SpinBoxWithLabel()
{
    delete ui;
}
