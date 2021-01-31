//
// Created on Jan 29, 2021.
//
#pragma once

#include "wx/wx.h"
#include "WindowMain.h"
#include "misc/values.hpp"

class App : public wxApp {
public:
	App();
	~App();
	virtual bool OnInit();

private:
	WindowMain *m_main = nullptr;
};

