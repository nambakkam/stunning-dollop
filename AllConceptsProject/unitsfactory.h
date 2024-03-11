#ifndef UNITSFACTORY_H
#define UNITSFACTORY_H

#include "unitshandler.h"
#include <QMetaEnum>
#include <QObject>
#include <QQmlVarPropertyHelpers.h>

class UnitsFactory : public QObject {
  Q_OBJECT

  QML_WRITABLE_VAR_PROPERTY(QString, lengthUnits)
  QML_WRITABLE_VAR_PROPERTY(QString, massUnits)
  QML_WRITABLE_VAR_PROPERTY(QString, timeUnits)

public:
  enum productEnum { CGS, MKS, FPS };
  Q_ENUM(productEnum)
  explicit UnitsFactory(QObject *parent = nullptr);
  UnitsHandler *factoryMethod(productEnum value) const;
  Q_INVOKABLE void setUnits(UnitsFactory::productEnum value);
signals:

private:
};

#endif // UNITSFACTORY_H
