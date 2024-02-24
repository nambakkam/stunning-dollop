#ifndef VECTORIMPLEMENTATION_H
#define VECTORIMPLEMENTATION_H

#include <QtQml>
#include <QObject>
#include <QVector>
#include <randomvaluesgenerator.h>
#include <QMetaEnum>
#include <QQmlVarPropertyHelpers.h>
#include <QFutureWatcher>

#define SMALLSIZE 10000
#define MEDIUMSIZE  50000
#define LARGESIZE 100000
#define LOWERLIMIT 10
#define UPPERLIMIT 1000
class VectorImplementation : public QObject
{
    Q_OBJECT
    QML_WRITABLE_VAR_PROPERTY(QString,description)
    QML_WRITABLE_VAR_PROPERTY(bool,disableScreen)
    Q_PROPERTY(QString vectorString READ getVectorForDisplay NOTIFY vectorChanged)

public:

    enum sizeEnum{
       SMALL = 1,
       MEDIUM,
       LARGE
   };
   Q_ENUM(sizeEnum)

    explicit VectorImplementation(QObject *parent = nullptr);
    Q_INVOKABLE void setVectorSize(VectorImplementation::sizeEnum value);
    static void declareQML() {
    qmlRegisterType<VectorImplementation>("VectorEnums", 1, 0, "VectorEnums");
    }

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
