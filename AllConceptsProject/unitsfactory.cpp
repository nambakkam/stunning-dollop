#include "unitsfactory.h"
#include "cgsunitshandler.h"
#include "fpsunitshandler.h"
#include "mksunitshandler.h"
#include "siunitshandler.h"
#include <memory>

UnitsFactory::UnitsFactory(QObject *parent)
    : QObject{parent}, m_lengthUnits{""}, m_massUnits{""}, m_timeUnits{""} {}

void UnitsFactory::setUnits(UnitsFactory::productEnum value) {
  std::unique_ptr<UnitsHandler> product = factoryMethod(value);
  if (product == nullptr) {
    return;
  }

  set_lengthUnits(product->getLengthUnits());
  set_massUnits(product->getMassUnits());
  set_timeUnits(product->getTimeUnits());
}

std::unique_ptr<UnitsHandler> UnitsFactory::factoryMethod(productEnum value) const {
  switch (value) {
  case CGS:
    return std::make_unique<CGSUnitsHandler>();
  case MKS:
    return std::make_unique<MKSUnitsHandler>();
  case FPS:
    return std::make_unique<FPSUnitsHandler>();
  case SI:
    return std::make_unique<SIUnitsHandler>();
  default:
    return nullptr;
  }
}
