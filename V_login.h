#ifndef V_LOGIN_H
#define V_LOGIN_H
#include "wxfb_project.h"
#include <iostream>
#include "sqlite.h"
#include <wx/msgdlg.h>
#include <vector>

class V_login : public login {
	
login_ log;
	
protected:
	void onclick_btn( wxCommandEvent& event ) ;
	
public:
	V_login(wxWindow *parent=NULL);
	V_login(std::string title = "Usuario", std::string button = "Agregar", wxWindow *parent=NULL);
	login_ getLogin(){return log;};
	~V_login();
};

#endif

