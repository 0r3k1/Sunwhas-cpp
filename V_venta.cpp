#include "V_venta.h"

using namespace std;

V_venta::V_venta(wxWindow *parent) : venta(parent) {
	sqlite db("data.db");
	vector<empleados_> vecEm;
	vector<servicios_> vecSer;
	d = getDia();
	m = getMes();
	pintaGrilla(d, m);
	
	vecEm = db.getEmpleados();
	vecSer= db.getServicios();
	
	for(int i=0; i<(int)vecEm.size(); i++){
		txt_empleado->Append(vecEm[i].nombre);
	}
	
	for(int i=0; i<(int)vecSer.size(); i++){
		txt_servicio->Append(vecSer[i].tipo);
	}
}

V_venta::~V_venta() {
	
}

void V_venta::onclick_venta_btn_agregar( wxCommandEvent& event )  {
	sqlite db("data.db");
	string pla, ser, pre, em;
	vector<registro_> vec;
	
	pla = txt_placa->GetValue().mb_str();
	ser = txt_servicio->GetValue().mb_str();
	em = txt_empleado->GetValue().mb_str();
	pre = convertToString(db.getPrecioServicio(ser));
	
	wxString alerta;
	
	if(cPlaca(pla)){
		alerta.Printf("La placa %s no es valida", pla.c_str());
		wxMessageBox(alerta, "Error Placa", wxICON_ERROR);
	}else if(!db.ifExistServicio(ser)){
		alerta.Printf("El servicio %s no existe", ser.c_str());
		wxMessageBox(alerta, "Error Servicio", wxICON_ERROR);
	}else if(!db.ifExistEmpleado(em)){
		alerta.Printf("EL empleado %s no existe", em.c_str());
		wxMessageBox(alerta, "Error empleado", wxICON_ERROR);
	}
	else{
		db.insertRegistro(m, d, string("P " + pla), ser, db.getIdEmpleado(em), convertToInt(pre));
		txt_placa->Clear();
		txt_servicio->Clear();
		txt_servicio->Clear();
		txt_empleado->Clear();
	}
	
	pintaGrilla(d, m);
	event.Skip();
}

void V_venta::pintaGrilla(int _d, int _m){
	sqlite db("data.db");
	vector<registro_> vec;
	
	vec = db.getRegistro(_d, _m);
	grid_venta->AppendRows(vec.size() - grid_venta->GetNumberRows());
	for(int i=0; i<(int)vec.size(); i++){
		grid_venta->SetCellValue(i, 0, vec[i].placa);
		grid_venta->SetCellValue(i, 1, vec[i].servicio);
		grid_venta->SetCellValue(i, 2, convertToString(vec[i].precio));
		grid_venta->SetCellValue(i, 3, db.getEmpleado(vec[i].empleado));
	}
	
	grid_venta->SetSelectionMode(wxGrid::wxGridSelectRows);
}

void V_venta::onclick_txt_placa( wxCommandEvent& event )  {
	wxColour color(255, 255, 255);
	txt_placa->SetBackgroundColour(color);
	event.Skip();
}

void V_venta::onclick_txt_servicio( wxCommandEvent& event )  {
	wxColour color(255, 255, 255);
	txt_servicio->SetBackgroundColour(color);
	event.Skip();
}

void V_venta::onclick_txt_empleado( wxCommandEvent& event )  {
	wxColour color(255, 255, 255);
	txt_empleado->SetBackgroundColour(color);
	event.Skip();
}

