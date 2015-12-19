#include "application.h"

Application::Application(int &argc, char **argv) : QApplication(argc, argv)
{
}

bool Application::notify(QObject *receiver, QEvent *event)
{
    try
    {
        return QApplication::notify(receiver, event);
    }
    catch(OwnException &exc)
    {
        QMessageBox::critical(NULL, applicationDisplayName(), exc.what());
        if(exc.isFatal())
        {
            exit();
        }
    }

    return false;
}
