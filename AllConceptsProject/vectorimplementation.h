#ifndef VECTORIMPLEMENTATION_H
#define VECTORIMPLEMENTATION_H

#include "randomvaluesgenerator.h"
#include <QFutureWatcher>
#include <QMetaEnum>
#include <QObject>
#include <QQmlVarPropertyHelpers.h>
#include <QVector>
#include <QtQml>
class VectorImplementation : public QObject {
  Q_OBJECT
  QML_WRITABLE_VAR_PROPERTY(QString, description)
  QML_WRITABLE_VAR_PROPERTY(bool, disableScreen)
  Q_PROPERTY(QString vectorString READ getVectorForDisplay NOTIFY vectorChanged)

public:
  explicit VectorImplementation(QObject *parent = nullptr);
  Q_INVOKABLE void setVectorSize(int value);

public slots:
  void pushRandomNumber();
  void popLastNumber();
  void insertatRandomIndex();
  void removeatRandomIndex();
  void searchRandomNumber();
  void valueAtRandomIndex();
  QString getVectorForDisplay();
signals:
  void vectorChanged();

private:
  QVector<int> vector;
  void generateRandomVector(size_t size);
  QFutureWatcher<void> vectorFutureWatcher;
};

#endif // VECTORIMPLEMENTATION_H
