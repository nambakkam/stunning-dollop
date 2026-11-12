#ifndef TASKVIEWMODELTEST_H
#define TASKVIEWMODELTEST_H

#include <QObject>

class TaskViewModelTest : public QObject
{
    Q_OBJECT

private slots:
    void exposesTaskRoles();
    void commandsUpdateTasksAndSummary();
    void reportsInvalidOperations();
};

#endif // TASKVIEWMODELTEST_H
