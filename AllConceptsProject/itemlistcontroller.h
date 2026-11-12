#ifndef ITEMLISTCONTROLLER_H
#define ITEMLISTCONTROLLER_H

#include <QObject>
#include <QString>

class ItemListModel;

class ItemListController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString errorMessage READ errorMessage NOTIFY errorMessageChanged)

public:
    explicit ItemListController(ItemListModel *model, QObject *parent = nullptr);

    QString errorMessage() const;

    Q_INVOKABLE void addItem(const QString &item);
    Q_INVOKABLE void removeItem(int row);

signals:
    void errorMessageChanged();

private:
    void setErrorMessage(const QString &message);

    ItemListModel *model_;
    QString errorMessage_;
};

#endif // ITEMLISTCONTROLLER_H
