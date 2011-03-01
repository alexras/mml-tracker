#ifndef MMLTRACKER_SEQUENCE_EDITOR_ITEM_SPINBOX_DELEGATE_H
#define MMLTRACKER_SEQUENCE_EDITOR_ITEM_SPINBOX_DELEGATE_H

#include <QStyledItemDelegate>

class SequenceEditorItemSpinBoxDelegate : public QStyledItemDelegate {
  Q_OBJECT

public:
  SequenceEditorItemSpinBoxDelegate(QObject* parent = NULL);

  // Creates the editor widget used to edit the item at the given index
  QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                        const QModelIndex &index) const;

  // Called when an editor is created to initialize it with data from the model
  void setEditorData(QWidget* editor, const QModelIndex& index) const;

  // Called when editing is finished to commit data from the editor to the model
  void setModelData(QWidget* editor, QAbstractItemModel* model,
                    const QModelIndex& index) const;

  // Updates the editor's geometry in response to external events
  void updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option,
                            const QModelIndex& index) const;
};

#endif // MMLTRACKER_SEQUENCE_EDITOR_ITEM_SPINBOX_DELEGATE_H
