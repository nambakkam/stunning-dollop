#include "randomvaluesgeneratortester.h"

#include "randomvaluesgenerator.h"

#include <QtTest>

RandomValuesGeneratorTester::RandomValuesGeneratorTester(QObject *parent)
    : QObject{parent}
{
}

void RandomValuesGeneratorTester::randomIntKeepsRequestedRange()
{
    const int value = RandomValuesGenerator::getInstance().generateRandomInt(5, 10);
    QVERIFY2(value >= 5 && value <= 10, "Generated integer must stay within range");

    const int reversedValue =
        RandomValuesGenerator::getInstance().generateRandomInt(10, 5);
    QVERIFY2(reversedValue >= 5 && reversedValue <= 10,
             "Inverted bounds should be normalized before generation");
}

void RandomValuesGeneratorTester::randomStringRespectsRequestedLength()
{
    const QString value = RandomValuesGenerator::getInstance().generateRandomString(12);
    QCOMPARE(value.length(), 12);

    const QString emptyValue =
        RandomValuesGenerator::getInstance().generateRandomString(0);
    QCOMPARE(emptyValue.length(), 0);
}

void RandomValuesGeneratorTester::randomRealSwapsInvertedRange()
{
    const double value = RandomValuesGenerator::getInstance().generateRandomReal(8.0, 2.0);
    QVERIFY2(value >= 2.0 && value <= 8.0,
             "Inverted real bounds should be normalized before generation");
}
