#ifndef V_PRINCIPAL_H
#define V_PRINCIPAL_H
#include "wxfb_project.h"
#include "utilidades.h"
#include "sqlite.h"
#include "V_venta.h"
#include "V_empleados.h"
#include "V_servicios.h"
#include "V_activo.h"
#include "V_retiro.h"
#include "V_clientes.h"
#include "V_contrato.h"
#include "V_login.h"
#include <ctime>
#include "sqlite.h"

class V_principal : public Index {
	login_ log;
	void freezUsuario();
	void not_admin();
	tm actual;
	tm anterior;
	int espera;
protected:
	void onclick_menu_del_A( wxCommandEvent& event ) ;
	void onclick_menu_del_U( wxCommandEvent& event ) ;
	void onclick_menu_del_V( wxCommandEvent& event ) ;
	void on_motion_mouse( wxMouseEvent& event ) ;
	void onclick_menu_singIn_U( wxCommandEvent& event ) ;
	void onclick_menu_singIn_A( wxCommandEvent& event ) ;
	void onclick_menu_admin( wxCommandEvent& event ) ;
	void onclick_menu_ver_empleado( wxCommandEvent& event ) ;
	void onclick_menu_ver_servicio( wxCommandEvent& event ) ;
	void onclick_menu_ver_cliente( wxCommandEvent& event ) ;
	void onclick_menu_ver_contratos( wxCommandEvent& event ) ;
	void onclick_menu_usuario( wxCommandEvent& event ) ;
	void onclick_menu_contrato( wxCommandEvent& event ) ;
	void onclick_btn_contratos( wxCommandEvent& event ) ;
	void onclick_btn_contrato( wxCommandEvent& event ) ;
	void onclick_menu_cliente( wxCommandEvent& event ) ;
	void onclick_menu_empleado( wxCommandEvent& event ) ;
	void onclick_menu_servicio( wxCommandEvent& event ) ;
	void onclick_index_btn_venta( wxCommandEvent& event ) ;
	void onclick_index_btn_retiro( wxCommandEvent& event ) ;
	void onclick_index_btn_activo( wxCommandEvent& event ) ;
	
public:
	V_principal(wxWindow *parent=NULL);
	~V_principal();
};

#endif

