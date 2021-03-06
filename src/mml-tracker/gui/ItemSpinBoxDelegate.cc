#include "HexSpinBox.h"
#include "ItemSpinBoxDelegate.h"

ItemSpinBoxDelegate::ItemSpinBoxDelegate(
  QObject* parent)
  : QStyledItemDelegate(parent) {

}

ItemSpinBoxDelegate::~ItemSpinBoxDelegate() {

}

// Creates the editor widget used to edit the item at the given index
QWidget* ItemSpinBoxDelegate::createEditor(
  QWidget* parent, const QStyleOptionViewItem& option,
  const QModelIndex& index) const {

  HexSpinBox* editor = new HexSpinBox(parent);
  editor->setMinimum(0);

  return editor;
}

// Called when an editor is created to initialize it with data from the model
void ItemSpinBoxDelegate::setEditorData(
  QWidget* editor, const QModelIndex& index) const {

  QVariant valueObj = index.model()->data(index, Qt::EditRole);

  int value;

  if (valueObj.isValid()) {
    bool ok = false;
    value = valueObj.toString().toInt(&ok, 16);
  } else {
    value = 0;
  }

  HexSpinBox* spinBox = static_cast<HexSpinBox*>(editor);
  spinBox->setMaximum(index.model()->data(index, Qt::UserRole).toUInt());
  spinBox->setValue(value);
}

// Called when editing is finished to commit data from the editor to the model
void ItemSpinBoxDelegate::setModelData(
  QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const {

  HexSpinBox* spinBox = static_cast<HexSpinBox*>(editor);

  // Interprets the data in the spinbox. If the value has changed since last
  // interpretation it will emit signals.
  spinBox->interpretText();

  int value = spinBox->value();

  model->setData(index, value, Qt::EditRole);
}

void ItemSpinBoxDelegate::updateEditorGeometry(
  QWidget* editor, const QStyleOptionViewItem& option,
  const QModelIndex& index) const {

  editor->setGeometry(option.rect);
}
