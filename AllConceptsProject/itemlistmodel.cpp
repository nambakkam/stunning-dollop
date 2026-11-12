#include "itemlistmodel.h"

ItemListModel::ItemListModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int ItemListModel::rowCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : items_.size();
}

QVariant ItemListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() < 0 || index.row() >= items_.size())
        return QVariant();

    if (role == ItemTextRole || role == Qt::DisplayRole)
        return items_.at(index.row());

    return QVariant();
}

QHash<int, QByteArray> ItemListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles.insert(ItemTextRole, "itemText");
    return roles;
}

void ItemListModel::appendItem(const QString &item)
{
    const int row = items_.size();
    beginInsertRows(QModelIndex(), row, row);
    items_.append(item);
    endInsertRows();
}

void ItemListModel::removeItemAt(int row)
{
    beginRemoveRows(QModelIndex(), row, row);
    items_.removeAt(row);
    endRemoveRows();
}
