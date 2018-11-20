#ifndef V_SERVICIOS_H
#define V_SERVICIOS_H

#include "wxfb_project.h"
#include <iostream>
#include <vector>
#include "sqlite.h"
#include "utilidades.h"
#include <wx/msgdlg.h>

class V_servicios : public servicios {
		void pintaGrilla();
protected:
	void onclick_agregar( wxCommandEvent& event ) ;
	
public:
	V_servicios(wxWindow *parent=NULL);
	V_servicios(bool ver, wxWindow *parent=NULL);
	~V_servicios();
};

#endif

