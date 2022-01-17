#include "MainApp.h"
#include "ServerErrdef.h"

CMainApp::CMainApp()
{
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
