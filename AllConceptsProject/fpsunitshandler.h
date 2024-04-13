#ifndef FPSUNITSHANDLER_H
#define FPSUNITSHANDLER_H

#include "unitshandler.h"
#include <QObject>
/**
 * @brief The FPSUnitsHandler class represents a handler for units in the FPS
 * (Foot Pound Second) system.
 *
 * This class inherits from the abstract base class UnitsHandler and provides
 * implementations for retrieving length, mass, and time units specific to the
 * FPS system.
 */
class FPSUnitsHandler : public UnitsHandler {
public:
  explicit FPSUnitsHandler(QObject *parent = nullptr);
  virtual ~FPSUnitsHandler();
  /**
   * @brief getLengthUnits function retrieves the length units for the FPS
   * system.
   *
   * This function returns a constant reference to a string representing the
   * length units used in the FPS system.
   *
   * @return A constant reference to the string representing the length units.
   */
  const QString &getLengthUnits() const override;
  /**
   * @brief getMassUnits function retrieves the Mass units for FPS System
   *
   * This function returns a constant reference to a string
   * representing the mass units used in the FPS system.
   * @return A constant reference to the string representing the mass units.
   */
  const QString &getMassUnits() const override;
  /**
   * @brief getTimeUnits function retrieves the time units for FPS System
   *
   * This function returns a constant reference to a string
   * representing the time units used in the FPS system.
   * @return A constant reference to the string representing the time units.
   */
  const QString &getTimeUnits() const override;

private:
  QString lengthUnits;
  QString massUnits;
  QString timeUnits;
};

#endif // FPSUNITSHANDLER_H
