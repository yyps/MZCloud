#ifndef CMAINAPP_H
#define CMAINAPP_H

#include <libevent/EvHttpWrapper.h>

class CMainApp
{
public:
    CMainApp();
    ~CMainApp();

    int Init();
    int Run();
    int Quit();
    void http_handle_callback();

private:
    evhttp_ptr m_httpSvr{nullptr};

};

#endif // CMAINAPP_H
