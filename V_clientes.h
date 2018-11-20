#ifndef V_CLIENTES_H
#define V_CLIENTES_H
#include "wxfb_project.h"
#include "sqlite.h"
#include <iostream>

class V_clientes : public Clientes {
	
private:
	
protected:
	void Onclick_agregar( wxCommandEvent& event ) ;
	
public:
	V_clientes(wxWindow *parent=NULL);
	V_clientes(bool ver, wxWindow *parent=NULL);
	~V_clientes();
	void pintaGrilla();
};

#endif

