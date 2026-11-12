#include "customhashtable.h"
#include "itemlistcontroller.h"
#include "itemlistmodel.h"
#include "randomvaluesgenerator.h"
#include "taskviewmodel.h"
#include "unitsfactory.h"
#include "vectorimplementation.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
int main(int argc, char *argv[]) {
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
  QGuiApplication app(argc, argv);

  ItemListModel itemListModel;
  ItemListController itemListController(&itemListModel);
  TaskViewModel taskViewModel;
  QQmlApplicationEngine engine;
  VectorImplementation *vectorHandler = new VectorImplementation(&app);
  UnitsFactory *unitsFactory = new UnitsFactory(&app);
  CustomHashTable *hashTable = new CustomHashTable(&app);
  engine.rootContext()->setContextProperty("vectorHandler", vectorHandler);
  engine.rootContext()->setContextProperty("hashTableHandler", hashTable);
  engine.rootContext()->setContextProperty("unitsFactory", unitsFactory);
  engine.rootContext()->setContextProperty("itemListModel", &itemListModel);
  engine.rootContext()->setContextProperty("itemListController", &itemListController);
  engine.rootContext()->setContextProperty("taskViewModel", &taskViewModel);
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
