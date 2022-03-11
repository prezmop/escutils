#include "cryptopanel.hpp"

#include <fstream>
#include <wx/filedlg.h>

#include "crypto/cryptography.hpp"

void CryptoPanel::modeSelected( wxCommandEvent& ){
	currentMode = static_cast<cryptoMode>(cryptoModeSelector->GetSelection());
	cryptoPadCheckbox->Show(currentMode == decr);
}

void CryptoPanel::filePicked( wxFileDirPickerEvent& ){

}

void CryptoPanel::save( wxCommandEvent& ) {

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
			decrypt(ifile,ofile,cryptoPadCheckbox->GetValue());
			break;
		case encr:
			encrypt(ifile,ofile);
			break;
		}
	}
}

