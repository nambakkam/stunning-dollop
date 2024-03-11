#include "mksunitshandler.h"

MKSUnitsHandler::MKSUnitsHandler(QObject *parent)
    : UnitsHandler{parent}, lengthUnits{"metre"}, massUnits{"kg"}, timeUnits{
                                                                       "s"} {}

MKSUnitsHandler::~MKSUnitsHandler() {}

const QString &MKSUnitsHandler::getLengthUnits() const { return lengthUnits; }

const QString &MKSUnitsHandler::getMassUnits() const { return massUnits; }

const QString &MKSUnitsHandler::getTimeUnits() const { return timeUnits; }
