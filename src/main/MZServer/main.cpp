#include <QCoreApplication>
#include "MainApp.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << QCoreApplication::applicationDirPath();

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
