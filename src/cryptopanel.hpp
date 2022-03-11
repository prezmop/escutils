#ifndef CRYPTOPANEL_HPP_
#define CRYPTOPANEL_HPP_

#include "wxwin/window.h"
#include <string>

enum cryptoMode                         {  decr = 0,  encr = 1};
const std::string cryptoExtensions[2] = {"_decr"   ,"_encr"   };

class CryptoPanel : public CryptoPanelBase
{
public:
	CryptoPanel( wxWindow* parent ) : CryptoPanelBase( parent ) {}
protected:
	void modeSelected( wxCommandEvent& ) override;
	void filePicked( wxFileDirPickerEvent& ) override;
	void save( wxCommandEvent& ) override;
private:
	cryptoMode currentMode = cryptoMode::decr;
};

#endif
