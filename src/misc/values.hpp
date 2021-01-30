//
// Created on Jan 29, 2021.
//
#pragma once

#include "wx/colour.h"

//wxIDs for all buttons and commands
enum ID {
	MenuFileNew = wxID_HIGHEST + 1,
	MenuFileOpen,
	MenuFileSave,
	MenuFileExit,
	MenuEditUndo,
	MenuEditRedo,
	MenuEditPrefs,
	MenuToolBrush,
	MenuToolEraser,
	MenuToolShading,
	MenuToolFill,
	MenuHelpShortcuts,
};

//Global wxColours for all the UI colors
namespace Colors {
	static const wxColour primary_bg = wxColour(40, 40, 40);
	static const wxColour button_bg = wxColour(80, 80, 80);
	static const wxColour button_fg = wxColour(220, 220, 220);
}

//TODO: convert every UI string to a global string constant
//Global strings for all the menus and toolbars
namespace Strings {
}

