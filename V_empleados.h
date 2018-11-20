#ifndef V_EMPLEADOS_H
#define V_EMPLEADOS_H
#include "wxfb_project.h"
#include <wx/msgdlg.h>
#include "sqlite.h"
#include <iostream>
#include <vector>

class V_empleados : public empleados {
	void pintaGrilla();
protected:
	void onclick_agregar( wxCommandEvent& event ) ;
	
public:
	V_empleados(wxWindow *parent=NULL);
	V_empleados(bool ver, wxWindow *parent=NULL);
	~V_empleados();
};

#endif

