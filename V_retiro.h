#ifndef V_RETIRO_H
#define V_RETIRO_H
#include "wxfb_project.h"
#include "sqlite.h"
#include "utilidades.h"
#include <iostream>

class V_retiro : public retiro {
	
private:
	
protected:
	void onclick_agregar( wxCommandEvent& event ) ;
	
public:
	V_retiro(wxWindow *parent=NULL);
	~V_retiro();
	void pintarGrilla();
};

#endif

