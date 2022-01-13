#include <QCoreApplication>
#include "MainApp.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CMainApp app;
    do
    {
        if (app.Init())
            break;

        if (app.Run())
            break;
    } while (0);

    return a.exec();
}
