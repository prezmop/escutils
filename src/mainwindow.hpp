#ifndef MAINWINDOW_HPP_
#define MAINWINDOW_HPP_

#include "wxwin/window.h"
#include "cryptopanel.hpp"

class MainWindow : public MainWindowBase {
public:
	MainWindow();
protected:
	void winClose( wxCloseEvent& ) override;
	CryptoPanel* crypto;
};

#endif
