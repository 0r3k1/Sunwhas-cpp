#include "V_retiro.h"

using namespace std;

V_retiro::V_retiro(wxWindow *parent) : retiro(parent) {
	pintarGrilla();
}

V_retiro::~V_retiro() {
	
}

void V_retiro::onclick_agregar( wxCommandEvent& event )  {
	sqlite db("data.db");
	int mes = getMes();
	int dia = getDia();
	string descripcion, monto;
	
	descripcion = txt_descripcion->GetValue().mb_str();
	monto = txt_monto->GetValue().mb_str();
	
	if(!descripcion.empty() && !monto.empty() && cPrecio(monto)){
		db.insertRetiro(mes, dia, descripcion, convertToInt(monto));
	}
	
	pintarGrilla();
	
	event.Skip();
}


void V_retiro::pintarGrilla(){
	sqlite db("data.db");
	vector<retiro_> vec;
	char consulta[200];
	
	sprintf(consulta, "mes = %d AND dia = %d", getMes(), getDia());
	vec = db.getretiro(consulta);
	
	grilla->AppendRows(vec.size() - grilla->GetNumberRows());
	for(int i=0; i<(int)vec.size(); i++){
		grilla->SetCellValue(i, 0, vec[i].descripcion);
		grilla->SetCellValue(i, 1, convertToString(vec[i].monto));
	}
	
	grilla->SetSelectionMode(wxGrid::wxGridSelectRows);
}
