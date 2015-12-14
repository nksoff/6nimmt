#include <QApplication>
#include <QQmlApplicationEngine>
#include <QMessageBox>

#include "lib/mainwindow.h"
#include "lib/ownexception.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    MainWindow mainWin;
    mainWin.show();
    return app.exec();
}
