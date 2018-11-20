///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Nov  6 2017)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxfb_project.h"

///////////////////////////////////////////////////////////////////////////

Index::Index( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 500,480 ), wxSize( 500,480 ) );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INACTIVEBORDER ) );
	
	m_menubar1 = new wxMenuBar( 0 );
	M_agregar = new wxMenu();
	empleado = new wxMenuItem( M_agregar, wxID_ANY, wxString( wxT("Agregar Empleado") ) , wxEmptyString, wxITEM_NORMAL );
	M_agregar->Append( empleado );
	
	servicio = new wxMenuItem( M_agregar, wxID_ANY, wxString( wxT("Agregar Servicio") ) , wxEmptyString, wxITEM_NORMAL );
	M_agregar->Append( servicio );
	
	clientes = new wxMenuItem( M_agregar, wxID_ANY, wxString( wxT("Agregar Cliente") ) , wxEmptyString, wxITEM_NORMAL );
	M_agregar->Append( clientes );
	
	contrato = new wxMenuItem( M_agregar, wxID_ANY, wxString( wxT("Agregar contrato") ) , wxEmptyString, wxITEM_NORMAL );
	M_agregar->Append( contrato );
	
	M_agregar->AppendSeparator();
	
	usuario = new wxMenuItem( M_agregar, wxID_ANY, wxString( wxT("Agregar Usuario") ) , wxEmptyString, wxITEM_NORMAL );
	M_agregar->Append( usuario );
	
	admin = new wxMenuItem( M_agregar, wxID_ANY, wxString( wxT("Agregar administrador") ) , wxEmptyString, wxITEM_NORMAL );
	M_agregar->Append( admin );
	
	m_menubar1->Append( M_agregar, wxT("Agregar") ); 
	
	M_ver = new wxMenu();
	wxMenuItem* v_empleado;
	v_empleado = new wxMenuItem( M_ver, wxID_ANY, wxString( wxT("ver empleados") ) , wxEmptyString, wxITEM_NORMAL );
	M_ver->Append( v_empleado );
	
	wxMenuItem* v_servicio;
	v_servicio = new wxMenuItem( M_ver, wxID_ANY, wxString( wxT("ver servicios") ) , wxEmptyString, wxITEM_NORMAL );
	M_ver->Append( v_servicio );
	
	v_cliente = new wxMenuItem( M_ver, wxID_ANY, wxString( wxT("ver clientes") ) , wxEmptyString, wxITEM_NORMAL );
	M_ver->Append( v_cliente );
	
	v_contratos = new wxMenuItem( M_ver, wxID_ANY, wxString( wxT("ver contratos") ) , wxEmptyString, wxITEM_NORMAL );
	M_ver->Append( v_contratos );
	
	m_menubar1->Append( M_ver, wxT("Ver") ); 
	
	secion = new wxMenu();
	wxMenuItem* in_user;
	in_user = new wxMenuItem( secion, wxID_ANY, wxString( wxT("Iniciar como Usuario") ) , wxEmptyString, wxITEM_NORMAL );
	secion->Append( in_user );
	
	in_admin = new wxMenuItem( secion, wxID_ANY, wxString( wxT("Iniciar como Admin") ) , wxEmptyString, wxITEM_NORMAL );
	secion->Append( in_admin );
	
	m_menubar1->Append( secion, wxT("Iniciar Secion") ); 
	
	M_admin = new wxMenu();
	wxMenuItem* del_admin;
	del_admin = new wxMenuItem( M_admin, wxID_ANY, wxString( wxT("Eliminar Administrador") ) , wxEmptyString, wxITEM_NORMAL );
	M_admin->Append( del_admin );
	
	wxMenuItem* del_user;
	del_user = new wxMenuItem( M_admin, wxID_ANY, wxString( wxT("Eliminar Usuario") ) , wxEmptyString, wxITEM_NORMAL );
	M_admin->Append( del_user );
	
	wxMenuItem* del_venta;
	del_venta = new wxMenuItem( M_admin, wxID_ANY, wxString( wxT("Eliminar Venta") ) , wxEmptyString, wxITEM_NORMAL );
	M_admin->Append( del_venta );
	
	m_menubar1->Append( M_admin, wxT("Administrador") ); 
	
	M_ayuda = new wxMenu();
	wxMenuItem* Copy;
	Copy = new wxMenuItem( M_ayuda, wxID_ANY, wxString( wxT("Copy Right") ) , wxEmptyString, wxITEM_NORMAL );
	M_ayuda->Append( Copy );
	
	wxMenuItem* M_manual;
	M_manual = new wxMenuItem( M_ayuda, wxID_ANY, wxString( wxT("Manual de Usuario") ) , wxEmptyString, wxITEM_NORMAL );
	M_ayuda->Append( M_manual );
	
	m_menubar1->Append( M_ayuda, wxT("Ayuda") ); 
	
	this->SetMenuBar( m_menubar1 );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	m_bitmap1 = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("img/logo.bmp"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_bitmap1, 0, wxALL, 5 );
	
	
	bSizer1->Add( bSizer2, 0, 0, 5 );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Venta"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer11->Add( m_staticText3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	index_btn_venta = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( index_btn_venta, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer5->Add( bSizer11, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer111;
	bSizer111 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText31 = new wxStaticText( this, wxID_ANY, wxT("Retiro"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	bSizer111->Add( m_staticText31, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	index_btn_retiro = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer111->Add( index_btn_retiro, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer5->Add( bSizer111, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer112;
	bSizer112 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText32 = new wxStaticText( this, wxID_ANY, wxT("Activo"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32->Wrap( -1 );
	bSizer112->Add( m_staticText32, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	index_btn_activo = new wxButton( this, wxID_ANY, wxT("Ver"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer112->Add( index_btn_activo, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer5->Add( bSizer112, 1, wxEXPAND, 5 );
	
	
	bSizer1->Add( bSizer5, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_MOTION, wxMouseEventHandler( Index::on_motion_mouse ) );
	this->Connect( empleado->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Index::onclick_menu_empleado ) );
	this->Connect( servicio->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Index::onclick_menu_servicio ) );
	this->Connect( clientes->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Index::onclick_menu_cliente ) );
	this->Connect( contrato->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Index::onclick_menu_contrato ) );
	this->Connect( usuario->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Index::onclick_menu_usuario ) );
	this->Connect( admin->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Index::onclick_menu_admin ) );
	this->Connect( v_empleado->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Index::onclick_menu_ver_empleado ) );
	this->Connect( v_servicio->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Index::onclick_menu_ver_servicio ) );
	this->Connect( v_cliente->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Index::onclick_menu_ver_cliente ) );
	this->Connect( v_contratos->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Index::onclick_menu_ver_contratos ) );
	this->Connect( in_user->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Index::onclick_menu_singIn_U ) );
	this->Connect( in_admin->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Index::onclick_menu_singIn_A ) );
	this->Connect( del_admin->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Index::onclick_menu_del_A ) );
	this->Connect( del_user->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Index::onclick_menu_del_U ) );
	this->Connect( del_venta->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Index::onclick_menu_del_V ) );
	index_btn_venta->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Index::onclick_index_btn_venta ), NULL, this );
	index_btn_retiro->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Index::onclick_index_btn_retiro ), NULL, this );
	index_btn_activo->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Index::onclick_index_btn_activo ), NULL, this );
}

