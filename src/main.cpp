#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "pbkdf2.hpp"
#include "sha256.hpp"
#include "clipboard.hpp"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    app.setOrganizationName("FogelSoft");
    app.setOrganizationDomain("github.com/derFogel");
    app.setApplicationName("c't Sesam");

    qmlRegisterType<PBKDF2>("Password", 1, 0, "PBKDF2");
    qmlRegisterType<SHA256>("Password", 1, 0, "SHA256");
    qmlRegisterType<Clipboard>("Clipboard", 1, 0, "Clipboard");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
