#ifndef SIUNITSHANDLER_H
#define SIUNITSHANDLER_H

#include "unitshandler.h"

/** Provides SI base units for length, mass, and time. */
class SIUnitsHandler : public UnitsHandler {
public:
  explicit SIUnitsHandler(QObject *parent = nullptr);
  const QString &getLengthUnits() const override;
  const QString &getMassUnits() const override;
  const QString &getTimeUnits() const override;

private:
  QString lengthUnits;
  QString massUnits;
  QString timeUnits;
};

#endif // SIUNITSHANDLER_H
