#ifndef V_ACTIVO_H
#define V_ACTIVO_H
#include "wxfb_project.h"
#include <iostream>
#include "utilidades.h"
#include "sqlite.h"

class V_activo : public activo {
	void limpiaGrilla();
protected:
	void onclick_btn_buscar( wxCommandEvent& event ) ;
	void onclick_txt_buscar( wxCommandEvent& event ) ;
	void pintaGrilla(std::string busqueda);
	
public:
	V_activo(wxWindow *parent=NULL);
	~V_activo();
};

#endif

