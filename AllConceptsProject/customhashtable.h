#ifndef CUSTOMHASHTABLE_H
#define CUSTOMHASHTABLE_H

#include <QFutureWatcher>
#include <QObject>
#include <QQmlVarPropertyHelpers.h>
#include <QVector>
class CustomHashTable : public QObject {
  Q_OBJECT
  QML_WRITABLE_VAR_PROPERTY(QString, displayData)
  QML_WRITABLE_VAR_PROPERTY(QString, description)
  QML_WRITABLE_VAR_PROPERTY(bool, disableScreen)

public:
  explicit CustomHashTable(QObject *parent = nullptr, int size = 50);
  struct keyValuePair {
    QString key;
    int value;
  };
public slots:
  void createHashtable(int size);
  void set();
  int get();
  void removeKey();
  QVector<QString> getAllKeys();
  void displayHashTable();
signals:

private:
  int m_size;
  int hash(const QString &key);
  QVector<QVector<keyValuePair>> data;
  void setHashTable();
  QFutureWatcher<void> hashFutureWatcher;
};

#endif // CUSTOMHASHTABLE_H
