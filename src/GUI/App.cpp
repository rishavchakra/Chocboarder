//
// Created on Jan 29, 2021.
//
#include "headers/App.h"

wxIMPLEMENT_APP(App);

App::App() {

}

App::~App() {

}

bool App::OnInit() {
	m_main = new WindowMain();
	m_main->SetBackgroundColour(Colors::window_bg);
	m_main->Show();
	SetTopWindow(m_main);
	return true;
}
