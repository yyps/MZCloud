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


//typedef std::shared_ptr<sql::Connection> connection_ptr;
//typedef std::shared_ptr<sql::Statement> statement_ptr;
//typedef  std::shared_ptr<sql::ResultSet> resultset_ptr;

//void show_statment_meta(statement_ptr stmtptr)
//{
//    //cout << "MaxFieldSize: " << stmtptr->getMaxFieldSize() << endl;
//    //cout << "MaxRows: " << stmtptr->getMaxRows() << endl;
//    //cout << "FetchSize: " << stmtptr->getFetchSize() << endl;
//}

//int main(int argc, char *argv[])
//{
//    QCoreApplication a(argc, argv);

//    sql::mysql::MySQL_Driver *driver = 0;
//    sql::Connection *conn_ = 0;

//    try
//    {
//        do
//        {
//            driver = sql::mysql::get_mysql_driver_instance();
//            conn_ = driver->connect("tcp://192.168.8.89:3306", "root", "1234qwer");
//            connection_ptr conn(conn_);
//            cout << "连接成功" << endl;

//            sql::Statement *stat_ = conn->createStatement();
//            statement_ptr stmtptr(stat_);
//            conn->setSchema("world");
//            bool b = stmtptr->execute("select * from city");
//            //bool b = stmtptr->execute("update city set Name='Hebron_guojianguang' where ID=4076");
//            if (b)
//            {
//                do
//                {
//                    auto result = stmtptr->getResultSet();
//                    resultset_ptr rsptr(result);
//                    cout << "Recive " << rsptr->rowsCount() << " rows." << endl;
//                    while (rsptr->next())
//                        cout << rsptr->getString(1) << "|" << rsptr->getString(2) << "|" << rsptr->getString(3) << endl;
//                } while (stmtptr->getMoreResults());
//            }
//            else
//            {
//                cout << "Update " << stmtptr->getUpdateCount() << " rows." << endl;
//            }
//        } while (0);
//    }
//    catch (sql::SQLException &e)
//    {
//        cout << "ERROR: " << e.what();
//        cout << " (MySQL error code: " << e.getErrorCode();
//        cout << ", SQLState: " << e.getSQLState() << ")" << endl;

//        if (e.getErrorCode() == 1047)
//        {
//            /*
//            Error: 1047 SQLSTATE: 08S01 (ER_UNKNOWN_COM_ERROR)
//            Message: Unknown command
//            */
//            cout << "/nYour server does not seem to support Prepared Statements at all. ";
//            cout << "Perhaps MYSQL < 4.1?" << endl;
//        }
//    }
//    catch (...)
//    {
//        cout << "连接失败" << endl;
//    }

//    return 0;
//}
