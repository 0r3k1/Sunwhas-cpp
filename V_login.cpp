#include "V_login.h"
using namespace std;

V_login::V_login(wxWindow *parent) : login(parent) {
	
}

V_login::V_login(string title, string button, wxWindow *parent) : login(parent) {
	SetTitle(title.c_str());
	btn_login->SetLabel(button.c_str());
	sqlite db("data.db");
	
	if(button == "Iniciar"){
		vector<login_> vec = db.getLogin();
		if(title == "Usuarios"){
			for(int i=0; i<(int)vec.size(); i++){
				if(vec[i].nivel == USUARIO) txt_nombre->Append(vec[i].nombre);
			}
		}else if(title == "Administradores"){
			for(int i=0; i<(int)vec.size(); i++){
				if(vec[i].nivel == ADMIN) txt_nombre->Append(vec[i].nombre);
				else if(vec[i].nivel == ROOT) txt_nombre->Append(vec[i].nombre);
			}
		}
	}else{
		vector<empleados_> vec = db.getEmpleados();
		for(int i=0; i<(int)vec.size(); i++){
			txt_nombre->Append(vec[i].nombre);
		}
	}
}

V_login::~V_login() {
	Destroy();
}

void V_login::onclick_btn( wxCommandEvent& event )  {
	wxString title = GetTitle(), alerta;
	string nombre, pass;
	sqlite db("data.db");
	wxString button = btn_login->GetLabelText();
	
	nombre = txt_nombre->GetValue();
	pass = txt_pass->GetValue();
	
	if(button == wxT("Agregar")){
		if(nombre.empty()){
			alerta.Printf("Agrege un nombre de usuario");
			wxMessageBox(alerta, "Erro Nombre", wxICON_ERROR);
		}else if(pass.empty()){
			alerta.Printf("Agregue una contraseña");
			wxMessageBox(alerta, "Erro Nombre", wxICON_ERROR);
		}else{
			if(title == wxT("Usuarios")){
				db.insertLogin(nombre, pass, USUARIO);
			}else if(title == wxT("Administradores")){
				db.insertLogin(nombre, pass, ADMIN);
			}
			
			if(db.getRc() != SQLITE_OK){
				wxMessageBox(db.errmsg().c_str(), "Erro", wxICON_ERROR);
			}else{
				alerta.Printf("El %s %s fue agregado con exito", title, nombre);
				wxMessageBox(alerta, "Success Full");
				txt_nombre->Clear();
				txt_pass->Clear();
			}
		}
	}else if(button == wxT("Iniciar")){
		vector<login_> vec = db.getLogin();
		bool flagN = false, flagP = false;
		
		for(int i=0; i<(int)vec.size(); i++){
			if(nombre == vec[i].nombre){
				flagN = true;
				if(pass == vec[i].pass){
					flagP = true;
					log = vec[i];
				}
				break;
			}
		}
		
		if(flagN && flagP){
			alerta.Printf("Bienvenido %s", nombre.c_str());
			wxMessageBox(alerta, "Sing In");
			Destroy();
		}else{
			if(!flagN){
				alerta.Printf("El nombre %s no se encuentra registrado", nombre.c_str());
				wxMessageBox(alerta, "Sing In", wxICON_ERROR);
			}else if(!flagP){
				alerta.Printf("La contraseña es incorrecta");
				wxMessageBox(alerta, "Sing In", wxICON_ERROR);
			}
		}
	}
	event.Skip();
}

