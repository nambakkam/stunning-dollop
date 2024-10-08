#include "customhashtable.h"
#include "randomvaluesgenerator.h"
#include "unitsfactory.h"
#include "vectorimplementation.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
int main(int argc, char *argv[]) {
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;
  VectorImplementation *vectorHandler = new VectorImplementation;
  UnitsFactory *unitsFactory = new UnitsFactory;
  CustomHashTable *hashTable = new CustomHashTable;
  engine.rootContext()->setContextProperty("vectorHandler", vectorHandler);
  engine.rootContext()->setContextProperty("hashTableHandler", hashTable);
  engine.rootContext()->setContextProperty("unitsFactory", unitsFactory);
  const QUrl url(QStringLiteral("qrc:/main.qml"));
  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreated, &app,
      [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
          QCoreApplication::exit(-1);
      },
      Qt::QueuedConnection);
  engine.load(url);

  return app.exec();
}