Index::~Index()
{
	// Disconnect Events
	this->Disconnect( wxEVT_MOTION, wxMouseEventHandler( Index::on_motion_mouse ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Index::onclick_menu_empleado ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Index::onclick_menu_servicio ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Index::onclick_menu_cliente ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Index::onclick_menu_contrato ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Index::onclick_menu_usuario ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Index::onclick_menu_admin ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Index::onclick_menu_ver_empleado ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Index::onclick_menu_ver_servicio ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Index::onclick_menu_ver_cliente ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Index::onclick_menu_ver_contratos ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Index::onclick_menu_singIn_U ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Index::onclick_menu_singIn_A ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Index::onclick_menu_del_A ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Index::onclick_menu_del_U ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Index::onclick_menu_del_V ) );
	index_btn_venta->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Index::onclick_index_btn_venta ), NULL, this );
	index_btn_retiro->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Index::onclick_index_btn_retiro ), NULL, this );
	index_btn_activo->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Index::onclick_index_btn_activo ), NULL, this );
	
}

venta::venta( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 720,570 ), wxSize( 720,570 ) );
	this->SetBackgroundColour( wxColour( 105, 186, 242 ) );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );
	
	placa = new wxStaticText( this, wxID_ANY, wxT("Placa"), wxDefaultPosition, wxDefaultSize, 0 );
	placa->Wrap( -1 );
	bSizer9->Add( placa, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	txt_placa = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), 0 );
	bSizer9->Add( txt_placa, 0, wxALL, 5 );
	
	servicio = new wxStaticText( this, wxID_ANY, wxT("Servicio"), wxDefaultPosition, wxDefaultSize, 0 );
	servicio->Wrap( -1 );
	bSizer9->Add( servicio, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	txt_servicio = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 170,-1 ), 0, NULL, 0 ); 
	bSizer9->Add( txt_servicio, 1, wxALL, 5 );
	
	empleado = new wxStaticText( this, wxID_ANY, wxT("Empleado"), wxDefaultPosition, wxDefaultSize, 0 );
	empleado->Wrap( -1 );
	bSizer9->Add( empleado, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	txt_empleado = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 170,-1 ), 0, NULL, 0 ); 
	bSizer9->Add( txt_empleado, 1, wxALL, 5 );
	
	venta_btn_agregar = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	bSizer9->Add( venta_btn_agregar, 0, wxALL, 5 );
	
	
	bSizer8->Add( bSizer9, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );
	
	grid_venta = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	grid_venta->CreateGrid( 0, 4 );
	grid_venta->EnableEditing( false );
	grid_venta->EnableGridLines( true );
	grid_venta->EnableDragGridSize( false );
	grid_venta->SetMargins( 0, 0 );
	
	// Columns
	grid_venta->SetColSize( 0, 91 );
	grid_venta->SetColSize( 1, 281 );
	grid_venta->SetColSize( 2, 80 );
	grid_venta->SetColSize( 3, 235 );
	grid_venta->EnableDragColMove( false );
	grid_venta->EnableDragColSize( false );
	grid_venta->SetColLabelSize( 30 );
	grid_venta->SetColLabelValue( 0, wxT("Placa") );
	grid_venta->SetColLabelValue( 1, wxT("Servicio") );
	grid_venta->SetColLabelValue( 2, wxT("Precio") );
	grid_venta->SetColLabelValue( 3, wxT("Empleado") );
	grid_venta->SetColLabelValue( 4, wxT("Precio") );
	grid_venta->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	grid_venta->EnableDragRowSize( false );
	grid_venta->SetRowLabelSize( 0 );
	grid_venta->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	grid_venta->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer10->Add( grid_venta, 1, wxEXPAND|wxALL, 5 );
	
	
	bSizer8->Add( bSizer10, 1, wxEXPAND|wxRIGHT, 5 );
	
	
	this->SetSizer( bSizer8 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	txt_placa->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( venta::onclick_txt_placa ), NULL, this );
	venta_btn_agregar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( venta::onclick_venta_btn_agregar ), NULL, this );
}

