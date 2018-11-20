#include "V_principal.h"

#include <iostream>
using namespace std;

V_principal::V_principal(wxWindow *parent) : Index(parent) {
	SetIcon(wxIcon(wxIconLocation("img/index.ico")));
	espera = 5; //tiempo de espera por defecto para el cierre de secion
	
	anterior = strFecha();
	
	log.nivel = -1;
	freezUsuario();
	not_admin();
}

V_principal::~V_principal() {
	Destroy();
}

void V_principal::onclick_index_btn_venta( wxCommandEvent& event )  {
	V_venta* win = new V_venta(NULL);
	win->Show();
	event.Skip();
}

void V_principal::onclick_index_btn_retiro( wxCommandEvent& event )  {
	V_retiro* win = new V_retiro(NULL);
	win->Show();
	event.Skip();
}

void V_principal::onclick_index_btn_activo( wxCommandEvent& event )  {
	V_activo* win = new V_activo(NULL);
	win->Show();
	event.Skip();
}

void V_principal::onclick_menu_empleado( wxCommandEvent& event )  {
	V_empleados* win = new V_empleados();
	win->Show();
	event.Skip();
}

void V_principal::onclick_menu_servicio( wxCommandEvent& event )  {
	V_servicios* win = new V_servicios();
	win->Show();
	event.Skip();
}

void V_principal::onclick_menu_cliente( wxCommandEvent& event )  {
	V_clientes* win = new V_clientes();
	win->Show();
	event.Skip();
}

void V_principal::onclick_menu_contrato( wxCommandEvent& event )  {
	V_contrato* win = new V_contrato();
	win->Show();
	event.Skip();
}


void V_principal::onclick_menu_ver_empleado( wxCommandEvent& event )  {
	V_empleados* win = new V_empleados(true);
	win->Show();
	event.Skip();
}

void V_principal::onclick_menu_ver_servicio( wxCommandEvent& event )  {
	V_servicios* win = new V_servicios(true);
	win->Show();
	event.Skip();
}

void V_principal::onclick_menu_ver_cliente( wxCommandEvent& event )  {
	V_clientes* win = new V_clientes(true);
	win->Show();
	event.Skip();
}

void V_principal::onclick_menu_ver_contratos( wxCommandEvent& event )  {
	V_contrato* win = new V_contrato(true);
	win->Show();
	event.Skip();
}

void V_principal::onclick_menu_usuario( wxCommandEvent& event )  {
	V_login* win = new V_login("Usuarios", "Agregar");
	win->Show();
	event.Skip();
}

void V_principal::onclick_menu_admin( wxCommandEvent& event )  {
	V_login* win = new V_login("Administradores", "Agregar");
	win->Show();
	event.Skip();
}

void V_principal::onclick_menu_singIn_U( wxCommandEvent& event )  {
	V_login* win = new V_login("Usuarios", "Iniciar");
	win->Show();
	event.Skip();
}

void V_principal::onclick_menu_singIn_A( wxCommandEvent& event )  {
	V_login* win = new V_login("Administradores", "Iniciar");
	win->ShowModal();
	log = win->getLogin();
	freezUsuario();
	event.Skip();
}

void V_principal::freezUsuario(){
	if(log.nivel != ADMIN and log.nivel != ROOT){
		index_btn_venta->Enable(false);
		index_btn_retiro->Enable(false);
		empleado->Enable(false);
		servicio->Enable(false);
		clientes->Enable(false);
		contrato->Enable(false);
		usuario->Enable(false);
		admin->Enable(false);
		v_cliente->Enable(false);
		v_contratos->Enable(false);
		//del_admin->Enable(false);
		//del_user->Enable(false);
		//del_venta->Enable(false);
	}else if(log.nivel == ADMIN || log.nivel == ROOT){
		index_btn_venta->Enable(true);
		index_btn_retiro->Enable(true);
		empleado->Enable(true);
		servicio->Enable(true);
		clientes->Enable(true);
		contrato->Enable(true);
		usuario->Enable(true);
		admin->Enable(true);
		v_cliente->Enable(true);
		v_contratos->Enable(true);
		//del_user->Enable(true);
		//del_venta->Enable(true);
		
		/*if(log.nivel == ROOT){
			del_admin->Enable(true);
		}*/
	}
	
	Refresh();
}

void V_principal::on_motion_mouse( wxMouseEvent& event )  {
	actual = strFecha();
	
	if(anterior.tm_min + espera == actual.tm_min){
		log.nivel = -1;
		freezUsuario();
	}
	
	anterior = strFecha();
	
	event.Skip();
}

void V_principal::not_admin(){
	sqlite db("data.db");
	
	vector<login_> vec = db.getLogin();
	if(vec.empty()){
		db.insertLogin("Cristobal Rodas", "123456789", ROOT);
	}
}


void V_principal::onclick_menu_del_A( wxCommandEvent& event )  {
	event.Skip();
}

void V_principal::onclick_menu_del_U( wxCommandEvent& event )  {
	event.Skip();
}

void V_principal::onclick_menu_del_V( wxCommandEvent& event )  {
	event.Skip();
}

