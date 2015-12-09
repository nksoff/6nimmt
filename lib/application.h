#ifndef APPLICATION_H
#define APPLICATION_H

#include <QGuiApplication>

class Application : public QGuiApplication
{
public:
    Application(int &argc, char **argv);
};

#endif // APPLICATION_H
