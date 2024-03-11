#ifndef MKSUNITSHANDLER_H
#define MKSUNITSHANDLER_H

#include "unitshandler.h"
#include <QObject>

class MKSUnitsHandler : public UnitsHandler {
public:
  explicit MKSUnitsHandler(QObject *parent = nullptr);
  virtual ~MKSUnitsHandler();

  virtual const QString &getLengthUnits() const override;
  virtual const QString &getMassUnits() const override;
  virtual const QString &getTimeUnits() const override;

private:
  QString lengthUnits;
  QString massUnits;
  QString timeUnits;
};

#endif // MKSUNITSHANDLER_H
