#ifndef ITEMLISTMODEL_H
#define ITEMLISTMODEL_H

#include <QAbstractListModel>
#include <QStringList>

class ItemListController;

class ItemListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum ItemRoles {
        ItemTextRole = Qt::UserRole + 1
    };

    explicit ItemListModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

private:
    friend class ItemListController;

    void appendItem(const QString &item);
    void removeItemAt(int row);

    QStringList items_;
};

#endif // ITEMLISTMODEL_H
