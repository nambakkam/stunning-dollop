#ifndef CGSUNITSHANDLER_H
#define CGSUNITSHANDLER_H

#include "unitshandler.h"
#include <QObject>

class CGSUnitsHandler : public UnitsHandler {
public:
  explicit CGSUnitsHandler(QObject *parent = nullptr);
  virtual ~CGSUnitsHandler();

  virtual const QString &getLengthUnits() const override;
  virtual const QString &getMassUnits() const override;
  virtual const QString &getTimeUnits() const override;

private:
  QString lengthUnits;
  QString massUnits;
  QString timeUnits;
};

#endif // CGSUNITSHANDLER_H
