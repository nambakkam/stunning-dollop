#ifndef TASKMODEL_H
#define TASKMODEL_H

#include <QAbstractListModel>
#include <QVector>

class TaskViewModel;

class TaskModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum TaskRoles {
        TaskTextRole = Qt::UserRole + 1,
        CompletedRole
    };

    explicit TaskModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

private:
    friend class TaskViewModel;

    struct Task {
        QString text;
        bool completed;
    };

    void appendTask(const QString &text);
    bool setTaskCompleted(int row, bool completed);
    bool removeTaskAt(int row);

    QVector<Task> tasks_;
};

#endif // TASKMODEL_H
