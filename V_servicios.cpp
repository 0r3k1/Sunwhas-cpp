#include "V_servicios.h"

using namespace std;

V_servicios::V_servicios(wxWindow *parent) : servicios(parent) {
	pintaGrilla();
}

V_servicios::V_servicios(bool ver, wxWindow *parent) : servicios(parent) {
	nombre->Hide();
	txt_nombre->Hide();
	valor->Hide();
	txt_valor->Hide();
	agregar->Hide();
	pintaGrilla();
}


void V_servicios::onclick_agregar( wxCommandEvent& event )  {
	sqlite db("data.db");
	string txt, val;
	int num;
	vector<servicios_> vec;
	wxString alerta;
	
	txt = txt_nombre->GetValue().mb_str();
	val = txt_valor->GetValue().mb_str();
	num = convertToInt(val);
	
	if(txt.empty()){
		alerta.Printf("Agrege un nombre para el servidio");
		wxMessageBox(alerta, "Error Nombre", wxICON_ERROR);
	}else if(val.empty() || !cPrecio(num)){
		alerta.Printf("El valor %s es invalido", val.c_str());
		wxMessageBox(alerta, "Error Valor", wxICON_ERROR);
	}else{
		db.insertServicioas(txt, num);
		txt_nombre->Clear();
		txt_valor->Clear();
	}
	
	pintaGrilla();
	
	event.Skip();
}

V_servicios::~V_servicios() {
	
}

void V_servicios::pintaGrilla(){
	sqlite db("data.db");
	vector<servicios_> vec;
	
	vec = db.getServicios();
	
	grilla_servicios->AppendRows(vec.size() - grilla_servicios->GetNumberRows());
	for (int i=0; i<(int)vec.size(); i++){
		grilla_servicios->SetCellValue(i, 0, vec[i].tipo);
		grilla_servicios->SetCellValue(i, 1, convertToString(vec[i].valor));
	}
	
	grilla_servicios->SetSelectionMode(wxGrid::wxGridSelectRows);
}

