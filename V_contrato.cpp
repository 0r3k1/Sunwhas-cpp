#include "V_contrato.h"

using namespace std;

V_contrato::V_contrato(wxWindow *parent) : contraros(parent) {
	vector<cliente_> cli;
	vector<dominio_> dom;
	sqlite db("data.db");
	
	cli = db.getClientes();
	dom = db.getDominio();
	
	for(int i=0; i<(int)cli.size(); i++){
		txt_nombre->Append(cli[i].nombre);
	}
	
	for(int i=0; i<(int)dom.size(); i++){
		txt_dominio->Append(dom[i].nombre);
	}
	
	for(int i=0; i<DIAS; i++){
		txt_dia->Append(diaSemana[i]);
	}
	
	pintaGrilla();
	
	cli.clear();
}

V_contrato::V_contrato(bool viw, wxWindow *parent) : contraros(parent) {
	nombre->Hide();
	direccion->Hide();
	email->Hide();
	arroba->Hide();
	dia->Hide();
	tel->Hide();
	placa->Hide();
	marca->Hide();
	linea->Hide();
	precio->Hide();
	txt_dia->Hide();
	txt_direccion->Hide();
	txt_dominio->Hide();
	txt_email->Hide();
	txt_linea->Hide();
	txt_marca->Hide();
	txt_nombre->Hide();
	txt_placa->Hide();
	txt_precio->Hide();
	txt_tel->Hide();
	agregar->Hide();
	
	pintaGrilla();
}

V_contrato::~V_contrato() {
	
}

void V_contrato::onclick_agregar( wxCommandEvent& event )  {
	contratos_ contrato;
	string dia, precio, dominio;
	vector<dominio_> dom;
	wxString alerta;
	sqlite db("data.db");
	bool flag = false;
	
	dom = db.getDominio();
	
	contrato.cliente.nombre = txt_nombre->GetValue().mb_str();
	contrato.direccion = txt_direccion->GetValue().mb_str();
	contrato.cliente.email = txt_email->GetValue().mb_str();
	dominio = txt_dominio->GetValue();
	contrato.cliente.tel = txt_tel->GetValue().mb_str();
	contrato.placa = txt_placa->GetValue().mb_str();
	contrato.marca = txt_marca->GetValue().mb_str();
	contrato.linea = txt_linea->GetValue().mb_str();
	dia = txt_dia->GetValue().mb_str();
	contrato.dia = getIdDia(dia);
	precio = txt_precio->GetValue().mb_str();
	contrato.precio = convertToInt(precio);
	
	for(int i=0; i<(int)dom.size(); i++){
		if(wxStringToString(dominio) == dom[i].nombre){
			flag = true;
			contrato.cliente.idemail = dom[i].id;
			break;
		}
	}
	
	if(!flag) db.insertDominio(dominio);
	
	if(contrato.cliente.nombre.empty()){
		alerta.Printf("Ingrese un nombre");
		wxMessageBox(alerta, "Error Nombre", wxICON_ERROR);
	}else if(contrato.direccion.empty()){
		alerta.Printf("Ingrese una dirreccion");
		wxMessageBox(alerta, "Error Direccion", wxICON_ERROR);
	}else if(txt_email->IsEmpty()){
		contrato.cliente.email = "Anonimo";
		contrato.cliente.idemail = -1;
	}else if(contrato.cliente.tel.empty()){
		alerta.Printf("Ingrese un numero de telefono");
		wxMessageBox(alerta, "Error Telefono", wxICON_ERROR);
	}else if(contrato.placa.empty() || cPlaca(contrato.placa)){
		alerta.Printf("La placa %s es incorrecta", contrato.placa);
		wxMessageBox(alerta, "Error Placa", wxICON_ERROR);
	}else if(contrato.marca.empty()){
		alerta.Printf("Ingrese una marca");
		wxMessageBox(alerta, "Error Marca", wxICON_ERROR);
	}else if(contrato.linea.empty()){
		alerta.Printf("Ingrese una linea de veiculo");
		wxMessageBox(alerta, "Error Linea", wxICON_ERROR);
	}else if(!ifExistDia(dia)){
		alerta.Printf("Ingrese un parametro de la lista dia porfavor");
		wxMessageBox(alerta, "Error Dia", wxICON_ERROR);
	}else{
		char consulta[300];
		sprintf(consulta, "'%s', '%s', '%s', %d, %d, '%s', '%s', '%s', '%s', %d", contrato.cliente.nombre.c_str(), contrato.direccion.c_str(), contrato.cliente.email.c_str(), contrato.cliente.idemail, contrato.dia, contrato.cliente.tel.c_str(), contrato.placa.c_str(), contrato.marca.c_str(), contrato.linea.c_str(), contrato.precio);
		db.insertContrato(consulta);
		
		txt_dia->Clear();
		txt_direccion->Clear();
		txt_email->Clear();
		txt_linea->Clear();
		txt_marca->Clear();
		txt_nombre->Clear();
		txt_placa->Clear();
		txt_precio->Clear();
		txt_tel->Clear();
		txt_dominio->Clear();
		
		pintaGrilla();
	}
	
	event.Skip();
}

void V_contrato::pintaGrilla(){
	vector<contratos_> vec;
	sqlite db("data.db");
	wxString e_mail;
	
	vec = db.getContrato();
	
	grilla->AppendRows(vec.size() - grilla->GetNumberRows());
	for(int i=0; i<(int)vec.size(); i++){
		grilla->SetCellValue(i, 0, vec[i].cliente.nombre);
		grilla->SetCellValue(i, 1, vec[i].direccion);
		if(vec[i].cliente.idemail == -1){
			e_mail.Printf("%s@%s", vec[i].cliente.email, "desconocido");
			grilla->SetCellValue(i, 2, e_mail);
		}else{
			e_mail.Printf("%s@%s", vec[i].cliente.email, db.getNomDominio(vec[i].cliente.idemail));
			grilla->SetCellValue(i, 2, e_mail);
		}
		grilla->SetCellValue(i, 3, diaSemana[vec[i].dia]);
		grilla->SetCellValue(i, 4, vec[i].cliente.tel);
		grilla->SetCellValue(i, 5, vec[i].placa);
		grilla->SetCellValue(i, 6, vec[i].marca);
		grilla->SetCellValue(i, 7, vec[i].linea);
		grilla->SetCellValue(i, 8, convertToString(vec[i].lavados));
		
		for(int j=0; j<9; j++){
			if(vec[i].dia == day(strFecha().tm_wday-1)){
				grilla->SetCellBackgroundColour(i, j, wxColour(58, 129, 196, 0));
			}else if(vec[i].dia == day(strFecha().tm_wday)){
				grilla->SetCellBackgroundColour(i, j, wxColour(191, 178, 196, 255));
			}
		}
	}
	
	grilla->SetSelectionMode(wxGrid::wxGridSelectRows);
	vec.clear();
}

void V_contrato::onclic_nombre( wxCommandEvent& event )  {
	string cliente;
	vector<cliente_> vec;
	sqlite db("data.db");
	
	cliente = txt_nombre->GetValue().mb_str();
	
	vec = db.getClientes();
	
	for(int i=0; i<(int)vec.size(); i++){
		if(cliente == vec[i].nombre){
			txt_tel->SetValue(vec[i].tel);
			txt_email->SetValue(vec[i].email);
			if(vec[i].idemail == -1){
				txt_dominio->SetValue("@desconocido.com");
			}else{
				txt_dominio->SetValue(db.getNomDominio(vec[i].idemail));
			}
			break;
		}
	}
	event.Skip();
}