venta::~venta()
{
	// Disconnect Events
	txt_placa->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( venta::onclick_txt_placa ), NULL, this );
	venta_btn_agregar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( venta::onclick_venta_btn_agregar ), NULL, this );
	
}

retiro::retiro( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 500,450 ), wxSize( 500,450 ) );
	this->SetBackgroundColour( wxColour( 105, 186, 242 ) );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText9 = new wxStaticText( this, wxID_ANY, wxT("Descripcion"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	bSizer12->Add( m_staticText9, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	txt_descripcion = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 210,-1 ), 0 );
	bSizer12->Add( txt_descripcion, 0, wxALL, 5 );
	
	m_staticText11 = new wxStaticText( this, wxID_ANY, wxT("Monto"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	bSizer12->Add( m_staticText11, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	txt_monto = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), 0 );
	bSizer12->Add( txt_monto, 0, wxALL, 5 );
	
	btn_agregar = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( btn_agregar, 0, wxALL, 5 );
	
	
	bSizer11->Add( bSizer12, 0, 0, 5 );
	
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxVERTICAL );
	
	grilla = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	grilla->CreateGrid( 0, 2 );
	grilla->EnableEditing( false );
	grilla->EnableGridLines( true );
	grilla->EnableDragGridSize( false );
	grilla->SetMargins( 0, 0 );
	
	// Columns
	grilla->SetColSize( 0, 401 );
	grilla->SetColSize( 1, 80 );
	grilla->EnableDragColMove( false );
	grilla->EnableDragColSize( false );
	grilla->SetColLabelSize( 30 );
	grilla->SetColLabelValue( 0, wxT("Descripcion") );
	grilla->SetColLabelValue( 1, wxT("Monto") );
	grilla->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	grilla->EnableDragRowSize( false );
	grilla->SetRowLabelSize( 0 );
	grilla->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	grilla->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer13->Add( grilla, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer11->Add( bSizer13, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer11 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	btn_agregar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( retiro::onclick_agregar ), NULL, this );
}

retiro::~retiro()
{
	// Disconnect Events
	btn_agregar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( retiro::onclick_agregar ), NULL, this );
	
}

