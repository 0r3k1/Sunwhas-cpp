#include <wx/image.h>
#include "Application.h"

#include <iostream>
using namespace std;

IMPLEMENT_APP(Application)

bool Application::OnInit() {
	
	V_principal *win = new V_principal(NULL);
	win->Show();
	return true;
}

