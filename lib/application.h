#ifndef APPLICATION_H
#define APPLICATION_H

#include "lib/main.h"

#include <QApplication>
#include <QMessageBox>

class Application : public QApplication
{
public:
    Application(int &argc, char **argv);

    virtual bool notify(QObject *, QEvent *);
};

#endif // APPLICATION_H
