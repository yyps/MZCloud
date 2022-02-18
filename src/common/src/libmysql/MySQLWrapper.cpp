#include <mysql/MySQLWrapper.h>
#include <assert.h>
#include <iostream>

CMySQLWrapper::CMySQLWrapper()
{
}

CMySQLWrapper::~CMySQLWrapper()
{
}

int CMySQLWrapper::Init()
{
    int err = ER_OK;
    do
    {
        std::unique_lock<std::mutex> locl(m_lock);

        if (m_connInfo.m_psql)
            break;

        m_connInfo.m_psql = mysql_init(nullptr);
        if (!m_connInfo.m_psql)
        {
            err = ER_INIT;
            break;
        }
    } while (0);

    return err;
}

int CMySQLWrapper::Connect()
{
    int err = ER_OK;
    do
    {
        assert(m_connInfo.m_psql);

        if (!mysql_real_connect(m_connInfo.m_psql,
                                m_connInfo.m_ip.c_str(),
                                m_connInfo.m_usrname.c_str(),
                                m_connInfo.m_passwd.c_str(),
                                m_connInfo.m_dbname.c_str(),
                                m_connInfo.m_port, nullptr, 0))
        {
            err = mysql_errno(m_connInfo.m_psql);
            //err = ER_CONNECT;
            break;
        }

    } while (0);
    return err;
}

int CMySQLWrapper::Execute(const std::string &sql)
{
    int err = ER_OK;
    do
    {
        assert(m_connInfo.m_psql);

        err = mysql_query(m_connInfo.m_psql, sql.c_str());

    } while (0);

    return err;
}

int CMySQLWrapper::Execute(const std::string &sql, const std::list<std::string> &record)
{
    int err = ER_OK;
    do
    {
        assert(m_connInfo.m_psql);
        auto psql = m_connInfo.m_psql;

        err = Execute(sql.c_str());
        if (err)
            break;

        do
        {
            auto result = mysql_store_result(psql);
            if (result)
            {
                // handle result!!!
                MYSQL_ROW row;
                int num_fields = mysql_num_fields(result);
                while ((row = mysql_fetch_row(result)))
                {
                    for(int i = 0; i < num_fields; i++)
                        printf("%s ", row[i] ? row[i] : "NULL");
                    printf("\n");
                }

                mysql_free_result(result);
            }
            else
            {
                if (mysql_field_count(psql) == 0)
                {
                    // no result
                }
                else
                {
                    // some error occurred
                    err = mysql_errno(psql);
                    break;
                }
            }

        } while (mysql_next_result(psql) == 0);

        if (err)
            break;

    } while (0);

    return err;
}

void CMySQLWrapper::Release()
{
    std::unique_lock<std::mutex> locl(m_lock);
    if (m_connInfo.m_psql)
        mysql_close(m_connInfo.m_psql);
}

std::string CMySQLWrapper::GetMySQLError()
{
    return mysql_error(m_connInfo.m_psql);
    //return mysql_stat(m_connInfo.m_psql);
}

CONN_INFO *CMySQLWrapper::GetConnInfo()
{
    return &m_connInfo;
}
