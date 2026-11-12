#include <QCoreApplication>
#include <QtTest>

#include "itemlisttest.h"
#include "randomvaluesgeneratortester.h"
#include "taskviewmodeltest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ItemListTest test;
    RandomValuesGeneratorTester randomGeneratorTest;
    TaskViewModelTest taskViewModelTest;
    const int itemListResult = QTest::qExec(&test, argc, argv);
    const int randomGeneratorResult = QTest::qExec(&randomGeneratorTest, argc, argv);
    const int taskViewModelResult = QTest::qExec(&taskViewModelTest, argc, argv);
    return itemListResult | randomGeneratorResult | taskViewModelResult;
}
