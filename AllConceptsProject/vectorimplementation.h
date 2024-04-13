#ifndef VECTORIMPLEMENTATION_H
#define VECTORIMPLEMENTATION_H

#include <QFutureWatcher>
#include <QMetaEnum>
#include <QObject>
#include <QQmlVarPropertyHelpers.h>
#include <QVector>
#include <QtQml>
/**
 * @brief The VectorImplementation class provides functionality for manipulating
 * a vector of integers.
 *
 * This class allows operations such as adding, removing, inserting elements,
 * searching for elements, and accessing elements at specific indices in the
 * vector.
 */
class VectorImplementation : public QObject {
  Q_OBJECT
  QML_WRITABLE_VAR_PROPERTY(
      QString, description) /**< Property for describing the vector. */
  QML_WRITABLE_VAR_PROPERTY(
      bool, disableScreen) /**< Property for disabling the screen. */
  Q_PROPERTY(QString vectorString READ getVectorForDisplay NOTIFY
                 vectorChanged) /**< Property for displaying the vector. */

public:
  explicit VectorImplementation(QObject *parent = nullptr);
  /**
   * @brief setVectorSize sets the size of the vector.
   *
   * @param value The size of the vector.
   */
  Q_INVOKABLE void setVectorSize(int value);

public slots:
  /**
   * @brief pushRandomNumber adds a random number to the vector.
   * The RandomValuesGenerator class is used for generating random integer
   * values
   */
  void pushRandomNumber();
  /**
   * @brief popLastNumber removes the last number from the vector.
   */
  void popLastNumber();
  /**
   * @brief insertatRandomIndex inserts a random number at a random index in the
   * vector.
   */
  void insertatRandomIndex();
  /**
   * @brief removeatRandomIndex removes an element at a random index from the
   * vector.
   */
  void removeatRandomIndex();
  /**
   * @brief searchRandomNumber searches for a random number in the vector.
   */
  void searchRandomNumber();
  /**
   * @brief valueAtRandomIndex retrieves the value at a random index in the
   * vector.
   *
   * @return A string representation of the value at the random index.
   */
  void valueAtRandomIndex();
  /**
   * @brief getVectorForDisplay retrieves the vector as a string for display.
   *
   * @return A string representation of the vector.
   */
  QString getVectorForDisplay();
signals:
  void vectorChanged();

private:
  QVector<int> vector;
  /**
   * @brief generateRandomVector generates a random vector of a given size.
   *
   * @param size The size of the vector to generate.
   */
  void generateRandomVector(size_t size);
  QFutureWatcher<void>
      vectorFutureWatcher; /**< Watcher for asynchronous vector operations. */
};

#endif // VECTORIMPLEMENTATION_H
