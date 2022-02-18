#ifndef CMYSQLWRAPPER_H
#define CMYSQLWRAPPER_H

#include <mysql/jdbc.h>
#include <string>
#include <iostream>
#include <mutex>
#include <list>
#include <thread>

typedef struct _conn_info
{
    std::string m_ip;
    int m_port{3306};
    std::string m_dbname;
    std::string m_usrname;
    std::string m_passwd;
    //MYSQL *m_psql{nullptr};

}CONN_INFO;

class CMySQLWrapper
{
public:
    CMySQLWrapper();
    ~CMySQLWrapper();
    int Init();
    int Connect();
    int Execute(const std::string& sql);
    int Execute(const std::string& sql, const std::list<std::string>& record);
    void Release();
    std::string GetMySQLError();
    CONN_INFO* GetConnInfo();
private:
    CONN_INFO m_connInfo;
    std::mutex m_lock;
};
typedef std::shared_ptr<CMySQLWrapper> mysql_ptr;
#endif // CMYSQLWRAPPER_H
