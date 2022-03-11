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
	this->SetSizeHints( wxSize( 500,-1 ), wxDefaultSize );

	wxBoxSizer* mainSizer;
	mainSizer = new wxBoxSizer( wxVERTICAL );

	mainNotebook = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	mainSizer->Add( mainNotebook, 1, wxEXPAND, 5 );


	this->SetSizer( mainSizer );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainWindowBase::winClose ) );
}

MainWindowBase::~MainWindowBase()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainWindowBase::winClose ) );

}

CryptoPanelBase::CryptoPanelBase( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	this->SetMinSize( wxSize( 500,170 ) );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("input:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer6->Add( m_staticText1, 0, wxALL, 5 );

	cryptoFileInput = new wxFilePickerCtrl( this, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("*"), wxDefaultPosition, wxSize( -1,-1 ), wxFLP_FILE_MUST_EXIST|wxFLP_OPEN|wxFLP_USE_TEXTCTRL );
	bSizer6->Add( cryptoFileInput, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );

	wxString cryptoModeSelectorChoices[] = { wxT("decrypt"), wxT("encrypt") };
	int cryptoModeSelectorNChoices = sizeof( cryptoModeSelectorChoices ) / sizeof( wxString );
	cryptoModeSelector = new wxRadioBox( this, wxID_ANY, wxT("mode"), wxDefaultPosition, wxDefaultSize, cryptoModeSelectorNChoices, cryptoModeSelectorChoices, 1, wxRA_SPECIFY_COLS );
	cryptoModeSelector->SetSelection( 0 );
	cryptoModeSelector->SetMinSize( wxSize( 150,-1 ) );

	bSizer3->Add( cryptoModeSelector, 0, wxALL, 5 );

	wxBoxSizer* bSizer51;
	bSizer51 = new wxBoxSizer( wxVERTICAL );

	cryptoPadCheckbox = new wxCheckBox( this, wxID_ANY, wxT("strip null bytes"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer51->Add( cryptoPadCheckbox, 0, wxALL, 5 );


	bSizer3->Add( bSizer51, 1, wxEXPAND|wxTOP|wxBOTTOM, 10 );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	cryptoAction = new wxButton( this, wxID_ANY, wxT("save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( cryptoAction, 0, wxALIGN_RIGHT|wxALL, 5 );


	bSizer3->Add( bSizer5, 1, wxALIGN_BOTTOM, 5 );


	bSizer6->Add( bSizer3, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer6 );
	this->Layout();

	// Connect Events
	cryptoFileInput->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( CryptoPanelBase::filePicked ), NULL, this );
	cryptoModeSelector->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( CryptoPanelBase::modeSelected ), NULL, this );
	cryptoPadCheckbox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CryptoPanelBase::nullbtesToggled ), NULL, this );
	cryptoAction->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CryptoPanelBase::save ), NULL, this );
}

CryptoPanelBase::~CryptoPanelBase()
{
	// Disconnect Events
	cryptoFileInput->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( CryptoPanelBase::filePicked ), NULL, this );
	cryptoModeSelector->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( CryptoPanelBase::modeSelected ), NULL, this );
	cryptoPadCheckbox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CryptoPanelBase::nullbtesToggled ), NULL, this );
	cryptoAction->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CryptoPanelBase::save ), NULL, this );

}
