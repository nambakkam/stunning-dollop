#ifndef RANDOMVALUESGENERATORTESTER_H
#define RANDOMVALUESGENERATORTESTER_H

#include <QObject>

class RandomValuesGeneratorTester : public QObject
{
    Q_OBJECT
public:
    explicit RandomValuesGeneratorTester(QObject *parent = nullptr);

private slots:
    void randomIntKeepsRequestedRange();
    void randomStringRespectsRequestedLength();
    void randomRealSwapsInvertedRange();
};

#endif // RANDOMVALUESGENERATORTESTER_H
