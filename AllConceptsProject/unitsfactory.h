#ifndef UNITSFACTORY_H
#define UNITSFACTORY_H

#include "unitshandler.h"
#include <QMetaEnum>
#include <QObject>
#include <QQmlVarPropertyHelpers.h>
/**
 * @brief The UnitsFactory class provides a factory for creating instances of
 * UnitsHandler.
 *
 * This class enables the creation of UnitsHandler instances corresponding to
 * different unit systems, such as CGS (Centimeter-Gram-Second), MKS
 * (Meter-Kilogram-Second), and FPS (Foot-Pound-Second).
 */
class UnitsFactory : public QObject {
  Q_OBJECT

  QML_WRITABLE_VAR_PROPERTY(QString,
                            lengthUnits) /**< Property for length units. */
  QML_WRITABLE_VAR_PROPERTY(QString, massUnits) /**< Property for mass units. */
  QML_WRITABLE_VAR_PROPERTY(QString, timeUnits) /**< Property for time units. */

public:
  /**
   * @brief productEnum is the enum defining the supported unit systems.
   */
  enum productEnum { CGS, MKS, FPS };
  Q_ENUM(productEnum)
  explicit UnitsFactory(QObject *parent = nullptr);
  /**
   * @brief factoryMethod creates a UnitsHandler instance based on the
   * specified unit system.
   *
   * @param value The unit system enum value.
   * @return Pointer to the created UnitsHandler instance.
   */
  UnitsHandler *factoryMethod(productEnum value) const;
  /**
   * @brief Sets the unit system for length, mass, and time simultaneously.
   *
   * This method sets the unit system for length, mass, and time simultaneously
   * based on the specified enum value.
   *
   * @param value The unit system enum value.
   */
  Q_INVOKABLE void setUnits(UnitsFactory::productEnum value);
signals:

private:
};

#endif // UNITSFACTORY_H
