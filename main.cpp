#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>

#include "lib/application.h"

int main(int argc, char **argv)
{
    Application app(argc, argv);
    return app.exec();
}
