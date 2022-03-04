#include "mainwindow.hpp"

#include <fstream>
#include <wx/filedlg.h>

#include "cryptography.hpp"

void MainWindow::cryptoModeSelected( wxCommandEvent& ){
	currentMode = static_cast<cryptoMode>(cryptoModeSelector->GetSelection());
	//updateSaveName();
}

void MainWindow::cryptoFilePicked( wxFileDirPickerEvent& ){
	//updateSaveName();
}

/*void MainWindow::cryptoFileSaved( wxFileDirPickerEvent& event ){

	std::ifstream ifile( cryptoFileInput->GetPath(), std::fstream::binary|std::fstream::in );
	std::ofstream ofile( event.GetPath(), std::fstream::binary|std::fstream::out );

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

void MainWindow::updateSaveName(){
	auto file = cryptoFileInput->GetFileName();
	file.SetName(file.GetName() + cryptoExtensions[currentMode]);
	cryptoFileOutput->SetFileName(file);
}*/

void MainWindow::cryptoSave( wxCommandEvent& ) {

	wxFileName file(cryptoFileInput->GetPath());
	file.SetName(file.GetName() + cryptoExtensions[currentMode]);

	wxFileDialog dialog( this, "select save location", "", "", wxFileSelectorDefaultWildcardStr, wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
	dialog.SetPath(file.GetFullPath());

	if (dialog.ShowModal() == wxID_CANCEL){
		return;
	}

	std::ifstream ifile( cryptoFileInput->GetPath(), std::fstream::binary|std::fstream::in );
	std::ofstream ofile( dialog.GetPath(), std::fstream::binary|std::fstream::out );

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
