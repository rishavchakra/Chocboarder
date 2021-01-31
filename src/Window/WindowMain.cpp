//
// Created on Jan 29, 2021.
//
#include "headers/cMain.h"

//Binds IDs to command functions
wxBEGIN_EVENT_TABLE(cMain, wxFrame)
				EVT_MENU(ID::MenuFileNew, cMain::OnFileNew)
				EVT_MENU(ID::MenuFileOpen, cMain::OnFileOpen)
				EVT_MENU(ID::MenuFileSave, cMain::OnFileSave)
				EVT_MENU(ID::MenuFileExit, cMain::OnFileExit)
				
				EVT_MENU(ID::MenuEditUndo, cMain::OnEditUndo)
				EVT_MENU(ID::MenuEditRedo, cMain::OnEditRedo)
				EVT_MENU(ID::MenuEditPrefs, cMain::OnEditPrefs)
				
				EVT_MENU(ID::MenuToolBrush, cMain::OnToolBrush)
				EVT_MENU(ID::MenuToolEraser, cMain::OnToolEraser)
				EVT_MENU(ID::MenuToolShading, cMain::OnToolShading)
				EVT_MENU(ID::MenuToolFill, cMain::OnToolFill)
				
				EVT_MENU(ID::MenuHelpShortcuts, cMain::OnHelpShortcuts)
wxEND_EVENT_TABLE()

//TODO: Fix the start coordinate and the size
cMain::cMain() :
		wxFrame(nullptr, wxID_ANY, "ChocBoarder", wxPoint(30, 30), wxSize(800, 700))
{
	//	Initializes all the window components
	InitMenu(this);
	InitToolbar(this);
	InitMainPanel(this);
	InitTimelinePanel(this);
	
	SetSpacings();
}

cMain::~cMain()
{
}

//
//          Inline Window Initialization functions
//
//TODO: Add keyboard shortcuts to menu items
inline void cMain::InitMenu(wxFrame *_frame)
{
	m_menuBar = new wxMenuBar();
	_frame->SetMenuBar(m_menuBar);
	
	//Menu file options
	wxMenu *menuFile = new wxMenu();
	menuFile->Append(ID::MenuFileNew, "New");
	menuFile->Append(ID::MenuFileOpen, "Open");
	menuFile->Append(ID::MenuFileSave, "Save Project");
	menuFile->Append(ID::MenuFileExit, "Exit");
	m_menuBar->Append(menuFile, "File");
	
	wxMenu *menuEdit = new wxMenu();
	menuEdit->Append(ID::MenuEditUndo, "Undo");
	menuEdit->Append(ID::MenuEditRedo, "Redo");
	menuEdit->Append(ID::MenuEditPrefs, "Preferences");
	m_menuBar->Append(menuEdit, "Edit");
	
	wxMenu *menuView = new wxMenu();
	m_menuBar->Append(menuView, "View");
	
	wxMenu *menuTool = new wxMenu();
	menuTool->Append(ID::MenuToolBrush, "Brush");
	menuTool->Append(ID::MenuToolEraser, "Eraser");
	menuTool->Append(ID::MenuToolShading, "Shading");
	menuTool->Append(ID::MenuToolFill, "Fill");
	m_menuBar->Append(menuTool, "Tools");
	
	wxMenu *menuHelp = new wxMenu();
	menuHelp->Append(ID::MenuHelpShortcuts, "Keyboard Shortcuts");
	m_menuBar->Append(menuHelp, "Help");
}

