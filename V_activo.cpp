#include "V_activo.h"

using namespace std;

V_activo::V_activo(wxWindow *parent) : activo(parent) {	
}

V_activo::~V_activo() {
	
}

void V_activo::onclick_txt_buscar( wxCommandEvent& event )  {
	event.Skip();
}

void V_activo::onclick_btn_buscar( wxCommandEvent& event )  {
	string texto;
	
	texto = txt_buscar->GetValue().mb_str();
	
	limpiaGrilla();
	pintaGrilla(texto);
	txt_buscar->Clear();
	
	event.Skip();
}

void V_activo::pintaGrilla(string busqueda){
	sqlite db("data.db");
	vector<registro_> vec;
	int sum = 0;
	char consulta[200];
	
	if(busqueda == "Hoy" || busqueda == "hoy"){
		sprintf(consulta, "mes = %d AND dia = %d", getMes(), getDia());
		vec = db.consulta(consulta);
	}else if(busqueda == db.getMes(busqueda).mes || busqueda == db.getMes(busqueda).abrev){
		sprintf(consulta, "mes = %d", db.getMes(busqueda).id);
		vec = db.consulta(consulta);
	}else if(db.ifExistEmpleado(busqueda)){
		sprintf(consulta, "empleado = %d", db.getIdEmpleado(busqueda));
		vec = db.consulta(consulta);
	}else{
		vector<string> parametros = palabra(busqueda);
		bool flag = false;
		string aux;
		
		for(int i=0; i<(int)parametros.size(); i++){
			aux = consulta;
			if(cPrecio(parametros[i])){
				if(flag) sprintf(consulta, "%s AND dia = %d", aux.c_str(), convertToInt(parametros[i]));
				else{
					sprintf(consulta, "dia = %d", convertToInt(parametros[i]));
					flag = true;
				}
			}else if(db.ifExistMes(parametros[i])){
				if(flag) sprintf(consulta, "%s AND mes = %d", aux.c_str(), db.getMes(parametros[i]).id);
				else{
					sprintf(consulta, "mes = %d", db.getMes(parametros[i]).id);
					flag = true;
				}
			}else if(db.ifExistEmpleado(parametros[i], true)){
				if(flag) sprintf(consulta, "%s AND empleado = %d", aux.c_str(), db.getIdEmpleado(parametros[i]));
				else{
					sprintf(consulta, "empleado = %d", db.getIdEmpleado(parametros[i]));
					flag = true;
				}
			}else if(db.ifExistServicio(parametros[i])){
				if(flag) sprintf(consulta, "%s AND servicio = '%s'", aux.c_str(), parametros[i].c_str());
				else{
					sprintf(consulta, "servicio = '%s'", parametros[i].c_str());
					flag = true;
				}
			}else if(isRang(parametros[i])){
				int one = getrang(parametros[i]);
				int two = getrang(parametros[i], 2);
				
				if(!mayor(one, two)){
					if(flag) sprintf(consulta, "%s AND (dia BETWEEN %d AND %d)", aux.c_str(), one, two);
					else{
						sprintf(consulta, "(dia BETWEEN %d AND %d)", one, two);
						flag = true;
					}
				}
			}else if(buscarservicio(parametros[i], "-", " ") != "NULL"){
				string remplazo = buscarservicio(parametros[i], "-", " ");
				if(flag) sprintf(consulta, "%s AND servicio = '%s'", aux.c_str(), remplazo.c_str());
				else{
					sprintf(consulta, "servicio = '%s'", remplazo.c_str());
					flag = true;
				}
			}if(parametros[i] == "Hoy" || parametros[i] == "hoy"){
				if(flag) sprintf(consulta, "%s AND mes = %d AND dia = %d", aux.c_str(), getMes(), getDia());
				else{
					sprintf(consulta, "mes = %d AND dia = %d", getMes(), getDia());
					flag = true;
				}
			}
		}
	}
	
	vec = db.consulta(consulta);
	
	grilla_activo->AppendRows(vec.size() - grilla_activo->GetNumberRows());
	for(int i=0; i<(int)vec.size(); i++){
		grilla_activo->SetCellValue(i, 0, vec[i].servicio);
		grilla_activo->SetCellValue(i, 1, convertToString(vec[i].precio));
		sum += vec[i].precio;
	}
	
	grilla_activo->AppendRows(1);
	grilla_activo->SetCellValue(vec.size(), 0, "Total");
	grilla_activo->SetCellValue(vec.size(), 1, convertToString(sum));
	grilla_activo->SetSelectionMode(wxGrid::wxGridSelectRows);
}

void V_activo::limpiaGrilla(){
	int num = grilla_activo->GetNumberRows();
	for(int i = 0; i < num; i++){
		grilla_activo->DeleteRows();
	}
}

