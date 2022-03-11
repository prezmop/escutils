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
	MainWindow* frame = new MainWindow();
    frame->Show(true);
    return true;
}
