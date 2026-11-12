#include "taskviewmodel.h"

#include <QAbstractItemModel>

TaskViewModel::TaskViewModel(QObject *parent)
    : QObject(parent)
{
    connect(&tasks_, &QAbstractItemModel::rowsInserted, this,
            [this](const QModelIndex &, int, int) {
                emit totalCountChanged();
                emit remainingCountChanged();
            });
    connect(&tasks_, &QAbstractItemModel::rowsRemoved, this,
            [this](const QModelIndex &, int, int) {
                emit totalCountChanged();
                emit remainingCountChanged();
            });
    connect(&tasks_, &QAbstractItemModel::dataChanged, this,
            [this](const QModelIndex &, const QModelIndex &, const QVector<int> &roles) {
                if (roles.contains(TaskModel::CompletedRole)) {
                    emit completedCountChanged();
                    emit remainingCountChanged();
                }
            });
}

TaskModel *TaskViewModel::tasks()
{
    return &tasks_;
}

int TaskViewModel::totalCount() const
{
    return tasks_.rowCount();
}

int TaskViewModel::completedCount() const
{
    int count = 0;
    for (int row = 0; row < tasks_.rowCount(); ++row) {
        if (tasks_.data(tasks_.index(row), TaskModel::CompletedRole).toBool())
            ++count;
    }
    return count;
}

int TaskViewModel::remainingCount() const
{
    return totalCount() - completedCount();
}

QString TaskViewModel::errorMessage() const
{
    return errorMessage_;
}

void TaskViewModel::addTask(const QString &text)
{
    const QString taskText = text.trimmed();
    if (taskText.isEmpty()) {
        setErrorMessage(tr("Enter a task before adding it."));
        return;
    }

    tasks_.appendTask(taskText);
    setErrorMessage(QString());
}

void TaskViewModel::setTaskCompleted(int row, bool completed)
{
    if (!tasks_.setTaskCompleted(row, completed)) {
        setErrorMessage(tr("The selected task no longer exists."));
        return;
    }

    setErrorMessage(QString());
}

void TaskViewModel::removeTask(int row)
{
    const bool rowExists = row >= 0 && row < tasks_.rowCount();
    const bool wasCompleted =
        rowExists && tasks_.data(tasks_.index(row), TaskModel::CompletedRole).toBool();
    if (!tasks_.removeTaskAt(row)) {
        setErrorMessage(tr("The selected task no longer exists."));
        return;
    }

    if (wasCompleted)
        emit completedCountChanged();
    setErrorMessage(QString());
}

void TaskViewModel::setErrorMessage(const QString &message)
{
    if (errorMessage_ == message)
        return;

    errorMessage_ = message;
    emit errorMessageChanged();
}
