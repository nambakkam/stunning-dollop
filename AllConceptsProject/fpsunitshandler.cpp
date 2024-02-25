#include "fpsunitshandler.h"

FPSUnitsHandler::FPSUnitsHandler(QObject *parent)
    : UnitsHandler{parent},lengthUnits{"ft"},massUnits{"lb"},timeUnits{"s"}
{

}

FPSUnitsHandler::~FPSUnitsHandler()
{

}

const QString &FPSUnitsHandler::getLengthUnits() const
{
    return lengthUnits;
}

const QString &FPSUnitsHandler::getMassUnits() const
{
    return massUnits;
}

const QString &FPSUnitsHandler::getTimeUnits() const
{
    return timeUnits;
}
