//
// Created on Jan 29, 2021.
//
#include "Window/headers/WindowMain.h"

//Binds IDs to command functions
wxBEGIN_EVENT_TABLE(WindowMain, wxFrame)
				EVT_MENU(ID::MenuFileNew, WindowMain::OnFileNew)
				EVT_MENU(ID::MenuFileOpen, WindowMain::OnFileOpen)
				EVT_MENU(ID::MenuFileSave, WindowMain::OnFileSave)
				EVT_MENU(ID::MenuFileExit, WindowMain::OnFileExit)
				
				EVT_MENU(ID::MenuEditUndo, WindowMain::OnEditUndo)
				EVT_MENU(ID::MenuEditRedo, WindowMain::OnEditRedo)
				EVT_MENU(ID::MenuEditPrefs, WindowMain::OnEditPrefs)
				
				EVT_MENU(ID::MenuToolBrush, WindowMain::OnToolBrush)
				EVT_MENU(ID::MenuToolEraser, WindowMain::OnToolEraser)
				EVT_MENU(ID::MenuToolShading, WindowMain::OnToolShading)
				EVT_MENU(ID::MenuToolFill, WindowMain::OnToolFill)
				
				EVT_MENU(ID::MenuHelpShortcuts, WindowMain::OnHelpShortcuts)
wxEND_EVENT_TABLE()

//TODO: Fix the start coordinate and the size
WindowMain::WindowMain() :
		wxFrame(nullptr, wxID_ANY, "ChocBoarder", wxPoint(30, 30), wxSize(1920, 1080))
{
	//	Initializes all the window components
	InitMenu(this);
	InitToolbar(this);
	InitMainPanel(this);
	InitTimelinePanel(this);
	
	SetSpacings();
}

WindowMain::~WindowMain()
{
}

//
//          Inline Window Initialization functions
//
//TODO: Add keyboard shortcuts to menu items
inline void WindowMain::InitMenu(wxFrame *_frame)
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

inline void WindowMain::InitToolbar(wxFrame *_frame)
{
//	m_toolbarPanel = new wxPanel(_frame, ID::ToolbarPanel);
	
	//	m_toolbarPanelLeft = new wxPanel(_frame, ID::ToolbarPanelLeft, wxPoint(0, 0));
	m_toolbarPanel = new wxPanel(_frame, ID::ToolbarPanel);
	m_toolbarPanel->SetBackgroundColour(Colors::primary_fg);
	
	m_toolBar = new wxToolBar(m_toolbarPanel, ID::Toolbar);
	m_toolBar->SetBackgroundColour(Colors::primary_fg);
	
	m_toolbarNew = new wxButton(m_toolBar, ID::ToolButtonNew, "New", wxDefaultPosition, Nums::tb_bttn_size);
	m_toolbarOpen = new wxButton(m_toolBar, ID::ToolButtonOpen, "Open", wxDefaultPosition, Nums::tb_bttn_size);
	m_toolbarSave = new wxButton(m_toolBar, ID::ToolButtonSave, "Save", wxDefaultPosition, Nums::tb_bttn_size);
	m_toolbarUndo = new wxButton(m_toolBar, ID::ToolButtonUndo, "Undo", wxDefaultPosition, Nums::tb_bttn_size);
	m_toolbarRedo = new wxButton(m_toolBar, ID::ToolButtonRedo, "Redo", wxDefaultPosition, Nums::tb_bttn_size);
	
	m_toolBar->AddControl(m_toolbarNew);
	m_toolBar->AddControl(m_toolbarOpen);
	m_toolBar->AddControl(m_toolbarSave);
	
	m_toolBar->AddStretchableSpace();
	
	m_toolBar->AddControl(m_toolbarUndo);
	m_toolBar->AddControl(m_toolbarRedo);
/*
	m_toolBar->AddTool(ID::ToolButtonNew, "New", wxBitmap(wxSize(Nums::tb_bttn_size_num, Nums::tb_bttn_size_num)));
	m_toolBar->AddTool(ID::ToolButtonNew, "Open", wxBitmap(wxSize(Nums::tb_bttn_size_num, Nums::tb_bttn_size_num)));
	m_toolBar->AddTool(ID::ToolButtonNew, "Save", wxBitmap(wxSize(Nums::tb_bttn_size_num, Nums::tb_bttn_size_num)));

	m_toolBar->AddStretchableSpace();

	m_toolBar->AddTool(ID::ToolButtonNew, "Undo", wxBitmap(wxSize(Nums::tb_bttn_size_num, Nums::tb_bttn_size_num)));
	m_toolBar->AddTool(ID::ToolButtonNew, "Redo", wxBitmap(wxSize(Nums::tb_bttn_size_num, Nums::tb_bttn_size_num)));
	*/
	m_toolBar->Realize();
	
}

inline void WindowMain::InitMainPanel(wxFrame *_frame)
{
	m_middlePanel = new wxPanel(_frame, ID::MiddlePanel);
	m_middlePanel->SetBackgroundColour(Colors::window_bg);
	
	m_canvasPanel = new wxPanel(m_middlePanel, ID::CanvasPanel);
	m_canvasPanel->SetBackgroundColour(Colors::canvas_bg);
	
	m_optionsPanel = new wxPanel(m_middlePanel, ID::OptionsPanel);
	m_optionsPanel->SetBackgroundColour(Colors::primary_bg);
	m_toolbarOpen = new wxButton(m_optionsPanel, wxID_ANY, "Options panel");
}

inline void WindowMain::InitTimelinePanel(wxFrame *_frame)
{
	m_timelinePanel = new wxPanel(_frame, ID::TimelinePanel);
	m_timelinePanel->SetBackgroundColour(Colors::primary_fg);
}

inline void WindowMain::SetSpacings()
{
	//	Flags: Proportion determines sizer major axis stretching
	//	wxEXPAND / wxFIXED_MINSIZE determine sizer minor axis stretching
	//	wxTOP, wxBOTTOM, wxLEFT, wxRIGHT, wxALL determine borders
	wxBoxSizer *SpacerMain = new wxBoxSizer(wxVERTICAL);
	SpacerMain->Add(m_toolbarPanel, 0, wxEXPAND);
	SpacerMain->Add(m_middlePanel, 1, wxEXPAND | wxTOP | wxBOTTOM, 2);
	SpacerMain->Add(m_timelinePanel, 0, wxEXPAND);
	this->SetSizer(SpacerMain);
	
	wxBoxSizer *SpacerToolbar = new wxBoxSizer(wxHORIZONTAL);
	SpacerToolbar->Add(m_toolBar, 1, wxFIXED_MINSIZE);
	m_toolbarPanel->SetSizer(SpacerToolbar);
	
	wxBoxSizer *SpacerMiddle = new wxBoxSizer(wxHORIZONTAL);
	SpacerMiddle->Add(m_canvasPanel, 1, wxEXPAND);
	SpacerMiddle->Add(m_optionsPanel, 0, wxEXPAND | wxLEFT, 2);
	m_middlePanel->SetSizer(SpacerMiddle);
	
	wxBoxSizer *SpacerTimelineControl = new wxBoxSizer(wxHORIZONTAL);
	SpacerMiddle->AddStretchSpacer();
//	SpacerMiddle->Add
	SpacerMiddle->AddStretchSpacer();
	m_timelineControlPanel->SetSizer(SpacerTimelineControl);
}