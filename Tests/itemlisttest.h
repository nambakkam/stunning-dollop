#ifndef ITEMLISTTEST_H
#define ITEMLISTTEST_H

#include <QObject>

class ItemListTest : public QObject
{
    Q_OBJECT

private slots:
    void modelExposesItemTextRole();
    void controllerAddsAndRemovesItems();
    void controllerReportsInvalidOperations();
};

#endif // ITEMLISTTEST_H
