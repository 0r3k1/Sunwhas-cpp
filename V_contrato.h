#ifndef V_CONTRATO_H
#define V_CONTRATO_H
#include "wxfb_project.h"
#include <wx/msgdlg.h>
#include "sqlite.h"
#include <iostream>
#include <vector>

class V_contrato : public contraros {
	
private:
	
protected:
	void onclic_nombre( wxCommandEvent& event ) ;
	void onclick_agregar( wxCommandEvent& event ) ;
	
public:
	V_contrato(wxWindow *parent=NULL);
	V_contrato(bool ver, wxWindow *parent=NULL);
	~V_contrato();
	void pintaGrilla();
};

#endif

