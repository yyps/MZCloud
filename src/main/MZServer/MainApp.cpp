#include "MainApp.h"
#include "ServerErrdef.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <getopt.h>
#include <io.h>
#include <fcntl.h>
#else
#include <sys/stat.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#endif

CMainApp::CMainApp()
{
#ifdef _WIN32
    WORD wVersionRequested;
    WSADATA wsaData;
    wVersionRequested = MAKEWORD(2, 2);
    WSAStartup(wVersionRequested, &wsaData);
#endif

    m_httpSvr = std::make_shared<CEvHttpServer>();
}

CMainApp::~CMainApp()
{

}

int CMainApp::Init()
{
    int err = ERR_SUCCESS;

    do
    {
        qDebug()<<"Avaliable drivers;";
        QStringList drivers = QSqlDatabase::drivers();
        foreach(QString driver,drivers)
        {
            qDebug()<<driver << ": " << QSqlDatabase::isDriverAvailable(driver);
        }

        QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
        if (!QSqlDatabase::isDriverAvailable("QODBC"))
        {
            qDebug()<< "driver error";
            break;
        }
        db.setDatabaseName("world");
        db.setHostName("192.168.11.100");
        db.setPort(3306);
        db.setUserName("root");
        db.setPassword("1234qwer");
        auto sqlerr = db.lastError();
        if (!db.open())
        {
            qDebug() << sqlerr.text();
            err = ERR_MYSQL_CONN;
            break;
        }
    } while (0);

    return err;
}

int CMainApp::Run()
{
    m_httpSvr->SetEventCB(nullptr);
    int err = m_httpSvr->EventLoopDispatch(7111);

    return err;
}

int CMainApp::Quit()
{
    return ERR_SUCCESS;
}
