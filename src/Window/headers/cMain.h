//
// Created on Jan 29, 2021.
//
#pragma once

#ifndef WX_INCLUDED
#define WX_INCLUDED

#include "wx/wx.h"

#endif

#include "misc/values.hpp"

class cMain : public wxFrame
{
public:
	cMain();
	
	~cMain();

//	Adding UI components
public:
	wxMenuBar *m_menuBar = nullptr;
	
	void InitMenu();

//	Button functions
	void OnFileNew(wxCommandEvent &evt);
	void OnFileOpen(wxCommandEvent &evt);
	void OnFileSave(wxCommandEvent &evt);
	void OnFileExit(wxCommandEvent &evt);
	
	void OnEditUndo(wxCommandEvent &evt);
	void OnEditRedo(wxCommandEvent &evt);
	void OnEditPrefs(wxCommandEvent &evt);
	
	void OnToolBrush(wxCommandEvent &evt);
	void OnToolEraser(wxCommandEvent &evt);
	void OnToolShading(wxCommandEvent &evt);
	void OnToolFill(wxCommandEvent &evt);
	
	void OnHelpShortcuts(wxCommandEvent &evt);

wxDECLARE_EVENT_TABLE();
};

