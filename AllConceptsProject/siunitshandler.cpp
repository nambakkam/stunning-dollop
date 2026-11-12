#include "siunitshandler.h"

SIUnitsHandler::SIUnitsHandler(QObject *parent)
    : UnitsHandler{parent}, lengthUnits{"m"}, massUnits{"kg"}, timeUnits{"s"} {}

const QString &SIUnitsHandler::getLengthUnits() const { return lengthUnits; }

const QString &SIUnitsHandler::getMassUnits() const { return massUnits; }

const QString &SIUnitsHandler::getTimeUnits() const { return timeUnits; }
