#ifndef UNITSHANDLER_H
#define UNITSHANDLER_H

#include <QObject>
#include <QString>

class UnitsHandler : public QObject
{
    Q_OBJECT
public:
    explicit UnitsHandler(QObject *parent = nullptr);
    virtual ~UnitsHandler();
    virtual const QString& getLengthUnits() const = 0; //Pure Virtual Function
    virtual const QString& getMassUnits() const = 0;
    virtual const QString& getTimeUnits() const = 0;
signals:

private:



};

#endif // UNITSHANDLER_H
