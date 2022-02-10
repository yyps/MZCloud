#include "MainApp.h"
#include "ServerErrdef.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include "mysql_com.h"

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
    m_mysql = std::make_shared<CMySQLWrapper>();
}

CMainApp::~CMainApp()
{
    Quit();
}

int CMainApp::Init()
{
    int err = ERR_SUCCESS;

    do
    {
        std::cout << "db init..." <<std::endl;
        err = m_mysql->Init();
        if (err)
        {
            std::cerr << "Error: mysql init err!" <<std::endl;
            break;
        }

        auto conn = m_mysql->GetConnInfo();
        conn->m_ip = "192.168.8.89";
        conn->m_port = 3306;
        conn->m_dbname = "world";
        conn->m_usrname = "root";
        conn->m_passwd = "1234qwer";

        std::cout << "db connect..." <<std::endl;
        err = m_mysql->Connect();
        if (err)
        {
            std::cout << "Error: mysql connect err : " << err << " " << m_mysql->GetMySQLError() <<std::endl;
            break;
        }
        std::cout << "db connect ok" <<std::endl;

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
    m_mysql->Release();
    return ERR_SUCCESS;
}
