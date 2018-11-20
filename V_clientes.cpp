#include "V_clientes.h"

using namespace std;

V_clientes::V_clientes(wxWindow *parent) : Clientes(parent) {
	pintaGrilla();
}

V_clientes::V_clientes(bool ver, wxWindow *parent) : Clientes(parent) {
	nombre->Hide();
	tel->Hide();
	email->Hide();
	txt_email->Hide();
	txt_nombre->Hide();
	txt_tel->Hide();
	agregar->Hide();
	pintaGrilla();
}

V_clientes::~V_clientes() {
	
}

void V_clientes::Onclick_agregar( wxCommandEvent& event )  {
	sqlite db("data.db");
	cliente_ cli;
	vector<dominio_> vec = db.getDominio();
	char columna[50], value[100];
	string colAux, valAux, dominio;
	bool flag = false;
	bool emailFlag = false;
	
	cli.nombre = txt_nombre->GetValue().mb_str();
	cli.tel = txt_tel->GetValue().mb_str();
	cli.email = txt_email->GetValue().mb_str();
	dominio = wxStringToString(txt_dominio->GetValue());
	
	for(int i=0; i<(int)vec.size(); i++){
		if(cli.idemail == vec[i].nombre){
			emailFlag = true;
			cli.idemail = vec[i].id;
			break;
		}
	}
	
	if(!emailFlag){
		db.insertDominio(dominio);
	}
	
	if(!cli.nombre.empty()){
		sprintf(columna, "nombre");
		sprintf(value, "'%s'", cli.nombre.c_str());
		flag = true;
		txt_nombre->Clear();
	}
	if(!cli.tel.empty()){
		if(flag){
			colAux = columna;
			valAux = value;
			sprintf(columna, "%s, tel", colAux.c_str());
			sprintf(value, "%s, '%s'", valAux.c_str(), cli.tel.c_str());
		}else{
			sprintf(columna, "tel");
			sprintf(value, "'%s'", cli.tel.c_str());
			flag = true;
		}
		txt_tel->Clear();
	}
	if(!cli.email.empty()){		
		if(flag){
			colAux = columna;
			valAux = value;
			sprintf(columna, "%s, email, idemail", colAux.c_str());
			sprintf(value, "%s, '%s', %d", valAux.c_str(), cli.email.c_str(), cli.idemail);
		}else{
			sprintf(columna, "email, idemail");
			sprintf(value, "'%s', %d", cli.email.c_str(), cli.idemail);
		}
		txt_email->Clear();
	}
	
	db.insertCliente(columna, value);
	pintaGrilla();
	
	
	event.Skip();
}

void V_clientes::pintaGrilla(){
	sqlite db("data.db");
	vector<cliente_> vec;
	wxString e_mail;
	
	vec = db.getClientes();
	
	grilla->AppendRows(vec.size() - grilla->GetNumberRows());
	for(int i=0; i<(int)vec.size(); i++){
		grilla->SetCellValue(i, 0, vec[i].nombre);
		grilla->SetCellValue(i, 1, vec[i].tel);
		if(vec[i].idemail == -1){
			e_mail.Printf("%s@desconocido", vec[i].email);
			grilla->SetCellValue(i, 2, e_mail);
		}else{
			e_mail.Printf("%s@%s", vec[i].email, db.getNomDominio(vec[i].idemail));
			grilla->SetCellValue(i, 2, e_mail);
		}
	}
	
	grilla->SetSelectionMode(wxGrid::wxGridSelectRows);
}

