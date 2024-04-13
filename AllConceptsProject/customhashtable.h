#ifndef CUSTOMHASHTABLE_H
#define CUSTOMHASHTABLE_H

#include <QFutureWatcher>
#include <QObject>
#include <QQmlVarPropertyHelpers.h>
#include <QVector>
/**
 * @brief The CustomHashTable class provides a custom implementation of a Hash
 * Table.
 *
 * This class provides functionality to create, set, get, and remove key-value
 * pairs in the hash table. Additionally, it offers methods to retrieve all keys
 * and display the contents of the hash table.
 */
class CustomHashTable : public QObject {
  Q_OBJECT
  QML_WRITABLE_VAR_PROPERTY(QString,
                            displayData) /**< Property for displaying data. */
  QML_WRITABLE_VAR_PROPERTY(
      QString, description) /**< Property for displaying description while
                               buttons are pressed on UI. */
  QML_WRITABLE_VAR_PROPERTY(bool,
                            disableScreen) /**< Property for disabling screen
                                              while the Hashtable Loads. */

public:
  explicit CustomHashTable(QObject *parent = nullptr, int size = 50);
  /**
   * @brief The keyValuePair struct provides the key and value pair for
   * implementing HashTable
   */
  struct keyValuePair {
    QString key;
    int value;
  };
public slots:
  /**
   * @brief createHashtable creates a new hash table with the
   * specified size.
   * @param size parameter is the size of the hash table to be created.
   */
  void createHashtable(int size);
  /**
   * @brief set inserts a random Key and a Value Pair
   * The function uses RandomValuesGenerator to generate random String and Int
   * values and adds them to HashTable
   */
  void set();
  /**
   * @brief get returns the value at a random key
   * RandomValuesGenerator is used to generate a randomkey and value at that key
   * is returned
   * @return returns the integer value at a particular key
   */
  int get();
  /**
   * @brief removeKey removes a random Key and a Value Pair from the HashTable
   * RandomValuesGenerator is used to generate a randomkey and that keyValue
   * pair is deleted from the HashTable
   */
  void removeKey();
  /**
   * @brief getAllKeys retrieves all keys present in the hash table.
   *
   * @return A vector containing all keys present in the hash table.
   */
  QVector<QString> getAllKeys();
  /**
   * @brief displayHashTable displays the contents of the hash table.
   */
  void displayHashTable();
signals:

private:
  int m_size;
  /**
   * @brief hash computes the hash value for a given key.
   *
   * @param key The key for which to compute the hash value.
   * @return The hash value computed for the given key.
   */
  int hash(const QString &key);
  QVector<QVector<keyValuePair>> data;
  /**
   * @brief Sets up the hash table.
   */
  void setHashTable();
  QFutureWatcher<void> hashFutureWatcher;
};

#endif // CUSTOMHASHTABLE_H
