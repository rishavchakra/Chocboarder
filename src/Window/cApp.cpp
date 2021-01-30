//
// Created on Jan 29, 2021.
//
#include "headers/cApp.h"

wxIMPLEMENT_APP(cApp);

cApp::cApp() {

}

cApp::~cApp() {

}

bool cApp::OnInit() {
	m_main = new cMain();
	m_main->SetBackgroundColour(Colors::primary_bg);
	m_main->Show();
	return true;
}
