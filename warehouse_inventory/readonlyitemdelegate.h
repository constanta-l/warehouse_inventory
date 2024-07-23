#ifndef READONLYITEMDELEGATE_H
#define READONLYITEMDELEGATE_H

#include <QStyledItemDelegate>

class ReadOnlyItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    explicit ReadOnlyItemDelegate(QObject *parent = nullptr);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif // READONLYITEMDELEGATE_H
