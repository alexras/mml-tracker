#ifndef MMLTRACKER_ITEM_SPINBOX_DELEGATE_H
#define MMLTRACKER_ITEM_SPINBOX_DELEGATE_H

#include <QStyledItemDelegate>

class ItemSpinBoxDelegate : public QStyledItemDelegate {
  Q_OBJECT

public:
  ItemSpinBoxDelegate(QObject* parent = NULL);
  virtual ~ItemSpinBoxDelegate();

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

#endif // MMLTRACKER_ITEM_SPINBOX_DELEGATE_H
