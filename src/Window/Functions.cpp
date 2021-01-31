//
// Created on Jan 31, 2021.
//
//
//          Command event functions
//
#include "headers/WindowMain.h"

void WindowMain::OnFileNew(wxCommandEvent &evt)
{
}

void WindowMain::OnFileOpen(wxCommandEvent &evt)
{
}

void WindowMain::OnFileSave(wxCommandEvent &evt)
{
}

void WindowMain::OnFileExit(wxCommandEvent &evt)
{
	Close();
	evt.Skip();
}

void WindowMain::OnEditUndo(wxCommandEvent &evt)
{
}

void WindowMain::OnEditRedo(wxCommandEvent &evt)
{
}

void WindowMain::OnEditPrefs(wxCommandEvent &evt)
{
}

void WindowMain::OnToolBrush(wxCommandEvent &evt)
{
}

void WindowMain::OnToolEraser(wxCommandEvent &evt)
{
}

void WindowMain::OnToolShading(wxCommandEvent &evt)
{
}

void WindowMain::OnToolFill(wxCommandEvent &evt)
{
}

void WindowMain::OnHelpShortcuts(wxCommandEvent &evt)
{
}