#ifndef RANDOMVALUESGENERATOR_H
#define RANDOMVALUESGENERATOR_H
#include <QRandomGenerator>
#include <QString>
#include <random>

#define SMALLSIZE 10000
#define MEDIUMSIZE 50000
#define LARGESIZE 100000
#define LOWERLIMIT 10
#define UPPERLIMIT 1000

class RandomValuesGenerator {
public:
  static RandomValuesGenerator &getInstance();
  RandomValuesGenerator(const RandomValuesGenerator &) = delete;
  void operator=(const RandomValuesGenerator &) = delete;
  int generateRandomInt(int min, int max);
  double generateRandomReal(double min, double max);
  QString generateRandomString(int strLength);

private:
  RandomValuesGenerator();
  std::mt19937 m_rng;
};

#endif // RANDOMVALUESGENERATOR_H
