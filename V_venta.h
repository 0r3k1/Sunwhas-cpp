#ifndef V_VENTA_H
#define V_VENTA_H
#include "wxfb_project.h"
#include <iostream>
#include <vector>
#include "sqlite.h"
#include "utilidades.h"
#include <wx/msgdlg.h>

class V_venta : public venta {
	int d;
	int m;
	void pintaGrilla(int _d, int _m);
protected:
	void onclick_txt_placa( wxCommandEvent& event ) ;
	void onclick_txt_servicio( wxCommandEvent& event ) ;
	void onclick_txt_empleado( wxCommandEvent& event ) ;
	void onclick_venta_btn_agregar( wxCommandEvent& event ) ;
	
public:
	V_venta(wxWindow *parent=NULL);
	~V_venta();
};

#endif

