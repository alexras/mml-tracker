#ifndef SEQUENCEEDITOR_H
#define SEQUENCEEDITOR_H

#include <QWidget>

namespace Ui {
    class SequenceEditor;
}

class SequenceEditor : public QWidget
{
    Q_OBJECT

public:
    explicit SequenceEditor(QWidget *parent = 0);
    ~SequenceEditor();

private:
    Ui::SequenceEditor *ui;
};

#endif // SEQUENCEEDITOR_H
