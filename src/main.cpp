#include <iostream>
#include <fstream>
#include <cryptopp/hex.h>
#include <sstream>
#include <wx/wx.h>
//#include <filesystem>

#include "cryptography.hpp"
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


//namespace fs = std::filesystem;
/*
int main (){


	fs::path ipath("abc/encrypted.gif");
	fs::path opath;
	opath  = ipath.parent_path();
	opath /= ipath.stem();
	opath += "_decr";
	opath += ipath.extension();

	std::cout << opath.string();

	std::ifstream input (ipath.native(), std::fstream::binary|std::fstream::in );
	//std::stringstream buf;
	std::ofstream output(opath.native(), std::fstream::binary|std::fstream::out);

	if (input.good()){
		decrypt(input,output);
	}
}*/