empleados::empleados( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 500,450 ), wxSize( 500,450 ) );
	this->SetBackgroundColour( wxColour( 105, 186, 242 ) );
	
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxHORIZONTAL );
	
	nombre = new wxStaticText( this, wxID_ANY, wxT("Nombre"), wxDefaultPosition, wxDefaultSize, 0 );
	nombre->Wrap( -1 );
	bSizer15->Add( nombre, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	txt_nombre = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( txt_nombre, 1, wxALL, 5 );
	
	tel = new wxStaticText( this, wxID_ANY, wxT("Tel."), wxDefaultPosition, wxDefaultSize, 0 );
	tel->Wrap( -1 );
	bSizer15->Add( tel, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	txt_tel = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( txt_tel, 0, wxALL, 5 );
	
	agregar = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( agregar, 0, wxALL, 5 );
	
	
	bSizer14->Add( bSizer15, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxVERTICAL );
	
	grilla_empleados = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	grilla_empleados->CreateGrid( 0, 2 );
	grilla_empleados->EnableEditing( false );
	grilla_empleados->EnableGridLines( true );
	grilla_empleados->EnableDragGridSize( false );
	grilla_empleados->SetMargins( 0, 0 );
	
	// Columns
	grilla_empleados->SetColSize( 0, 351 );
	grilla_empleados->SetColSize( 1, 130 );
	grilla_empleados->EnableDragColMove( false );
	grilla_empleados->EnableDragColSize( false );
	grilla_empleados->SetColLabelSize( 30 );
	grilla_empleados->SetColLabelValue( 0, wxT("Nombre") );
	grilla_empleados->SetColLabelValue( 1, wxT("Telefono") );
	grilla_empleados->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	grilla_empleados->EnableDragRowSize( false );
	grilla_empleados->SetRowLabelSize( 0 );
	grilla_empleados->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	grilla_empleados->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer16->Add( grilla_empleados, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer14->Add( bSizer16, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer14 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	agregar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( empleados::onclick_agregar ), NULL, this );
}

empleados::~empleados()
{
	// Disconnect Events
	agregar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( empleados::onclick_agregar ), NULL, this );
	
}

servicios::servicios( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 500,450 ), wxSize( 500,450 ) );
	this->SetBackgroundColour( wxColour( 105, 186, 242 ) );
	
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxHORIZONTAL );
	
	nombre = new wxStaticText( this, wxID_ANY, wxT("Nombre"), wxDefaultPosition, wxDefaultSize, 0 );
	nombre->Wrap( -1 );
	bSizer15->Add( nombre, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	txt_nombre = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( txt_nombre, 1, wxALL, 5 );
	
	valor = new wxStaticText( this, wxID_ANY, wxT("Valor"), wxDefaultPosition, wxDefaultSize, 0 );
	valor->Wrap( -1 );
	bSizer15->Add( valor, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	txt_valor = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer15->Add( txt_valor, 0, wxALL, 5 );
	
	agregar = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( agregar, 0, wxALL, 5 );
	
	
	bSizer14->Add( bSizer15, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxVERTICAL );
	
	grilla_servicios = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	grilla_servicios->CreateGrid( 0, 2 );
	grilla_servicios->EnableEditing( false );
	grilla_servicios->EnableGridLines( true );
	grilla_servicios->EnableDragGridSize( false );
	grilla_servicios->SetMargins( 0, 0 );
	
	// Columns
	grilla_servicios->SetColSize( 0, 351 );
	grilla_servicios->SetColSize( 1, 130 );
	grilla_servicios->EnableDragColMove( false );
	grilla_servicios->EnableDragColSize( false );
	grilla_servicios->SetColLabelSize( 30 );
	grilla_servicios->SetColLabelValue( 0, wxT("Nombre") );
	grilla_servicios->SetColLabelValue( 1, wxT("Valor") );
	grilla_servicios->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	grilla_servicios->EnableDragRowSize( false );
	grilla_servicios->SetRowLabelSize( 0 );
	grilla_servicios->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	grilla_servicios->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer16->Add( grilla_servicios, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer14->Add( bSizer16, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer14 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	agregar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( servicios::onclick_agregar ), NULL, this );
}

servicios::~servicios()
{
	// Disconnect Events
	agregar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( servicios::onclick_agregar ), NULL, this );
	
}

activo::activo( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxColour( 105, 186, 242 ) );
	
	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxVERTICAL );
	
	buscar = new wxStaticText( this, wxID_ANY, wxT("Buscar"), wxDefaultPosition, wxDefaultSize, 0 );
	buscar->Wrap( -1 );
	bSizer21->Add( buscar, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer20->Add( bSizer21, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxHORIZONTAL );
	
	txt_buscar = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer22->Add( txt_buscar, 1, wxALL, 5 );
	
	btn_buscar = new wxButton( this, wxID_ANY, wxT("Buscar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer22->Add( btn_buscar, 0, wxALL, 5 );
	
	
	bSizer20->Add( bSizer22, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxVERTICAL );
	
	grilla_activo = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	grilla_activo->CreateGrid( 0, 2 );
	grilla_activo->EnableEditing( false );
	grilla_activo->EnableGridLines( true );
	grilla_activo->EnableDragGridSize( false );
	grilla_activo->SetMargins( 0, 0 );
	
	// Columns
	grilla_activo->SetColSize( 0, 321 );
	grilla_activo->SetColSize( 1, 80 );
	grilla_activo->EnableDragColMove( false );
	grilla_activo->EnableDragColSize( false );
	grilla_activo->SetColLabelSize( 30 );
	grilla_activo->SetColLabelValue( 0, wxT("Servicio") );
	grilla_activo->SetColLabelValue( 1, wxT("precio") );
	grilla_activo->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	grilla_activo->EnableDragRowSize( false );
	grilla_activo->SetRowLabelSize( 80 );
	grilla_activo->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	grilla_activo->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer24->Add( grilla_activo, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer20->Add( bSizer24, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer20 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	txt_buscar->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( activo::onclick_txt_buscar ), NULL, this );
	btn_buscar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( activo::onclick_btn_buscar ), NULL, this );
}

activo::~activo()
{
	// Disconnect Events
	txt_buscar->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( activo::onclick_txt_buscar ), NULL, this );
	btn_buscar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( activo::onclick_btn_buscar ), NULL, this );
	
}

