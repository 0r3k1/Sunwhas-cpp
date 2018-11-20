///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Nov  6 2017)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __WXFB_PROJECT_H__
#define __WXFB_PROJECT_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/statbmp.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/textctrl.h>
#include <wx/combobox.h>
#include <wx/grid.h>
#include <wx/bmpcbox.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class Index
///////////////////////////////////////////////////////////////////////////////
class Index : public wxFrame 
{
	private:
	
	protected:
		wxMenuBar* m_menubar1;
		wxMenu* M_agregar;
		wxMenuItem* empleado;
		wxMenuItem* servicio;
		wxMenuItem* clientes;
		wxMenuItem* contrato;
		wxMenuItem* usuario;
		wxMenuItem* admin;
		wxMenu* M_ver;
		wxMenuItem* v_cliente;
		wxMenuItem* v_contratos;
		wxMenu* secion;
		wxMenuItem* in_admin;
		wxMenu* M_admin;
		wxMenu* M_ayuda;
		wxStaticBitmap* m_bitmap1;
		wxStaticText* m_staticText3;
		wxButton* index_btn_venta;
		wxStaticText* m_staticText31;
		wxButton* index_btn_retiro;
		wxStaticText* m_staticText32;
		wxButton* index_btn_activo;
		
		// Virtual event handlers, overide them in your derived class
		virtual void on_motion_mouse( wxMouseEvent& event ) { event.Skip(); }
		virtual void onclick_menu_empleado( wxCommandEvent& event ) { event.Skip(); }
		virtual void onclick_menu_servicio( wxCommandEvent& event ) { event.Skip(); }
		virtual void onclick_menu_cliente( wxCommandEvent& event ) { event.Skip(); }
		virtual void onclick_menu_contrato( wxCommandEvent& event ) { event.Skip(); }
		virtual void onclick_menu_usuario( wxCommandEvent& event ) { event.Skip(); }
		virtual void onclick_menu_admin( wxCommandEvent& event ) { event.Skip(); }
		virtual void onclick_menu_ver_empleado( wxCommandEvent& event ) { event.Skip(); }
		virtual void onclick_menu_ver_servicio( wxCommandEvent& event ) { event.Skip(); }
		virtual void onclick_menu_ver_cliente( wxCommandEvent& event ) { event.Skip(); }
		virtual void onclick_menu_ver_contratos( wxCommandEvent& event ) { event.Skip(); }
		virtual void onclick_menu_singIn_U( wxCommandEvent& event ) { event.Skip(); }
		virtual void onclick_menu_singIn_A( wxCommandEvent& event ) { event.Skip(); }
		virtual void onclick_menu_del_A( wxCommandEvent& event ) { event.Skip(); }
		virtual void onclick_menu_del_U( wxCommandEvent& event ) { event.Skip(); }
		virtual void onclick_menu_del_V( wxCommandEvent& event ) { event.Skip(); }
		virtual void onclick_index_btn_venta( wxCommandEvent& event ) { event.Skip(); }
		virtual void onclick_index_btn_retiro( wxCommandEvent& event ) { event.Skip(); }
		virtual void onclick_index_btn_activo( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		Index( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Sun Whas"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,480 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~Index();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class venta
///////////////////////////////////////////////////////////////////////////////
class venta : public wxFrame 
{
	private:
	
	protected:
		wxStaticText* placa;
		wxTextCtrl* txt_placa;
		wxStaticText* servicio;
		wxComboBox* txt_servicio;
		wxStaticText* empleado;
		wxComboBox* txt_empleado;
		wxButton* venta_btn_agregar;
		wxGrid* grid_venta;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onclick_txt_placa( wxCommandEvent& event ) { event.Skip(); }
		virtual void onclick_venta_btn_agregar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		venta( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Venta del dia"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 720,570 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~venta();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class retiro
///////////////////////////////////////////////////////////////////////////////
class retiro : public wxFrame 
{
	private:
	
	protected:
		wxStaticText* m_staticText9;
		wxTextCtrl* txt_descripcion;
		wxStaticText* m_staticText11;
		wxTextCtrl* txt_monto;
		wxButton* btn_agregar;
		wxGrid* grilla;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onclick_agregar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		retiro( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Retiros"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,450 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~retiro();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class empleados
///////////////////////////////////////////////////////////////////////////////
class empleados : public wxFrame 
{
	private:
	
	protected:
		wxStaticText* nombre;
		wxTextCtrl* txt_nombre;
		wxStaticText* tel;
		wxTextCtrl* txt_tel;
		wxButton* agregar;
		wxGrid* grilla_empleados;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onclick_agregar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		empleados( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Empleados"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,450 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~empleados();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class servicios
///////////////////////////////////////////////////////////////////////////////
class servicios : public wxFrame 
{
	private:
	
	protected:
		wxStaticText* nombre;
		wxTextCtrl* txt_nombre;
		wxStaticText* valor;
		wxTextCtrl* txt_valor;
		wxButton* agregar;
		wxGrid* grilla_servicios;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onclick_agregar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		servicios( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Servicios"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,450 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~servicios();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class activo
///////////////////////////////////////////////////////////////////////////////
class activo : public wxFrame 
{
	private:
	
	protected:
		wxStaticText* buscar;
		wxTextCtrl* txt_buscar;
		wxButton* btn_buscar;
		wxGrid* grilla_activo;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onclick_txt_buscar( wxCommandEvent& event ) { event.Skip(); }
		virtual void onclick_btn_buscar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		activo( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Activo"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,457 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~activo();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class Clientes
///////////////////////////////////////////////////////////////////////////////
class Clientes : public wxFrame 
{
	private:
	
	protected:
		wxStaticText* nombre;
		wxTextCtrl* txt_nombre;
		wxStaticText* tel;
		wxTextCtrl* txt_tel;
		wxStaticText* email;
		wxTextCtrl* txt_email;
		wxStaticText* m_staticText29;
		wxBitmapComboBox* txt_dominio;
		wxButton* agregar;
		wxGrid* grilla;
		
		// Virtual event handlers, overide them in your derived class
		virtual void Onclick_agregar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		Clientes( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Clientes"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 750,479 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~Clientes();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class contraros
///////////////////////////////////////////////////////////////////////////////
class contraros : public wxFrame 
{
	private:
	
	protected:
		wxStaticText* nombre;
		wxComboBox* txt_nombre;
		wxStaticText* direccion;
		wxTextCtrl* txt_direccion;
		wxStaticText* email;
		wxTextCtrl* txt_email;
		wxStaticText* arroba;
		wxComboBox* txt_dominio;
		wxStaticText* dia;
		wxComboBox* txt_dia;
		wxStaticText* tel;
		wxTextCtrl* txt_tel;
		wxStaticText* placa;
		wxTextCtrl* txt_placa;
		wxStaticText* marca;
		wxTextCtrl* txt_marca;
		wxStaticText* linea;
		wxTextCtrl* txt_linea;
		wxStaticText* precio;
		wxTextCtrl* txt_precio;
		wxButton* agregar;
		wxGrid* grilla;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onclic_nombre( wxCommandEvent& event ) { event.Skip(); }
		virtual void onclick_agregar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		contraros( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Contratos"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 966,448 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~contraros();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class login
///////////////////////////////////////////////////////////////////////////////
class login : public wxDialog 
{
	private:
	
	protected:
		wxStaticBitmap* m_bitmap3;
		wxStaticText* m_staticText28;
		wxComboBox* txt_nombre;
		wxStaticText* m_staticText29;
		wxTextCtrl* txt_pass;
		wxButton* btn_login;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onclick_btn( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		login( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Login"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 496,255 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~login();
	
};

#endif //__WXFB_PROJECT_H__
