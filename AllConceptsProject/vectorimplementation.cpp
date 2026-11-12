#include "vectorimplementation.h"
#include "randomvaluesgenerator.h"

#include <QStringList>

VectorImplementation::VectorImplementation(QObject *parent)
    : QObject{parent}, m_disableScreen(false) {}

void VectorImplementation::setVectorSize(int value) {
  size_t size = 0;
  switch (value) {
  case RandomValuesGenerator::SMALL:
    size = kSmallSize;
    break;
  case RandomValuesGenerator::MEDIUM:
    size = kMediumSize;
    break;
  case RandomValuesGenerator::LARGE:
    size = kLargeSize;
    break;
  default:
    set_description("Unsupported vector size requested");
    return;
  }

  generateRandomVector(size);
  set_disableScreen(false);
  set_description("Random vector of size " + QString::number(vector.size()) +
                  " generated");
  emit vectorChanged();
}

void VectorImplementation::pushRandomNumber() {
  const int randomNumber = RandomValuesGenerator::getInstance().generateRandomInt(
      kLowerLimit, kUpperLimit);
  vector.push_back(randomNumber);
  set_description(
      QString("Random number %1 pushed to the vector").arg(randomNumber));
  emit vectorChanged();
}

void VectorImplementation::popLastNumber() {
  if (vector.isEmpty()) {
    set_description("Vector is empty");
    return;
  }

  const int lastNumber = vector.last();
  vector.pop_back();
  set_description(
      QString("Last Number %1 popped from the vector").arg(lastNumber));
  emit vectorChanged();
}

void VectorImplementation::insertatRandomIndex() {
  if (vector.isEmpty()) {
    pushRandomNumber();
    return;
  }

  const int randomIndex =
      RandomValuesGenerator::getInstance().generateRandomInt(0, vector.size() - 1);
  const int randomNumber = RandomValuesGenerator::getInstance().generateRandomInt(
      kLowerLimit, kUpperLimit);
  vector.insert(randomIndex, randomNumber);
  set_description(QString("%1 inserted at the index %2")
                      .arg(randomNumber)
                      .arg(randomIndex));
  emit vectorChanged();
}

void VectorImplementation::searchRandomNumber() {
  if (vector.isEmpty()) {
    set_description("Vector is empty");
    return;
  }

  const int randomNumber = RandomValuesGenerator::getInstance().generateRandomInt(
      kLowerLimit, kUpperLimit);
  const bool numberPresent = vector.contains(randomNumber);
  if (numberPresent) {
    set_description(QString("%1 is present in the vector ").arg(randomNumber));
  } else {
    set_description(
        QString("%1 is not present in the vector ").arg(randomNumber));
  }
}

void VectorImplementation::valueAtRandomIndex() {
  if (vector.isEmpty()) {
    set_description("Vector is empty");
    return;
  }

  const int randomIndex =
      RandomValuesGenerator::getInstance().generateRandomInt(0, vector.size() - 1);
  const int number = vector.at(randomIndex);
  set_description(QString("%1 is found at the index %2 of the vector ")
                      .arg(number)
                      .arg(randomIndex));
}

QString VectorImplementation::getVectorForDisplay() {
  QStringList values;
  values.reserve(vector.size());
  for (const int value : vector) {
    values << QString::number(value);
  }
  return values.join(QStringLiteral(", "));
}

void VectorImplementation::removeatRandomIndex() {
  if (vector.isEmpty()) {
    set_description("Vector is empty");
    return;
  }

  const int randomIndex =
      RandomValuesGenerator::getInstance().generateRandomInt(0, vector.size() - 1);
  const int randomValue = vector.at(randomIndex);
  vector.removeAt(randomIndex);
  set_description(QString("Value %1 Removed at the index ").arg(randomValue) +
                  QString::number(randomIndex));
  emit vectorChanged();
}

void VectorImplementation::generateRandomVector(size_t size) {
  vector.clear();
  vector.reserve(static_cast<int>(size));
  for (size_t i = 0; i < size; ++i) {
    vector.push_back(RandomValuesGenerator::getInstance().generateRandomInt(
        kLowerLimit, kUpperLimit));
  }
}
