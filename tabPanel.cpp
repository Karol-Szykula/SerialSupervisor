#include "tabPanel.h"

//(*InternalHeaders(TabPanel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(TabPanel)
const long TabPanel::ID_STATICTEXT1 = wxNewId();
const long TabPanel::ID_TEXTCTRL1 = wxNewId();
const long TabPanel::ID_BUTTON1 = wxNewId();
const long TabPanel::ID_TEXTCTRL2 = wxNewId();
const long TabPanel::ID_PANEL1 = wxNewId();
const long TabPanel::ID_NOTEBOOK1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(TabPanel,wxPanel)
	//(*EventTable(TabPanel)
	//*)
END_EVENT_TABLE()

TabPanel::TabPanel(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size,
         long style, const wxString& name)
{
    m_parent = parent;

	//(*Initialize(TabPanel)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxSize(304,201), 0, _T("ID_NOTEBOOK1"));
	Panel1 = new wxPanel(Notebook1, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	FlexGridSizer1 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer1->AddGrowableCol(1);
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Send:"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT1"));
	FlexGridSizer1->Add(StaticText1, 1, wxALL|wxEXPAND, 5);
	sendTextWidget = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	FlexGridSizer1->Add(sendTextWidget, 1, wxALL|wxEXPAND, 5);
	Button1 = new wxButton(Panel1, ID_BUTTON1, _("Clear"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer1->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(FlexGridSizer1, 0, wxALL|wxEXPAND, 5);
	terminalTextWidget = new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	BoxSizer2->Add(terminalTextWidget, 1, wxALL|wxEXPAND, 5);
	Panel1->SetSizer(BoxSizer2);
	BoxSizer2->Fit(Panel1);
	BoxSizer2->SetSizeHints(Panel1);
	Notebook1->AddPage(Panel1, _("Terminal"), false);
	BoxSizer1->Add(Notebook1, 1, wxALL|wxEXPAND, 0);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	//*)
}

TabPanel::~TabPanel()
{
	//(*Destroy(TabPanel)
	//*)
}

void TabPanel::appendTextToTerminal(std::string inText)
{
    //! \todo appendTextToTerminal function needs a switch to add new line character to the terminal window
    terminalTextWidget->AppendText(inText);
}

std::string TabPanel::getTextFromSendWidget()
{
    wxString text = sendTextWidget->GetValue();

    sendTextWidget->Clear();

    return text.ToStdString();
}



