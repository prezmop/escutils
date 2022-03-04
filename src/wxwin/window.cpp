///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "window.h"

///////////////////////////////////////////////////////////////////////////

MainWindowBase::MainWindowBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 500,230 ), wxDefaultSize );

	wxBoxSizer* mainSizer;
	mainSizer = new wxBoxSizer( wxVERTICAL );

	mainNotebook = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	crypto = new wxPanel( mainNotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	m_staticText1 = new wxStaticText( crypto, wxID_ANY, wxT("input:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer6->Add( m_staticText1, 0, wxALL, 5 );

	cryptoFileInput = new wxFilePickerCtrl( crypto, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("*.*"), wxDefaultPosition, wxSize( -1,-1 ), wxFLP_FILE_MUST_EXIST|wxFLP_OPEN|wxFLP_USE_TEXTCTRL );
	bSizer6->Add( cryptoFileInput, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );

	wxString cryptoModeSelectorChoices[] = { wxT("decrypt"), wxT("encrypt") };
	int cryptoModeSelectorNChoices = sizeof( cryptoModeSelectorChoices ) / sizeof( wxString );
	cryptoModeSelector = new wxRadioBox( crypto, wxID_ANY, wxT("mode"), wxDefaultPosition, wxDefaultSize, cryptoModeSelectorNChoices, cryptoModeSelectorChoices, 1, wxRA_SPECIFY_COLS );
	cryptoModeSelector->SetSelection( 0 );
	cryptoModeSelector->SetMinSize( wxSize( 150,90 ) );

	bSizer3->Add( cryptoModeSelector, 0, wxALL, 5 );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	cryptoAction = new wxButton( crypto, wxID_ANY, wxT("save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( cryptoAction, 0, wxALIGN_RIGHT|wxALL, 5 );


	bSizer3->Add( bSizer5, 1, wxALIGN_BOTTOM, 5 );


	bSizer6->Add( bSizer3, 0, wxEXPAND, 5 );


	crypto->SetSizer( bSizer6 );
	crypto->Layout();
	bSizer6->Fit( crypto );
	mainNotebook->AddPage( crypto, wxT("encrypt/decrypt"), false );

	mainSizer->Add( mainNotebook, 1, wxEXPAND, 5 );


	this->SetSizer( mainSizer );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	cryptoFileInput->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( MainWindowBase::cryptoFilePicked ), NULL, this );
	cryptoModeSelector->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( MainWindowBase::cryptoModeSelected ), NULL, this );
	cryptoAction->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowBase::cryptoSave ), NULL, this );
}

MainWindowBase::~MainWindowBase()
{
	// Disconnect Events
	cryptoFileInput->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( MainWindowBase::cryptoFilePicked ), NULL, this );
	cryptoModeSelector->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( MainWindowBase::cryptoModeSelected ), NULL, this );
	cryptoAction->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowBase::cryptoSave ), NULL, this );

}
