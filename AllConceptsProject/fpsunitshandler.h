#ifndef FPSUNITSHANDLER_H
#define FPSUNITSHANDLER_H

#include "unitshandler.h"
#include <QObject>

class FPSUnitsHandler : public UnitsHandler
{
public:
    explicit FPSUnitsHandler(QObject *parent = nullptr);
    virtual ~FPSUnitsHandler();
    virtual const QString& getLengthUnits() const override;
    virtual const QString& getMassUnits() const override;
    virtual const QString& getTimeUnits() const override;

private:
    QString lengthUnits;
    QString massUnits;
    QString timeUnits;
};

#endif // FPSUNITSHANDLER_H
