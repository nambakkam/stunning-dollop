#include "unitsfactory.h"
#include "cgsunitshandler.h"
#include "fpsunitshandler.h"
#include "mksunitshandler.h"
#include <memory>

UnitsFactory::UnitsFactory(QObject *parent)
    : QObject{parent}, m_lengthUnits{""}, m_massUnits{""}, m_timeUnits{""} {}

void UnitsFactory::setUnits(UnitsFactory::productEnum value) {
  std::unique_ptr<UnitsHandler> product(factoryMethod(value));
  set_lengthUnits(product->getLengthUnits());
  set_massUnits(product->getMassUnits());
  set_timeUnits(product->getTimeUnits());
}

UnitsHandler *UnitsFactory::factoryMethod(productEnum value) const {
  switch (value) {
  case CGS:
    return new CGSUnitsHandler;
    break;
  case MKS:
    return new MKSUnitsHandler;
    break;
  case FPS:
    return new FPSUnitsHandler;
    break;
  default:
    return nullptr;
    break;
  }
}
