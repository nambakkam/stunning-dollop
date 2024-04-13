#ifndef CGSUNITSHANDLER_H
#define CGSUNITSHANDLER_H

#include "unitshandler.h"
#include <QObject>

/**
 * @brief The CGSUnitsHandler class represents a handler for units in the CGS
 * (Centimeter-Gram-Second) system.
 *
 * This class inherits from the abstract base class UnitsHandler and provides
 * implementations for retrieving length, mass, and time units specific to the
 * CGS system.
 */
class CGSUnitsHandler : public UnitsHandler {
public:
  explicit CGSUnitsHandler(QObject *parent = nullptr);
  virtual ~CGSUnitsHandler();
  /**
   * @brief getLengthUnits function retrieves the length units for the CGS
   * system.
   *
   * This function returns a constant reference to a string representing the
   * length units used in the CGS system.
   *
   * @return A constant reference to the string representing the length units.
   */
  const QString &getLengthUnits() const override;
  /**
   * @brief getMassUnits function retrieves the Mass units for CGS System
   *
   * This function returns a constant reference to a string
   * representing the mass units used in the CGS system.
   * @return A constant reference to the string representing the mass units.
   */
  const QString &getMassUnits() const override;
  /**
   * @brief getTimeUnits function retrieves the time units for CGS System
   *
   * This function returns a constant reference to a string
   * representing the time units used in the CGS system.
   * @return A constant reference to the string representing the time units.
   */
  const QString &getTimeUnits() const override;

private:
  QString lengthUnits;
  QString massUnits;
  QString timeUnits;
};

#endif // CGSUNITSHANDLER_H
