//
// Created on Jan 29, 2021.
//
#include "headers/cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
				EVT_MENU(ID_MENU_NEW, cMain::OnMenuNew)
				EVT_MENU(ID_MENU_OPEN, cMain::OnMenuOpen)
				EVT_MENU(ID_MENU_SAVE, cMain::OnMenuSave)
				EVT_MENU(ID_MENU_EXIT, cMain::OnMenuExit)
wxEND_EVENT_TABLE()

cMain::cMain() :
		wxFrame(nullptr, wxID_ANY, "ChocBoarder", wxPoint(30, 30), wxSize(800, 700))
{
//	Adds the menu to the top of the window
	m_menuBar = new wxMenuBar();
	this->SetMenuBar(m_menuBar);
	
	//Menu file options
	wxMenu *menuFile = new wxMenu();
	menuFile->Append(ID_MENU_NEW, "New");
	menuFile->Append(ID_MENU_OPEN, "Open");
	menuFile->Append(ID_MENU_SAVE, "Save");
	menuFile->Append(ID_MENU_EXIT, "Exit");
	m_menuBar->Append(menuFile, "File");
}

cMain::~cMain()
{
}

void cMain::OnMenuNew(wxCommandEvent &evt)
{
}

void cMain::OnMenuOpen(wxCommandEvent &evt)
{
}

void cMain::OnMenuSave(wxCommandEvent &evt)
{
}

void cMain::OnMenuExit(wxCommandEvent &evt)
{
	Close();
	evt.Skip();
}
