//
// Created on Jan 29, 2021.
//
#pragma once

#include "wx/colour.h"

//wxIDs for all buttons and commands
enum ID
{
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

	ToolbarPanel,
	ToolbarPanelLeft,
	ToolbarPanelRight,
	ToolbarPanelMiddle,
	Toolbar,
	ToolButtonNew,
	ToolButtonOpen,
	ToolButtonSave,
	ToolButtonUndo,
	ToolButtonRedo,

	MiddlePanel,
	CanvasPanel,
	Canvas,
	BrushPanel,
	OptionsPanel,
	Options,

	TimelinePanel,
	TimelineControlPanel,
	Timeline,
};

//Global wxColours for all the UI colors
namespace Colors {
	static const wxColour window_bg = wxColour(24, 24, 24);
	static const wxColour primary_fg = wxColour(40, 40, 40);
	static const wxColour primary_bg = wxColour(48, 48, 48);
	static const wxColour canvas_bg = wxColour(64, 64, 64);
	static const wxColour button_bg = wxColour(80, 80, 80);
	static const wxColour button_fg = wxColour(220, 220, 220);
}

//TODO: convert every UI string to a global string constant
//Global strings for all the menus and toolbars
namespace Strings {
}

namespace Nums {
	static const int tb_bttn_size_num = 42;
	static const wxSize tb_bttn_size = wxSize(tb_bttn_size_num, tb_bttn_size_num);
}