#include "MainApp.h"
#include "ServerErrdef.h"

CMainApp::CMainApp()
{
    m_httpSvr = std::make_shared<CEvHttpServer>(7111);
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
    int err = m_httpSvr->EventLoopDispatch();

    return err;
}

int CMainApp::Quit()
{
    return ERR_SUCCESS;
}
