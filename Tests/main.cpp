#include <QCoreApplication>
#include <QtTest>

#include "itemlisttest.h"
#include "taskviewmodeltest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ItemListTest test;
    TaskViewModelTest taskViewModelTest;
    const int itemListResult = QTest::qExec(&test, argc, argv);
    const int taskViewModelResult = QTest::qExec(&taskViewModelTest, argc, argv);
    return itemListResult | taskViewModelResult;
}
