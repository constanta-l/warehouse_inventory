// readonlyitemdelegate.cpp
#include "readonlyitemdelegate.h"
#include <QWidget>
#include <QModelIndex>

ReadOnlyItemDelegate::ReadOnlyItemDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{}

QWidget *ReadOnlyItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    // Prevent editing for the ID column
    if (index.column() == 0) // Assuming ID is the first column
        return nullptr; // Return nullptr to make it read-only

    return QStyledItemDelegate::createEditor(parent, option, index);
}
