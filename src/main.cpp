#include <iostream>
#include <fstream>
#include <cryptopp/hex.h>
#include <sstream>
#include <wx/wx.h>

#include "crypto/cryptography.hpp"
#include "mainwindow.hpp"

class MyApp : public wxApp
{
  public:
    virtual bool OnInit();
};

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit(){
	MainWindow *frame = new MainWindow(nullptr);
    frame->Show(true);
    return true;
}
