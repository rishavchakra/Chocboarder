//
// Created on Jan 29, 2021.
//
#pragma once

#include "wx/colour.h"

//Defining Menu 
#define ID_MENU_NEW 1
#define ID_MENU_OPEN 2
#define ID_MENU_SAVE 3
#define ID_MENU_EXIT 4


enum UI {
	LIST_BUTTON,
	ButtonTop
};

namespace Colors {
	static const wxColour primary_bg = wxColour(40, 40, 40);
	static const wxColour button_bg = wxColour(80, 80, 80);
	static const wxColour button_fg = wxColour(220, 220, 220);
}

namespace Strings {
}

