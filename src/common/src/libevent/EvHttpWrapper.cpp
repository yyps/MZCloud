#include "libevent/EvHttpWrapper.h"
#include <assert.h>
#include <libevent/evhttp.h>
#include <iostream>
#include <fstream>

CEvHttpServer::CEvHttpServer()
{
    m_evbase = event_base_new();
    assert(m_evbase!=nullptr);
    m_evhttp = evhttp_new(m_evbase);
    assert(m_evhttp!=nullptr);
}

CEvHttpServer::~CEvHttpServer()
{
    if (m_evbase)
        event_base_free(m_evbase);
    if (m_evhttp)
        evhttp_free(m_evhttp);
}

void CEvHttpServer::SetEventCB(event_cb_t cb)
{
    m_cb = cb;
    evhttp_set_cb(m_evhttp, "/", handle_callback, nullptr);
}

int CEvHttpServer::EventLoopDispatch(const int& port)
{
    int err = 0;

    assert(m_evbase);
    assert(m_evhttp);

    int e = evhttp_bind_socket(m_evhttp, "0.0.0.0", (uint16_t)port);
    assert(e==0);

    event_base_dispatch(m_evbase);

    return err;
}

void CEvHttpServer::handle_callback(evhttp_request *req, void *arg)
{
    const char *cmdtype;
    struct evkeyvalq *headers;
    struct evkeyval *header;
    struct evbuffer *buf;

    switch (evhttp_request_get_command(req)) {
    case EVHTTP_REQ_GET: cmdtype = "GET"; break;
    case EVHTTP_REQ_POST: cmdtype = "POST"; break;
    case EVHTTP_REQ_HEAD: cmdtype = "HEAD"; break;
    case EVHTTP_REQ_PUT: cmdtype = "PUT"; break;
    case EVHTTP_REQ_DELETE: cmdtype = "DELETE"; break;
    case EVHTTP_REQ_OPTIONS: cmdtype = "OPTIONS"; break;
    case EVHTTP_REQ_TRACE: cmdtype = "TRACE"; break;
    case EVHTTP_REQ_CONNECT: cmdtype = "CONNECT"; break;
    case EVHTTP_REQ_PATCH: cmdtype = "PATCH"; break;
    default: cmdtype = "unknown"; break;
    }

    std::cout << "Received a " << cmdtype << " request for " << evhttp_request_get_uri(req) << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "Header: " << std::endl;
    headers = evhttp_request_get_input_headers(req);
    for (header = headers->tqh_first; header; header = header->next.tqe_next)
        std::cout << header->key  << "-" << header->value << std::endl;

    std::string content;
    buf = evhttp_request_get_input_buffer(req);
    while (evbuffer_get_length(buf))
    {
        int n;
        char cbuf[128];
        n = evbuffer_remove(buf, cbuf, sizeof(cbuf));
        if (n > 0)
        {
            content += std::string(cbuf);
        }
    }
    std::cout << "Content: " << content << std::endl;

    // add output response
    struct evkeyvalq *rspheaders = evhttp_request_get_output_headers(req);
    assert(rspheaders);
    evhttp_add_header(rspheaders, "Content-Type", "text/html");
    struct evbuffer *rspbuf = evhttp_request_get_output_buffer(req);
    assert(rspbuf);

    int fd = -1;
    do
    {
        std::ifstream ifs;
        ifs.open("../../res/index.html", std::ios::binary|std::ios::in);
        if (!ifs.is_open())
            break;

        /* read fd */
        auto rdfd = [](std::filebuf& fb)->int{
            class _filebuf : public std::filebuf{
            public:
                int rdfd(){
                    return _M_file.fd();
                }
            };
            return static_cast<_filebuf&>(fb).rdfd();
        };

        fd = rdfd(*(ifs.rdbuf()));
        ifs.seekg(0, ifs.end);
        long size = ifs.tellg();
        evbuffer_add_file(rspbuf, fd, 0, size);

    } while (0);

   // evbuffer_add(rspbuf, demo.c_str(), demo.length());

    evhttp_send_reply(req, 200, "OK", NULL);
}
