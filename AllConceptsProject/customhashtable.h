#ifndef CUSTOMHASHTABLE_H
#define CUSTOMHASHTABLE_H

#include <QObject>
#include <QVector>
#include <QQmlVarPropertyHelpers.h>
class CustomHashTable : public QObject
{
    Q_OBJECT
    QML_WRITABLE_VAR_PROPERTY(QString,displayData);
public:
    explicit CustomHashTable(QObject *parent = nullptr,int size = 50);
    struct keyValuePair{
        QString key;
        int value;
    };
public slots:
    void createHashtable(int size);
    void set();
    int get();
    void removeKey();
    QVector<QString> getAllKeys();
signals:

private:
    int m_size;
    int hash(const QString &key);
    QVector<QVector<keyValuePair>> data;
    void displayData();
};

#endif // CUSTOMHASHTABLE_H
