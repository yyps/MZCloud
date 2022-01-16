#include "libevent/EvHttpWrapper.h"
#include <assert.h>
#include <libevent/evhttp.h>

CEvHttpServer::CEvHttpServer(const int& port)
{
    m_evbase = event_base_new();
    assert(m_evbase!=nullptr);
    m_evhttp = evhttp_new(m_evbase);
    assert(m_evhttp!=nullptr);
    evhttp_bind_socket(m_evhttp, "0.0.0.0", (uint16_t)port);
}

CEvHttpServer::~CEvHttpServer()
{
    if (m_evbase)
    {
        event_base_free(m_evbase);
        m_evbase = nullptr;
    }
}

void CEvHttpServer::SetEventCB(event_cb_t cb)
{
    m_cb = cb;
    evhttp_set_cb(m_evhttp, "/test", cb, nullptr);
}

int CEvHttpServer::EventLoopDispatch()
{
    int err = 0;

    assert(m_evbase);
    assert(m_evhttp);

    event_base_dispatch(m_evbase);

    return err;
}
