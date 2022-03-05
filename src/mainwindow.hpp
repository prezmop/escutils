#ifndef MAINWINDOW_HPP_
#define MAINWINDOW_HPP_

#include "wxwin/window.h"
#include <iostream>

enum cryptoMode                         {  decr = 0,  encr = 1};
const std::string cryptoExtensions[2] = {"_decr"   ,"_encr"   };

class MainWindow : public MainWindowBase
{
public:
	MainWindow( wxWindow* parent ) : MainWindowBase( parent ) {}
protected:
	void cryptoModeSelected( wxCommandEvent& ) override;
	void cryptoFilePicked( wxFileDirPickerEvent& ) override;
	void cryptoSave( wxCommandEvent& ) override;
	void mainWinClose( wxCloseEvent& ) override;
private:
	cryptoMode currentMode = cryptoMode::decr;
};

#endif
