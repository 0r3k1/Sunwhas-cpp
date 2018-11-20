#include "V_empleados.h"

using namespace std;

V_empleados::V_empleados(wxWindow *parent) : empleados(parent) {
	pintaGrilla();
}

V_empleados::V_empleados(bool ver, wxWindow *parent) : empleados(parent) {
	nombre->Hide();
	txt_nombre->Hide();
	tel->Hide();
	txt_tel->Hide();
	agregar->Hide();
	pintaGrilla();
}

void V_empleados::onclick_agregar( wxCommandEvent& event )  {
	sqlite db("data.db");
	string nombre, tel;
	vector<empleados_> vec;
	
	nombre = txt_nombre->GetValue().mb_str();
	tel = txt_tel->GetValue().mb_str();
	
	if(tel.empty()) tel = "NULL";
	
	if(nombre.empty()){
		wxString text = "Agrege un nombre para el empleado";
		wxMessageBox(text, "Error Nombre", wxICON_ERROR);
	}else{
		db.insertEmpleados(nombre, tel);
		pintaGrilla();
		txt_nombre->Clear();
		txt_tel->Clear();
	}
	
	event.Skip();
}

V_empleados::~V_empleados() {
	
}

void V_empleados::pintaGrilla(){
	sqlite db("data.db");
	vector<empleados_> vec;
	
	vec = db.getEmpleados();
	
	grilla_empleados->AppendRows(vec.size() - grilla_empleados->GetNumberRows());
	for (int i=0; i<(int)vec.size(); i++){
		grilla_empleados->SetCellValue(i, 0, vec[i].nombre);
		grilla_empleados->SetCellValue(i, 1, vec[i].tel);
	}
	
	grilla_empleados->SetSelectionMode(wxGrid::wxGridSelectRows);
}

