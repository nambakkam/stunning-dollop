#ifndef RANDOMVALUESGENERATOR_H
#define RANDOMVALUESGENERATOR_H
#include <QObject>
#include <QRandomGenerator>
#include <QString>
#include <QtQml>
#include <random>

#define SMALLSIZE 10000
#define MEDIUMSIZE 50000
#define LARGESIZE 100000
#define LOWERLIMIT 10
#define UPPERLIMIT 1000

class RandomValuesGenerator : public QObject {
  Q_OBJECT
public:
  enum sizeEnum { SMALL = 1, MEDIUM, LARGE };
  Q_ENUM(sizeEnum)
  static RandomValuesGenerator &getInstance();
  int generateRandomInt(int min, int max);
  double generateRandomReal(double min, double max);
  QString generateRandomString(int strLength);

private:
  RandomValuesGenerator(QObject *parent = nullptr);
  std::mt19937 m_rng;
};

#endif // RANDOMVALUESGENERATOR_H
