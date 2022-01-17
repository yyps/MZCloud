#ifndef EVHTTPWRAPPER_H
#define EVHTTPWRAPPER_H

#include <event2/event.h>
#include <evhttp.h>
#include <thread>

typedef void (*event_cb_t)(struct evhttp_request *, void *);

class CEvHttpServer
{
public:
    CEvHttpServer();
    ~CEvHttpServer();

    void SetEventCB(event_cb_t cb);
    int EventLoopDispatch(const int& port);
    static void handle_callback(struct evhttp_request *htpreq, void *usrdata);

private:
    event_base *m_evbase{nullptr};
    evhttp *m_evhttp{nullptr};
    event_cb_t m_cb{nullptr};
};
typedef std::shared_ptr<CEvHttpServer> evhttp_ptr;

#endif // EVHTTPWRAPPER_H