Clientes::Clientes( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 651,479 ), wxSize( 750,479 ) );
	this->SetBackgroundColour( wxColour( 105, 186, 242 ) );
	
	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer25;
	bSizer25 = new wxBoxSizer( wxHORIZONTAL );
	
	nombre = new wxStaticText( this, wxID_ANY, wxT("Nombre"), wxDefaultPosition, wxDefaultSize, 0 );
	nombre->Wrap( -1 );
	bSizer25->Add( nombre, 0, wxALL, 5 );
	
	txt_nombre = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 150,-1 ), 0 );
	bSizer25->Add( txt_nombre, 1, wxALL, 5 );
	
	tel = new wxStaticText( this, wxID_ANY, wxT("Tel."), wxDefaultPosition, wxDefaultSize, 0 );
	tel->Wrap( -1 );
	bSizer25->Add( tel, 0, wxALL, 5 );
	
	txt_tel = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), 0 );
	bSizer25->Add( txt_tel, 1, wxALL, 5 );
	
	email = new wxStaticText( this, wxID_ANY, wxT("E-mail"), wxDefaultPosition, wxDefaultSize, 0 );
	email->Wrap( -1 );
	bSizer25->Add( email, 0, wxALL, 5 );
	
	txt_email = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 150,-1 ), 0 );
	bSizer25->Add( txt_email, 1, wxALL, 5 );
	
	m_staticText29 = new wxStaticText( this, wxID_ANY, wxT("@"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText29->Wrap( -1 );
	bSizer25->Add( m_staticText29, 0, wxALL, 5 );
	
	txt_dominio = new wxBitmapComboBox( this, wxID_ANY, wxT("gmail.com"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer25->Add( txt_dominio, 1, wxALL, 5 );
	
	agregar = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer25->Add( agregar, 0, wxALL, 5 );
	
	
	bSizer24->Add( bSizer25, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxVERTICAL );
	
	grilla = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	grilla->CreateGrid( 0, 3 );
	grilla->EnableEditing( true );
	grilla->EnableGridLines( true );
	grilla->EnableDragGridSize( false );
	grilla->SetMargins( 0, 0 );
	
	// Columns
	grilla->SetColSize( 0, 306 );
	grilla->SetColSize( 1, 99 );
	grilla->SetColSize( 2, 282 );
	grilla->EnableDragColMove( false );
	grilla->EnableDragColSize( true );
	grilla->SetColLabelSize( 30 );
	grilla->SetColLabelValue( 0, wxT("Nombre") );
	grilla->SetColLabelValue( 1, wxT("Tel.") );
	grilla->SetColLabelValue( 2, wxT("E-mail") );
	grilla->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	grilla->EnableDragRowSize( false );
	grilla->SetRowLabelSize( 40 );
	grilla->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	grilla->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer26->Add( grilla, 1, wxALL, 5 );
	
	
	bSizer24->Add( bSizer26, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer24 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	agregar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Clientes::Onclick_agregar ), NULL, this );
}

Clientes::~Clientes()
{
	// Disconnect Events
	agregar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Clientes::Onclick_agregar ), NULL, this );
	
}

