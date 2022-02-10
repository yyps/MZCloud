#include <QCoreApplication>
#include "MainApp.h"
#include <QDebug>
#include <iostream>
#include "ServerErrdef.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    CMainApp app;
    int err = ERR_SUCCESS;
    do
    {
        err = app.Init();
        if (err)
            break;

        err = app.Run();
        if (err)
            break;
    } while (0);

    if (err)
        exit(err);

    return a.exec();
}
