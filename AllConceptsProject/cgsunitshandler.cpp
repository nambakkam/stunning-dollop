#include "cgsunitshandler.h"

CGSUnitsHandler::CGSUnitsHandler(QObject *parent)
    : UnitsHandler{parent}, lengthUnits{"cm"},massUnits{"g"},timeUnits{"s"}
{

}

CGSUnitsHandler::~CGSUnitsHandler()
{

}

const QString &CGSUnitsHandler::getLengthUnits() const
{
    return lengthUnits;
}

const QString &CGSUnitsHandler::getMassUnits() const
{
    return massUnits;
}

const QString &CGSUnitsHandler::getTimeUnits() const
{
    return timeUnits;
}
