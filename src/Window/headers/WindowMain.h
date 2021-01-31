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
	
	wxPanel *m_toolbarPanel = nullptr;
	wxPanel *m_middlePanel = nullptr;
	wxPanel *m_canvasPanel = nullptr;
	wxPanel *m_optionsPanel = nullptr;
	wxPanel *m_timelinePanel = nullptr;
	
	wxToolBar *m_toolBar = nullptr;
	wxToolBarToolBase *m_toolButtonNew = nullptr;
	wxToolBarToolBase *m_toolButtonOpen = nullptr;
	wxToolBarToolBase *m_toolButtonSave = nullptr;
	
	wxPanel *m_toolbarPanelLeft = nullptr;
	wxButton *m_toolbarOpen = nullptr;
	wxButton *m_toolbarSave = nullptr;
	
	wxPanel *m_toolbarPanelMiddle = nullptr;
	wxStaticText *m_toolbarFileName = nullptr;
	
	wxPanel *m_toolbarPanelRight = nullptr;
	wxButton *m_toolbarUndo = nullptr;
	wxButton *m_toolbarRedo = nullptr;
	
	//Timeline
	//Add timeline component here
	wxPanel *m_timelineControlPanel = nullptr;
	
	void InitMenu(wxFrame *);
	void InitToolbar(wxFrame *);
	void InitMainPanel(wxFrame *);
	void InitTimelinePanel(wxFrame *);
	
	void SetSpacings();

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

