#include <QGuiApplication>
#include <QQmlApplicationEngine>
//BAĞLAMAK İÇİN GEREKLİ KÜTÜPHANE
#include <QQmlContext>

//ISLEM DOSYAMI BAĞLIYORUM.
#include "islem.h"

//MODEL DOSYAMI BAĞLIYORUM.
#include "listmodel.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    Islem database;
    database.veritabaniBaglan();

    ListModel *model = new ListModel();

    engine.rootContext()->setContextProperty("database", &database);
    engine.rootContext()->setContextProperty("myModel", model);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
