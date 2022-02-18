QT -= gui
QT += sql

CONFIG += c++11 console
CONFIG -= app_bundle

CONFIG(debug,debug|release){
    DESTDIR = $$PWD/../../../bin/debug
    DEFINES += DEBUG_MODE
}
else {
    DESTDIR = $$PWD/../../../bin/release
}

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += ../../common/include\
        ../../common/include/libevent \
        ../../common/include/libmysql

SOURCES += \
        ../../common/src/libmysql/MySQLWrapper.cpp \
        ../../common/src/libevent/EvHttpWrapper.cpp \
        MainApp.cpp \
        main.cpp

HEADERS += \
    ../../common/include/libevent/EvHttpWrapper.h \
    ../../common/include/libevent/evdns.h \
    ../../common/include/libevent/event.h \
    ../../common/include/libevent/event2/buffer.h \
    ../../common/include/libevent/event2/buffer_compat.h \
    ../../common/include/libevent/event2/bufferevent.h \
    ../../common/include/libevent/event2/bufferevent_compat.h \
    ../../common/include/libevent/event2/bufferevent_ssl.h \
    ../../common/include/libevent/event2/bufferevent_struct.h \
    ../../common/include/libevent/event2/dns.h \
    ../../common/include/libevent/event2/dns_compat.h \
    ../../common/include/libevent/event2/dns_struct.h \
    ../../common/include/libevent/event2/event-config.h \
    ../../common/include/libevent/event2/event.h \
    ../../common/include/libevent/event2/event_compat.h \
    ../../common/include/libevent/event2/event_struct.h \
    ../../common/include/libevent/event2/http.h \
    ../../common/include/libevent/event2/http_compat.h \
    ../../common/include/libevent/event2/http_struct.h \
    ../../common/include/libevent/event2/keyvalq_struct.h \
    ../../common/include/libevent/event2/listener.h \
    ../../common/include/libevent/event2/rpc.h \
    ../../common/include/libevent/event2/rpc_compat.h \
    ../../common/include/libevent/event2/rpc_struct.h \
    ../../common/include/libevent/event2/tag.h \
    ../../common/include/libevent/event2/tag_compat.h \
    ../../common/include/libevent/event2/thread.h \
    ../../common/include/libevent/event2/util.h \
    ../../common/include/libevent/event2/visibility.h \
    ../../common/include/libevent/event2/watch.h \
    ../../common/include/libevent/evhttp.h \
    ../../common/include/libevent/evrpc.h \
    ../../common/include/libevent/evutil.h \
    ../../common/include/libmysql/MySQLWrapper.h \
    ../../common/include/libmysql/big_endian.h \
    ../../common/include/libmysql/binary_log_types.h \
    ../../common/include/libmysql/byte_order_generic.h \
    ../../common/include/libmysql/byte_order_generic_x86.h \
    ../../common/include/libmysql/decimal.h \
    ../../common/include/libmysql/errmsg.h \
    ../../common/include/libmysql/jdbc/cppconn/build_config.h \
    ../../common/include/libmysql/jdbc/cppconn/config.h \
    ../../common/include/libmysql/jdbc/cppconn/connection.h \
    ../../common/include/libmysql/jdbc/cppconn/datatype.h \
    ../../common/include/libmysql/jdbc/cppconn/driver.h \
    ../../common/include/libmysql/jdbc/cppconn/exception.h \
    ../../common/include/libmysql/jdbc/cppconn/metadata.h \
    ../../common/include/libmysql/jdbc/cppconn/parameter_metadata.h \
    ../../common/include/libmysql/jdbc/cppconn/prepared_statement.h \
    ../../common/include/libmysql/jdbc/cppconn/resultset.h \
    ../../common/include/libmysql/jdbc/cppconn/resultset_metadata.h \
    ../../common/include/libmysql/jdbc/cppconn/sqlstring.h \
    ../../common/include/libmysql/jdbc/cppconn/statement.h \
    ../../common/include/libmysql/jdbc/cppconn/variant.h \
    ../../common/include/libmysql/jdbc/cppconn/version_info.h \
    ../../common/include/libmysql/jdbc/cppconn/warning.h \
    ../../common/include/libmysql/jdbc/mysql_connection.h \
    ../../common/include/libmysql/jdbc/mysql_driver.h \
    ../../common/include/libmysql/jdbc/mysql_error.h \
    ../../common/include/libmysql/keycache.h \
    ../../common/include/libmysql/little_endian.h \
    ../../common/include/libmysql/m_ctype.h \
    ../../common/include/libmysql/m_string.h \
    ../../common/include/libmysql/my_alloc.h \
    ../../common/include/libmysql/my_byteorder.h \
    ../../common/include/libmysql/my_command.h \
    ../../common/include/libmysql/my_compiler.h \
    ../../common/include/libmysql/my_config.h \
    ../../common/include/libmysql/my_dbug.h \
    ../../common/include/libmysql/my_dir.h \
    ../../common/include/libmysql/my_getopt.h \
    ../../common/include/libmysql/my_global.h \
    ../../common/include/libmysql/my_list.h \
    ../../common/include/libmysql/my_sys.h \
    ../../common/include/libmysql/my_thread.h \
    ../../common/include/libmysql/my_thread_local.h \
    ../../common/include/libmysql/my_xml.h \
    ../../common/include/libmysql/mysql.h \
    ../../common/include/libmysql/mysql/MySQLWrapper.h \
    ../../common/include/libmysql/mysql/client_authentication.h \
    ../../common/include/libmysql/mysql/client_plugin.h \
    ../../common/include/libmysql/mysql/client_plugin.h.pp \
    ../../common/include/libmysql/mysql/get_password.h \
    ../../common/include/libmysql/mysql/jdbc.h \
    ../../common/include/libmysql/mysql/mysql_lex_string.h \
    ../../common/include/libmysql/mysql/plugin_auth_common.h \
    ../../common/include/libmysql/mysql/plugin_trace.h \
    ../../common/include/libmysql/mysql/psi/mysql_file.h \
    ../../common/include/libmysql/mysql/psi/mysql_idle.h \
    ../../common/include/libmysql/mysql/psi/mysql_mdl.h \
    ../../common/include/libmysql/mysql/psi/mysql_memory.h \
    ../../common/include/libmysql/mysql/psi/mysql_ps.h \
    ../../common/include/libmysql/mysql/psi/mysql_socket.h \
    ../../common/include/libmysql/mysql/psi/mysql_sp.h \
    ../../common/include/libmysql/mysql/psi/mysql_stage.h \
    ../../common/include/libmysql/mysql/psi/mysql_statement.h \
    ../../common/include/libmysql/mysql/psi/mysql_table.h \
    ../../common/include/libmysql/mysql/psi/mysql_thread.h \
    ../../common/include/libmysql/mysql/psi/mysql_transaction.h \
    ../../common/include/libmysql/mysql/psi/psi.h \
    ../../common/include/libmysql/mysql/psi/psi_base.h \
    ../../common/include/libmysql/mysql/psi/psi_memory.h \
    ../../common/include/libmysql/mysql/service_my_snprintf.h \
    ../../common/include/libmysql/mysql/service_mysql_alloc.h \
    ../../common/include/libmysql/mysql_com.h \
    ../../common/include/libmysql/mysql_com_server.h \
    ../../common/include/libmysql/mysql_embed.h \
    ../../common/include/libmysql/mysql_time.h \
    ../../common/include/libmysql/mysql_version.h \
    ../../common/include/libmysql/mysqld_ername.h \
    ../../common/include/libmysql/mysqld_error.h \
    ../../common/include/libmysql/mysqlx/common.h \
    ../../common/include/libmysql/mysqlx/common/api.h \
    ../../common/include/libmysql/mysqlx/common/error.h \
    ../../common/include/libmysql/mysqlx/common/op_if.h \
    ../../common/include/libmysql/mysqlx/common/settings.h \
    ../../common/include/libmysql/mysqlx/common/util.h \
    ../../common/include/libmysql/mysqlx/common/value.h \
    ../../common/include/libmysql/mysqlx/common_constants.h \
    ../../common/include/libmysql/mysqlx/devapi/collations.h \
    ../../common/include/libmysql/mysqlx/devapi/collection_crud.h \
    ../../common/include/libmysql/mysqlx/devapi/common.h \
    ../../common/include/libmysql/mysqlx/devapi/crud.h \
    ../../common/include/libmysql/mysqlx/devapi/detail/crud.h \
    ../../common/include/libmysql/mysqlx/devapi/detail/error.h \
    ../../common/include/libmysql/mysqlx/devapi/detail/result.h \
    ../../common/include/libmysql/mysqlx/devapi/detail/row.h \
    ../../common/include/libmysql/mysqlx/devapi/detail/session.h \
    ../../common/include/libmysql/mysqlx/devapi/detail/settings.h \
    ../../common/include/libmysql/mysqlx/devapi/document.h \
    ../../common/include/libmysql/mysqlx/devapi/error.h \
    ../../common/include/libmysql/mysqlx/devapi/executable.h \
    ../../common/include/libmysql/mysqlx/devapi/mysql_charsets.h \
    ../../common/include/libmysql/mysqlx/devapi/mysql_collations.h \
    ../../common/include/libmysql/mysqlx/devapi/result.h \
    ../../common/include/libmysql/mysqlx/devapi/row.h \
    ../../common/include/libmysql/mysqlx/devapi/settings.h \
    ../../common/include/libmysql/mysqlx/devapi/table_crud.h \
    ../../common/include/libmysql/mysqlx/xapi.h \
    ../../common/include/libmysql/mysqlx/xdevapi.h \
    ../../common/include/libmysql/sql_common.h \
    ../../common/include/libmysql/sql_state.h \
    ../../common/include/libmysql/sslopt-case.h \
    ../../common/include/libmysql/sslopt-longopts.h \
    ../../common/include/libmysql/sslopt-vars.h \
    ../../common/include/libmysql/thr_cond.h \
    ../../common/include/libmysql/thr_mutex.h \
    ../../common/include/libmysql/thr_rwlock.h \
    ../../common/include/libmysql/typelib.h \
    MainApp.h \
    ServerErrdef.h

unix:{
    # set run path
    QMAKE_LFLAGS += -Wl,-rpath=../libs
    QMAKE_LFLAGS += -Wl,-rpath=../../libs/linux/x64
    QMAKE_LFLAGS += -Wl,-rpath=/usr/local/lib

    LIBS += -L../../../libs/linux/x64 -levent
    LIBS += -L../../../libs/linux/x64 -lmysqlclient
}

win32:{
    LIBS += -L$$PWD/../../../../libs/windows/x64/libevent -levent
    LIBS += -lWs2_32
}
