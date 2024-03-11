#include "vectorimplementation.h"
#include <QFuture>
#include <QtConcurrent>
VectorImplementation::VectorImplementation(QObject *parent)
    : QObject{parent}, m_disableScreen(false) {
  QObject::connect(
      &vectorFutureWatcher, &QFutureWatcher<void>::finished, [this]() {
        set_disableScreen(false);
        set_description("Random vector of size " +
                        QString::number(vector.size()) + " generated");
        emit vectorChanged();
      });
}

void VectorImplementation::setVectorSize(
    RandomValuesGenerator::sizeEnum value) {

  qDebug() << "Inside setVectorSize ";
  size_t size = 0;
  switch (value) {
  case RandomValuesGenerator::SMALL:
    size = SMALLSIZE;
    break;
  case RandomValuesGenerator::MEDIUM:
    size = MEDIUMSIZE;
    break;
  case RandomValuesGenerator::LARGE:
    size = LARGESIZE;
    break;
  default:
    break;
  }

  QFuture<void> vectorFuture = QtConcurrent::run(
      this, &VectorImplementation::generateRandomVector, size);
  vectorFutureWatcher.setFuture(vectorFuture);
  set_disableScreen(true);
  set_description("Please Wait while the vector Loads");
}

void VectorImplementation::pushRandomNumber() {
  int randomNumber = RandomValuesGenerator::getInstance().generateRandomInt(
      LOWERLIMIT, UPPERLIMIT);
  vector.push_back(randomNumber);
  set_description(
      QString("Random number %1 pushed to the vector").arg(randomNumber));
  emit vectorChanged();
}

void VectorImplementation::popLastNumber() {
  int lastNumber = vector.last();
  vector.pop_back();
  set_description(
      QString("Last Number %1 popped from the vector").arg(lastNumber));
  emit vectorChanged();
}

void VectorImplementation::insertatRandomIndex() {
  int randomIndex =
      RandomValuesGenerator::getInstance().generateRandomInt(0, vector.size());
  int randomNumber = RandomValuesGenerator::getInstance().generateRandomInt(
      LOWERLIMIT, UPPERLIMIT);
  vector.insert(randomIndex, randomNumber);
  set_description(QString("%1 inserted at the index %2")
                      .arg(randomNumber)
                      .arg(randomIndex));
  emit vectorChanged();
}

void VectorImplementation::searchRandomNumber() {
  int randomNumber = RandomValuesGenerator::getInstance().generateRandomInt(
      LOWERLIMIT, UPPERLIMIT);
  bool numberPresent = vector.contains(randomNumber);
  if (numberPresent) {
    set_description(QString("%1 is present in the vector ").arg(randomNumber));
  } else {
    set_description(
        QString("%1 is not present in the vector ").arg(randomNumber));
  }
}

void VectorImplementation::valueAtRandomIndex() {
  int randomIndex =
      RandomValuesGenerator::getInstance().generateRandomInt(0, vector.size());
  int number = vector.at(randomIndex);
  set_description(QString("%1 is found at the index %2 of the vector ")
                      .arg(number)
                      .arg(randomIndex));
}

QString VectorImplementation::getVectorForDisplay() {
  QByteArray data;
  std::copy(vector.begin(), vector.end(), std::back_inserter(data));

  //    qDebug() << data.toHex( ' ' );
  return QString(data.toHex(','));
}

void VectorImplementation::removeatRandomIndex() {
  int randomIndex =
      RandomValuesGenerator::getInstance().generateRandomInt(0, vector.size());
  int randomValue = vector.at(randomIndex);
  vector.removeAt(randomIndex);
  set_description(QString("Value %1 Removed at the index ").arg(randomValue) +
                  QString::number(randomIndex));
  emit vectorChanged();
}

void VectorImplementation::generateRandomVector(size_t size) {
  qDebug() << "Inside generateRandomVector";
  vector.clear();
  for (size_t i = 0; i < size; i++) {
    vector.push_back(RandomValuesGenerator::getInstance().generateRandomInt(
        LOWERLIMIT, UPPERLIMIT));
  }
  qDebug() << "First 3 elements " << vector.at(0) << "," << vector.at(1) << ","
           << vector.at(2);
}
