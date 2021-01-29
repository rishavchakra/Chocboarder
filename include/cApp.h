//
// Created on Jan 29, 2021.
//
#pragma once

#include "wx/wx.h"
#include "cMain.h"

class cApp : public wxApp {
public:
	cApp();
	~cApp();
	virtual bool OnInit();

private:
	cMain *m_main = nullptr;
};

