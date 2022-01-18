#include "MainApp.h"
#include "ServerErrdef.h"

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
}

CMainApp::~CMainApp()
{

}

int CMainApp::Init()
{

    return ERR_SUCCESS;
}

int CMainApp::Run()
{
    m_httpSvr->SetEventCB(nullptr);
    int err = m_httpSvr->EventLoopDispatch(7111);

    return err;
}

int CMainApp::Quit()
{
    return ERR_SUCCESS;
}
