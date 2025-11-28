#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "userviewmodel.h"
#include "userfiltermodel.h"
#include <qqml.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/UserViewAndFilterModel_Example/main.qml"));

    qmlRegisterType<UserFilterModel>("UserViewAndFilterModel_Example", 1, 0, "UserFilterModel");
    // qmlRegisterType<UserViewModel>("UserViewAndFilterModel_Example", 1, 0, "UserViewModel");

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
