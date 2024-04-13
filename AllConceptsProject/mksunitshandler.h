#ifndef MKSUNITSHANDLER_H
#define MKSUNITSHANDLER_H

#include "unitshandler.h"
#include <QObject>

/**
 * @brief The CGSUnitsHandler class represents a handler for units in the MKS
 * (Meter-Kilogram-Second) system.
 *
 * This class inherits from the abstract base class UnitsHandler and provides
 * implementations for retrieving length, mass, and time units specific to the
 * MKS system.
 */
class MKSUnitsHandler : public UnitsHandler {
public:
  explicit MKSUnitsHandler(QObject *parent = nullptr);
  virtual ~MKSUnitsHandler();
  /**
   * @brief getLengthUnits function retrieves the length units for the MKS
   * system.
   *
   * This function returns a constant reference to a string representing the
   * length units used in the MKS system.
   *
   * @return A constant reference to the string representing the length units.
   */
  const QString &getLengthUnits() const override;

  /**
   * @brief getMassUnits function retrieves the Mass units for MKS System
   *
   * This function returns a constant reference to a string
   * representing the mass units used in the MKS system.
   * @return A constant reference to the string representing the mass units.
   */
  const QString &getMassUnits() const override;
  /**
   * @brief getTimeUnits function retrieves the time units for MKS System
   *
   * This function returns a constant reference to a string
   * representing the time units used in the MKS system.
   * @return A constant reference to the string representing the time units.
   */
  virtual const QString &getTimeUnits() const override;

private:
  QString lengthUnits;
  QString massUnits;
  QString timeUnits;
};

#endif // MKSUNITSHANDLER_H
