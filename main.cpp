#include <QApplication>

#include "lib/main.h"
#include "lib/application.h"
#include "lib/windows/mainwindow.h"

int main(int argc, char **argv)
{
    Application app(argc, argv);
    MainWindow mainWin;
    mainWin.show();
    return app.exec();
}
