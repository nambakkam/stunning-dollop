#include "randomvaluesgenerator.h"

#include <algorithm>

RandomValuesGenerator::RandomValuesGenerator(QObject *parent)
    : QObject{parent}, m_rng(std::random_device{}()) {}
RandomValuesGenerator &RandomValuesGenerator::getInstance() {
  static RandomValuesGenerator instance;
  return instance;
}

int RandomValuesGenerator::generateRandomInt(int min, int max) {
  if (min > max) {
    std::swap(min, max);
  }

  std::uniform_int_distribution<int> dist(min, max);
  return dist(m_rng);
}

double RandomValuesGenerator::generateRandomReal(double min, double max) {
  if (min > max) {
    std::swap(min, max);
  }

  std::uniform_real_distribution<double> dist(min, max);
  return dist(m_rng);
}

QString RandomValuesGenerator::generateRandomString(int strLength) {
  if (strLength <= 0) {
    return QString();
  }

  const QString possibleCharacters(
      "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
  QString randomString;
  randomString.reserve(strLength);

  for (int i = 0; i < strLength; ++i) {
    const int index =
        QRandomGenerator::global()->bounded(possibleCharacters.length());
    const QChar nextChar = possibleCharacters.at(index);
    randomString.append(nextChar);
  }
  return randomString;
}
