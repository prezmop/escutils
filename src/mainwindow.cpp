#include "mainwindow.hpp"

#include <fstream>
#include <wx/filedlg.h>

#include "cryptography.hpp"

void MainWindow::cryptoModeSelected( wxCommandEvent& ){
	currentMode = static_cast<cryptoMode>(cryptoModeSelector->GetSelection());
}

void MainWindow::cryptoFilePicked( wxFileDirPickerEvent& ){

}

void MainWindow::cryptoSave( wxCommandEvent& ) {

	wxFileName file(cryptoFileInput->GetPath());
	file.SetName(file.GetName() + cryptoExtensions[currentMode]);

	wxFileDialog dialog( this, "select save location", "", "", wxFileSelectorDefaultWildcardStr, wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
	dialog.SetPath(file.GetFullPath());

	if (dialog.ShowModal() == wxID_CANCEL){
		return;
	}

	std::ifstream ifile( static_cast<std::string>(cryptoFileInput->GetPath()), std::fstream::binary|std::fstream::in );
	std::ofstream ofile( static_cast<std::string>(dialog.GetPath()), std::fstream::binary|std::fstream::out );

	if (ifile.good()){
		switch(currentMode){
		case decr:
			decrypt(ifile,ofile);
			break;
		case encr:
			encrypt(ifile,ofile);
			break;
		}
	}
}

void MainWindow::mainWinClose( wxCloseEvent& ) {
	//calling this->Close() causes a segfault
	this->Destroy();
}