contraros::contraros( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxColour( 105, 186, 242 ) );
	
	wxBoxSizer* bSizer27;
	bSizer27 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxHORIZONTAL );
	
	nombre = new wxStaticText( this, wxID_ANY, wxT("Nombre"), wxDefaultPosition, wxDefaultSize, 0 );
	nombre->Wrap( -1 );
	bSizer31->Add( nombre, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	txt_nombre = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer31->Add( txt_nombre, 1, wxALL, 5 );
	
	direccion = new wxStaticText( this, wxID_ANY, wxT("Direccion"), wxDefaultPosition, wxDefaultSize, 0 );
	direccion->Wrap( -1 );
	bSizer31->Add( direccion, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	txt_direccion = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer31->Add( txt_direccion, 1, wxALL, 5 );
	
	email = new wxStaticText( this, wxID_ANY, wxT("E-mail"), wxDefaultPosition, wxDefaultSize, 0 );
	email->Wrap( -1 );
	bSizer31->Add( email, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	txt_email = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer31->Add( txt_email, 1, wxALL, 5 );
	
	arroba = new wxStaticText( this, wxID_ANY, wxT("@"), wxDefaultPosition, wxDefaultSize, 0 );
	arroba->Wrap( -1 );
	bSizer31->Add( arroba, 0, wxALL, 5 );
	
	txt_dominio = new wxComboBox( this, wxID_ANY, wxT("gmail.com"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer31->Add( txt_dominio, 0, wxALL, 5 );
	
	dia = new wxStaticText( this, wxID_ANY, wxT("Dia"), wxDefaultPosition, wxDefaultSize, 0 );
	dia->Wrap( -1 );
	bSizer31->Add( dia, 0, wxALL, 5 );
	
	txt_dia = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), 0, NULL, 0 ); 
	bSizer31->Add( txt_dia, 0, wxALL, 5 );
	
	
	bSizer29->Add( bSizer31, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer32;
	bSizer32 = new wxBoxSizer( wxHORIZONTAL );
	
	tel = new wxStaticText( this, wxID_ANY, wxT("Tel"), wxDefaultPosition, wxDefaultSize, 0 );
	tel->Wrap( -1 );
	bSizer32->Add( tel, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	txt_tel = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer32->Add( txt_tel, 1, wxALL, 5 );
	
	placa = new wxStaticText( this, wxID_ANY, wxT("Placa"), wxDefaultPosition, wxDefaultSize, 0 );
	placa->Wrap( -1 );
	bSizer32->Add( placa, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	txt_placa = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), 0 );
	bSizer32->Add( txt_placa, 0, wxALL, 5 );
	
	marca = new wxStaticText( this, wxID_ANY, wxT("Marca"), wxDefaultPosition, wxDefaultSize, 0 );
	marca->Wrap( -1 );
	bSizer32->Add( marca, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	txt_marca = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer32->Add( txt_marca, 1, wxALL, 5 );
	
	linea = new wxStaticText( this, wxID_ANY, wxT("Linea"), wxDefaultPosition, wxDefaultSize, 0 );
	linea->Wrap( -1 );
	bSizer32->Add( linea, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	txt_linea = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer32->Add( txt_linea, 1, wxALL, 5 );
	
	precio = new wxStaticText( this, wxID_ANY, wxT("Precio"), wxDefaultPosition, wxDefaultSize, 0 );
	precio->Wrap( -1 );
	bSizer32->Add( precio, 0, wxALL, 5 );
	
	txt_precio = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer32->Add( txt_precio, 0, wxALL, 5 );
	
	
	bSizer29->Add( bSizer32, 0, wxEXPAND, 5 );
	
	
	bSizer28->Add( bSizer29, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer30;
	bSizer30 = new wxBoxSizer( wxVERTICAL );
	
	agregar = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer30->Add( agregar, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer28->Add( bSizer30, 0, wxEXPAND, 5 );
	
	
	bSizer27->Add( bSizer28, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxVERTICAL );
	
	grilla = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	grilla->CreateGrid( 0, 9 );
	grilla->EnableEditing( false );
	grilla->EnableGridLines( true );
	grilla->EnableDragGridSize( false );
	grilla->SetMargins( 0, 0 );
	
	// Columns
	grilla->SetColSize( 0, 161 );
	grilla->SetColSize( 1, 159 );
	grilla->SetColSize( 2, 125 );
	grilla->SetColSize( 3, 71 );
	grilla->SetColSize( 4, 80 );
	grilla->SetColSize( 5, 105 );
	grilla->SetColSize( 6, 106 );
	grilla->SetColSize( 7, 80 );
	grilla->SetColSize( 8, 52 );
	grilla->EnableDragColMove( false );
	grilla->EnableDragColSize( false );
	grilla->SetColLabelSize( 30 );
	grilla->SetColLabelValue( 0, wxT("Nombre") );
	grilla->SetColLabelValue( 1, wxT("Direccion") );
	grilla->SetColLabelValue( 2, wxT("E-mail") );
	grilla->SetColLabelValue( 3, wxT("Dia") );
	grilla->SetColLabelValue( 4, wxT("Tel.") );
	grilla->SetColLabelValue( 5, wxT("Placa") );
	grilla->SetColLabelValue( 6, wxT("Modelo") );
	grilla->SetColLabelValue( 7, wxT("Linea") );
	grilla->SetColLabelValue( 8, wxT("lavados") );
	grilla->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	grilla->EnableDragRowSize( true );
	grilla->SetRowLabelSize( 0 );
	grilla->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	grilla->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer34->Add( grilla, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer27->Add( bSizer34, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer27 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	txt_nombre->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( contraros::onclic_nombre ), NULL, this );
	agregar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( contraros::onclick_agregar ), NULL, this );
}

contraros::~contraros()
{
	// Disconnect Events
	txt_nombre->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( contraros::onclic_nombre ), NULL, this );
	agregar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( contraros::onclick_agregar ), NULL, this );
	
}

login::login( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxColour( 105, 186, 242 ) );
	
	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer37;
	bSizer37 = new wxBoxSizer( wxVERTICAL );
	
	m_bitmap3 = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("img/login.bmp"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer37->Add( m_bitmap3, 0, wxALL, 5 );
	
	
	bSizer35->Add( bSizer37, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	wxBoxSizer* bSizer38;
	bSizer38 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer39;
	bSizer39 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText28 = new wxStaticText( this, wxID_ANY, wxT("Nombre"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText28->Wrap( -1 );
	bSizer39->Add( m_staticText28, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	txt_nombre = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer39->Add( txt_nombre, 1, wxALL, 5 );
	
	
	bSizer38->Add( bSizer39, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer40;
	bSizer40 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText29 = new wxStaticText( this, wxID_ANY, wxT("Password"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText29->Wrap( -1 );
	bSizer40->Add( m_staticText29, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	txt_pass = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD );
	bSizer40->Add( txt_pass, 1, wxALL, 5 );
	
	
	bSizer38->Add( bSizer40, 1, wxEXPAND, 5 );
	
	
	bSizer35->Add( bSizer38, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer34->Add( bSizer35, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer36;
	bSizer36 = new wxBoxSizer( wxVERTICAL );
	
	btn_login = new wxButton( this, wxID_ANY, wxT("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer36->Add( btn_login, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer34->Add( bSizer36, 1, wxEXPAND, 5 );
	
	
	bSizer33->Add( bSizer34, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer33 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	btn_login->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( login::onclick_btn ), NULL, this );
}

login::~login()
{
	// Disconnect Events
	btn_login->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( login::onclick_btn ), NULL, this );
	
}
