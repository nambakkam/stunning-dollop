#include "itemlisttest.h"

#include "itemlistcontroller.h"
#include "itemlistmodel.h"

#include <QSignalSpy>
#include <QtTest>

void ItemListTest::modelExposesItemTextRole()
{
    ItemListModel model;
    ItemListController controller(&model);
    controller.addItem(QStringLiteral("First"));

    QCOMPARE(model.rowCount(), 1);
    QCOMPARE(model.data(model.index(0), ItemListModel::ItemTextRole).toString(),
             QStringLiteral("First"));
    QCOMPARE(model.roleNames().value(ItemListModel::ItemTextRole),
             QByteArray("itemText"));
}

void ItemListTest::controllerAddsAndRemovesItems()
{
    ItemListModel model;
    ItemListController controller(&model);
    QSignalSpy insertedSpy(&model, &QAbstractItemModel::rowsInserted);
    QSignalSpy removedSpy(&model, &QAbstractItemModel::rowsRemoved);

    controller.addItem(QStringLiteral("  First  "));
    QCOMPARE(model.rowCount(), 1);
    QCOMPARE(model.data(model.index(0), ItemListModel::ItemTextRole).toString(),
             QStringLiteral("First"));
    QCOMPARE(insertedSpy.count(), 1);

    controller.removeItem(0);
    QCOMPARE(model.rowCount(), 0);
    QCOMPARE(removedSpy.count(), 1);
}

void ItemListTest::controllerReportsInvalidOperations()
{
    ItemListModel model;
    ItemListController controller(&model);
    QSignalSpy errorSpy(&controller, &ItemListController::errorMessageChanged);

    controller.addItem(QStringLiteral("   "));
    QVERIFY(!controller.errorMessage().isEmpty());
    QCOMPARE(model.rowCount(), 0);

    controller.removeItem(0);
    QVERIFY(!controller.errorMessage().isEmpty());
    QCOMPARE(model.rowCount(), 0);
    QCOMPARE(errorSpy.count(), 2);
}
