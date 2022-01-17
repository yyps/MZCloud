QT -= gui

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
        ../../common/include/libevent

SOURCES += \
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
    MainApp.h \
    ServerErrdef.h


unix:{
    LIBS += -L/usr/local/lib -levent
}
