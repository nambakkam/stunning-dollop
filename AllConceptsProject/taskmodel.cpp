#include "taskmodel.h"

TaskModel::TaskModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int TaskModel::rowCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : tasks_.size();
}

QVariant TaskModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() < 0 || index.row() >= tasks_.size())
        return QVariant();

    const Task &task = tasks_.at(index.row());
    if (role == TaskTextRole || role == Qt::DisplayRole)
        return task.text;
    if (role == CompletedRole)
        return task.completed;

    return QVariant();
}

QHash<int, QByteArray> TaskModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles.insert(TaskTextRole, "taskText");
    roles.insert(CompletedRole, "completed");
    return roles;
}

void TaskModel::appendTask(const QString &text)
{
    const int row = tasks_.size();
    beginInsertRows(QModelIndex(), row, row);
    tasks_.append({text, false});
    endInsertRows();
}

bool TaskModel::setTaskCompleted(int row, bool completed)
{
    if (row < 0 || row >= tasks_.size())
        return false;
    if (tasks_.at(row).completed == completed)
        return true;

    tasks_[row].completed = completed;
    const QModelIndex changedIndex = index(row);
    emit dataChanged(changedIndex, changedIndex, {CompletedRole});
    return true;
}

bool TaskModel::removeTaskAt(int row)
{
    if (row < 0 || row >= tasks_.size())
        return false;

    beginRemoveRows(QModelIndex(), row, row);
    tasks_.removeAt(row);
    endRemoveRows();
    return true;
}
