#include "customhashtable.h"
#include "randomvaluesgenerator.h"
#include <QDebug>

CustomHashTable::CustomHashTable(QObject *parent, int size)
    : QObject{parent}, m_disableScreen{false}, m_size{size}, data{size} {}

void CustomHashTable::set() {
  QString key =
      RandomValuesGenerator::getInstance().generateRandomString(kLowerLimit);
  const int value = RandomValuesGenerator::getInstance().generateRandomInt(
      kLowerLimit, kUpperLimit);
  const int hashValue = hash(key);
  keyValuePair pair;
  pair.key = key;
  pair.value = value;
  QString desc;
  const QVector<QString> keys = getAllKeys();
  if (!keys.contains(key)) {
    data[hashValue].push_back(pair);
    desc = QString("Key: %1 and Value: %2 added to HashTable")
               .arg(key)
               .arg(value);
  } else {
    desc = QString("Key: %1 and Value: %2 is already present in hashTable")
               .arg(key)
               .arg(value);
  }
  set_description(desc);
}
int CustomHashTable::get() {
  const QVector<QString> keys = getAllKeys();
  if (keys.isEmpty()) {
    set_description("Hash table is empty");
    return 0;
  }

  const int index =
      RandomValuesGenerator::getInstance().generateRandomInt(0, keys.length() - 1);
  const QString key = keys.at(index);
  const int hashValue = hash(key);
  int value = 0;
  for (int i = 0; i < data[hashValue].length(); ++i) {
    if (data[hashValue].at(i).key == key) {
      value = data[hashValue].at(i).value;
      const QString desc = QString("Key: %1 and Value: %2").arg(key).arg(value);
      set_description(desc);
      break;
    }
  }
  return value;
}
void CustomHashTable::removeKey() {
  const QVector<QString> keys = getAllKeys();
  if (keys.isEmpty()) {
    set_description("Hash table is empty");
    return;
  }

  const int index =
      RandomValuesGenerator::getInstance().generateRandomInt(0, keys.length() - 1);
  const QString key = keys.at(index);
  const int hashValue = hash(key);
  for (int i = 0; i < data[hashValue].length(); ++i) {
    if (data[hashValue].at(i).key == key) {
      const QString desc = QString("Key: %1 and Value: %2 removed from HashTable")
                             .arg(key)
                             .arg(data[hashValue].at(i).value);
      data[hashValue].removeAt(i);
      set_description(desc);
      break;
    }
  }
}

QVector<QString> CustomHashTable::getAllKeys() {
  QVector<QString> keys;
  for (int i = 0; i < data.length(); i++) {
    for (int j = 0; j < data.at(i).length(); j++) {
      keys.append(data.at(i).at(j).key);
    }
  }
  return keys;
}

int CustomHashTable::hash(const QString &key) {
  if (m_size <= 0) {
    return 0;
  }

  int hash = 0;
  for (int i = 0; i < key.length(); ++i) {
    hash = (hash + key.at(i).unicode() * i) % m_size;
  }
  return hash;
}
void CustomHashTable::setHashTable() {
  if (m_size <= 0) {
    return;
  }

  for (int i = 0; i < m_size; ++i) {
    set();
  }
}

void CustomHashTable::createHashtable(int size) {
  int hashTableSize = 0;
  switch (size) {
  case RandomValuesGenerator::SMALL:
    hashTableSize = kSmallSize;
    break;
  case RandomValuesGenerator::MEDIUM:
    hashTableSize = kMediumSize;
    break;
  case RandomValuesGenerator::LARGE:
    hashTableSize = kLargeSize;
    break;
  default:
    return;
  }

  data.clear();
  data.resize(hashTableSize);
  m_size = hashTableSize;
  setHashTable();
  set_description("Hash Table set to selected size");
  set_disableScreen(false);
  displayHashTable();
}

void CustomHashTable::displayHashTable() {
  QVector<QString> keysValues;
  set_disableScreen(true);
  for (int i = 0; i < data.length(); ++i) {
    for (int j = 0; j < data.at(i).length(); ++j) {
      const QString pair = QString("Key: %1 Value %2 ")
                               .arg(data.at(i).at(j).key)
                               .arg(data.at(i).at(j).value);
      keysValues.append(pair);
    }
  }
  set_displayData(keysValues.toList().join(","));
  set_disableScreen(false);
}
