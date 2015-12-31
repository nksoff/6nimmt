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
    catch(std::exception &exc) {
        QMessageBox::critical(NULL, applicationDisplayName(), exc.what());
        exit();
    }
    catch(...) {
        QMessageBox::critical(NULL, applicationDisplayName(), "Unknown error");
        exit();
    }

    return false;
}
