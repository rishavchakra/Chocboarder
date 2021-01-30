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
	InitMenu();
}

cMain::~cMain()
{
}

//
//          Inline Window Initialization functions
//
//TODO: Add keyboard shortcuts to menu items
inline void cMain::InitMenu()
{
	m_menuBar = new wxMenuBar();
	this->SetMenuBar(m_menuBar);
	
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