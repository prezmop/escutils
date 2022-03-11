#include "mainwindow.hpp"

#include "cryptopanel.hpp"

MainWindow::MainWindow() : MainWindowBase( nullptr ) {
	crypto = new CryptoPanel(mainNotebook);
	mainNotebook->AddPage(crypto,"decrypt/encrypt");
}

void MainWindow::winClose( wxCloseEvent& ) {
	//calling this->Close() causes a segfault
	this->Destroy();
}
