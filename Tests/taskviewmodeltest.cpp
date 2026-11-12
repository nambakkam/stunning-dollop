#include "taskviewmodeltest.h"

#include "taskmodel.h"
#include "taskviewmodel.h"

#include <QSignalSpy>
#include <QtTest>

void TaskViewModelTest::exposesTaskRoles()
{
    TaskViewModel viewModel;

    QCOMPARE(viewModel.tasks()->rowCount(), 0);
    QCOMPARE(viewModel.tasks()->roleNames().value(TaskModel::TaskTextRole),
             QByteArray("taskText"));
    QCOMPARE(viewModel.tasks()->roleNames().value(TaskModel::CompletedRole),
             QByteArray("completed"));
}

void TaskViewModelTest::commandsUpdateTasksAndSummary()
{
    TaskViewModel viewModel;
    TaskModel *model = viewModel.tasks();
    QSignalSpy insertedSpy(model, &QAbstractItemModel::rowsInserted);
    QSignalSpy changedSpy(model, &QAbstractItemModel::dataChanged);
    QSignalSpy removedSpy(model, &QAbstractItemModel::rowsRemoved);
    QSignalSpy totalCountSpy(&viewModel, &TaskViewModel::totalCountChanged);
    QSignalSpy completedCountSpy(&viewModel, &TaskViewModel::completedCountChanged);
    QSignalSpy remainingCountSpy(&viewModel, &TaskViewModel::remainingCountChanged);

    viewModel.addTask(QStringLiteral("  Write tests  "));
    QCOMPARE(model->rowCount(), 1);
    QCOMPARE(model->data(model->index(0), TaskModel::TaskTextRole).toString(),
             QStringLiteral("Write tests"));
    QVERIFY(!model->data(model->index(0), TaskModel::CompletedRole).toBool());
    QCOMPARE(viewModel.totalCount(), 1);
    QCOMPARE(viewModel.remainingCount(), 1);
    QCOMPARE(insertedSpy.count(), 1);
    QCOMPARE(totalCountSpy.count(), 1);
    QCOMPARE(completedCountSpy.count(), 0);
    QCOMPARE(remainingCountSpy.count(), 1);

    viewModel.setTaskCompleted(0, true);
    QVERIFY(model->data(model->index(0), TaskModel::CompletedRole).toBool());
    QCOMPARE(viewModel.completedCount(), 1);
    QCOMPARE(viewModel.remainingCount(), 0);
    QCOMPARE(changedSpy.count(), 1);
    QCOMPARE(completedCountSpy.count(), 1);
    QCOMPARE(remainingCountSpy.count(), 2);

    viewModel.removeTask(0);
    QCOMPARE(model->rowCount(), 0);
    QCOMPARE(viewModel.totalCount(), 0);
    QCOMPARE(viewModel.completedCount(), 0);
    QCOMPARE(viewModel.remainingCount(), 0);
    QCOMPARE(removedSpy.count(), 1);
    QCOMPARE(totalCountSpy.count(), 2);
    QCOMPARE(completedCountSpy.count(), 2);
    QCOMPARE(remainingCountSpy.count(), 3);
}

void TaskViewModelTest::reportsInvalidOperations()
{
    TaskViewModel viewModel;
    QSignalSpy errorSpy(&viewModel, &TaskViewModel::errorMessageChanged);

    viewModel.addTask(QStringLiteral("   "));
    QVERIFY(!viewModel.errorMessage().isEmpty());
    QCOMPARE(viewModel.tasks()->rowCount(), 0);

    viewModel.setTaskCompleted(0, true);
    QVERIFY(!viewModel.errorMessage().isEmpty());
    QCOMPARE(viewModel.tasks()->rowCount(), 0);

    viewModel.removeTask(0);
    QVERIFY(!viewModel.errorMessage().isEmpty());
    QCOMPARE(viewModel.tasks()->rowCount(), 0);
    QCOMPARE(errorSpy.count(), 2);
}
