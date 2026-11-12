#ifndef TASKVIEWMODEL_H
#define TASKVIEWMODEL_H

#include "taskmodel.h"

#include <QObject>
#include <QString>

class TaskViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(TaskModel *tasks READ tasks CONSTANT)
    Q_PROPERTY(int totalCount READ totalCount NOTIFY totalCountChanged)
    Q_PROPERTY(int completedCount READ completedCount NOTIFY completedCountChanged)
    Q_PROPERTY(int remainingCount READ remainingCount NOTIFY remainingCountChanged)
    Q_PROPERTY(QString errorMessage READ errorMessage NOTIFY errorMessageChanged)

public:
    explicit TaskViewModel(QObject *parent = nullptr);

    TaskModel *tasks();
    int totalCount() const;
    int completedCount() const;
    int remainingCount() const;
    QString errorMessage() const;

    Q_INVOKABLE void addTask(const QString &text);
    Q_INVOKABLE void setTaskCompleted(int row, bool completed);
    Q_INVOKABLE void removeTask(int row);

signals:
    void totalCountChanged();
    void completedCountChanged();
    void remainingCountChanged();
    void errorMessageChanged();

private:
    void setErrorMessage(const QString &message);

    TaskModel tasks_;
    QString errorMessage_;
};

#endif // TASKVIEWMODEL_H
