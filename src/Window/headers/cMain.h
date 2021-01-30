//
// Created on Jan 29, 2021.
//
#pragma once

#include "wx/wx.h"
#include "misc/values.hpp"

class cMain : public wxFrame {
public:
	cMain();
	~cMain();
	
//	Adding UI components
public:
	wxMenuBar* m_menuBar = nullptr;

	void OnMenuNew(wxCommandEvent& evt);
	void OnMenuOpen(wxCommandEvent& evt);
	void OnMenuSave(wxCommandEvent& evt);
	void OnMenuExit(wxCommandEvent& evt);
	
	wxDECLARE_EVENT_TABLE();
};

