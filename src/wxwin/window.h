///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/gdicmn.h>
#include <wx/notebook.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/dialog.h>
#include <wx/stattext.h>
#include <wx/filepicker.h>
#include <wx/radiobox.h>
#include <wx/checkbox.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/panel.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MainWindowBase
///////////////////////////////////////////////////////////////////////////////
class MainWindowBase : public wxDialog
{
	private:

	protected:
		wxNotebook* mainNotebook;

		// Virtual event handlers, override them in your derived class
		virtual void winClose( wxCloseEvent& event ) { event.Skip(); }


	public:

		MainWindowBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("escapists utilities"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,-1 ), long style = wxDEFAULT_DIALOG_STYLE );

		~MainWindowBase();

};

///////////////////////////////////////////////////////////////////////////////
/// Class CryptoPanelBase
///////////////////////////////////////////////////////////////////////////////
class CryptoPanelBase : public wxPanel
{
	private:

	protected:
		wxStaticText* m_staticText1;
		wxFilePickerCtrl* cryptoFileInput;
		wxRadioBox* cryptoModeSelector;
		wxCheckBox* cryptoPadCheckbox;
		wxButton* cryptoAction;

		// Virtual event handlers, override them in your derived class
		virtual void filePicked( wxFileDirPickerEvent& event ) { event.Skip(); }
		virtual void modeSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void nullbtesToggled( wxCommandEvent& event ) { event.Skip(); }
		virtual void save( wxCommandEvent& event ) { event.Skip(); }


	public:

		CryptoPanelBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,170 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

		~CryptoPanelBase();

};