inline void cMain::InitToolbar(wxFrame *_frame)
{
//	m_toolbarPanel = new wxPanel(_frame, ID::ToolbarPanel);
	
	//	m_toolbarPanelLeft = new wxPanel(_frame, ID::ToolbarPanelLeft, wxPoint(0, 0));
	m_toolbarPanel = new wxPanel(_frame, ID::ToolbarPanel);
	m_toolbarPanel->SetBackgroundColour(Colors::primary_fg);
	
	m_toolBar = new wxToolBar(m_toolbarPanel, ID::Toolbar, wxPoint(0, 0), wxSize(-1, -1));
	m_toolBar->SetBackgroundColour(Colors::primary_fg);
	
	m_toolBar->AddTool(ID::ToolButtonNew, "New", wxBitmap(wxSize(30, 30)));
	m_toolBar->AddTool(ID::ToolButtonNew, "Open", wxBitmap(wxSize(30, 30)));
	m_toolBar->AddTool(ID::ToolButtonNew, "Save", wxBitmap(wxSize(30, 30)));
	
	m_toolBar->AddSeparator();
	m_toolBar->AddStretchableSpace();
	
	m_toolBar->AddTool(ID::ToolButtonNew, "Undo", wxBitmap(wxSize(30, 30)));
	m_toolBar->AddTool(ID::ToolButtonNew, "Redo", wxBitmap(wxSize(30, 30)));
	m_toolBar->Realize();
	
}

inline void cMain::InitMainPanel(wxFrame *_frame)
{
	m_middlePanel = new wxPanel(_frame, ID::MiddlePanel);
	m_middlePanel->SetBackgroundColour(Colors::window_bg);

	m_canvasPanel = new wxPanel(m_middlePanel, ID::CanvasPanel);
	m_canvasPanel->SetBackgroundColour(Colors::canvas_bg);
	
	m_optionsPanel = new wxPanel(m_middlePanel, ID::OptionsPanel);
	m_optionsPanel->SetBackgroundColour(Colors::primary_bg);
	m_toolbarOpen = new wxButton(m_optionsPanel, wxID_ANY, "Options panel");
}

inline void cMain::InitTimelinePanel(wxFrame *_frame)
{
	m_timelinePanel = new wxPanel(_frame, ID::TimelinePanel);
	m_timelinePanel->SetBackgroundColour(Colors::primary_fg);
	m_toolbarSave = new wxButton(m_timelinePanel, wxID_ANY, "Timeline panel");
}

inline void cMain::SetSpacings()
{
	//	Flags: Proportion determines sizer major axis stretching
	//	wxEXPAND / wxFIXED_MINSIZE determine sizer minor axis stretching
	//	wxTOP, wxBOTTOM, wxLEFT, wxRIGHT, wxALL determine borders
	wxBoxSizer *SpacerMain = new wxBoxSizer(wxVERTICAL);
	SpacerMain->Add(m_toolbarPanel, 0, wxEXPAND);
	SpacerMain->Add(m_middlePanel, 1, wxEXPAND | wxTOP | wxBOTTOM, 2);
	SpacerMain->Add(m_timelinePanel, 0, wxEXPAND);
	this->SetSizer(SpacerMain);
	
	wxBoxSizer *SpacerMiddle = new wxBoxSizer(wxHORIZONTAL);
	SpacerMiddle->Add(m_canvasPanel, 1, wxEXPAND);
	SpacerMiddle->Add(m_optionsPanel, 0, wxEXPAND | wxLEFT, 2);
	m_middlePanel->SetSizer(SpacerMiddle);
}

//
//          Command event functions
//
void cMain::OnFileNew(wxCommandEvent &evt)
{
}

void cMain::OnFileOpen(wxCommandEvent &evt)
{
}

void cMain::OnFileSave(wxCommandEvent &evt)
{
}

void cMain::OnFileExit(wxCommandEvent &evt)
{
	Close();
	evt.Skip();
}

void cMain::OnEditUndo(wxCommandEvent &evt)
{
}

void cMain::OnEditRedo(wxCommandEvent &evt)
{
}

void cMain::OnEditPrefs(wxCommandEvent &evt)
{
}

void cMain::OnToolBrush(wxCommandEvent &evt)
{
}

void cMain::OnToolEraser(wxCommandEvent &evt)
{
}

void cMain::OnToolShading(wxCommandEvent &evt)
{
}

void cMain::OnToolFill(wxCommandEvent &evt)
{
}

void cMain::OnHelpShortcuts(wxCommandEvent &evt)
{
}