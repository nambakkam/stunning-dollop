#include "itemlistcontroller.h"

#include "itemlistmodel.h"

ItemListController::ItemListController(ItemListModel *model, QObject *parent)
    : QObject(parent)
    , model_(model)
{
}

QString ItemListController::errorMessage() const
{
    return errorMessage_;
}

void ItemListController::addItem(const QString &item)
{
    const QString trimmedItem = item.trimmed();
    if (trimmedItem.isEmpty()) {
        setErrorMessage(tr("Enter an item before adding it."));
        return;
    }

    model_->appendItem(trimmedItem);
    setErrorMessage(QString());
}

void ItemListController::removeItem(int row)
{
    if (row < 0 || row >= model_->rowCount()) {
        setErrorMessage(tr("The selected item no longer exists."));
        return;
    }

    model_->removeItemAt(row);
    setErrorMessage(QString());
}

void ItemListController::setErrorMessage(const QString &message)
{
    if (errorMessage_ == message)
        return;

    errorMessage_ = message;
    emit errorMessageChanged();
}
