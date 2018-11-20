#include "sqlite.h"
using namespace std;

sqlite::sqlite(string nom) {
	rc = sqlite3_open(nom.c_str(), &db);
	creartablas();
}

sqlite::~sqlite() {
	sqlite3_close(db);
}

void sqlite::creartablas(){
	char consulta[50];
	char tablas[NTABLAS][15] = {
		"empleados",
		"servicios",
		"registro",
		"meses",
		"retiro",
		"clientes",
		"contratos",
		"login",
		"dominios"
	};
	
	char create[NTABLAS][300] = {
		"CREATE TABLE empleados ("
		"id INTEGER PRIMARY KEY,"
		"Nombre VARCHAR(80) NOT NULL,"
		"tel VARCHAR(15) NULL DEFAULT NULL"
		");",
		"CREATE TABLE servicios ("
		"id INTEGER PRIMARY KEY,"
		"tipo TEXT UNIQUE,"
		"valor INTEGER(2) NOT NULL"
		");",
		"CREATE TABLE registro ("
		"id INTEGER PRIMARY KEY,"
		"mes INTEGER NULL DEFAULT NULL,"
		"dia INT(2) NULL DEFAULT NULL,"
		"placa VARCHAR(8) NULL DEFAULT NULL,"
		"servicio VARCHAR(10) NULL DEFAULT NULL,"
		"empleado INT(2) NULL DEFAULT NULL,"
		"precio INT(2) NULL DEFAULT NULL"
		");",
		"CREATE TABLE meses ("
		"id INTEGER PRIMARY KEY,"
		"mes VARCHAR(10) NULL DEFAULT NULL,"
		"avrev VARCHAR(5) NULL DEFAULT NULL"
		");",
		"CREATE TABLE retiro ("
		"id INTEGER PRIMARY KEY,"
		"mes INTEGER NULL DEFAULT NULL,"
		"dia INTEGER NULL DEFAULT NULL,"
		"descripcion VARCHAR(300) NULL DEFAULT NULL,"
		"monto INTEGER NULL DEFAULT NULL"
		");",
		"CREATE TABLE clientes ("
		"id INTEGER PRIMARY KEY,"
		"nombre TEXT DEFAULT 'desconocido',"
		"tel TEXT DEFAULT 'NULL',"
		"email TXT DEFAULT 'NULL',"
		"idemail INTEGER DEFAULT 'NULL'"
		");",
		"CREATE TABLE contratos("
		"id INTEGER PRIMARY KEY,"
		"nombre VARCHAR(50),"
		"direccion VARCHAR(50),"
		"email VARCHAR(100),"
		"idemail integer,"
		"dia integer,"
		"tel varchar(15),"
		"placa varchar(8),"
		"marca varchar(20),"
		"linea varchar(20),"
		"precio integer,"
		"lavados integer default 4"
		");",
		"CREATE TABLE login("
		"id integer PRIMARY KEY,"
		"nombre varchar(20) UNIQUE NOT NULL,"
		"pass varchar(15) NOT NULL,"
		"nivel integer NOT NULL"
		");",
		"CREATE TABLE dominios("
		"id INTEGER PRIMARY KEY,"
		"nombre VARCHAR(20) NOT NULL"
		");"
	};
	
	for(int i=0; i<NTABLAS; i++){
		sprintf(consulta, "SELECT * FROM %s;", tablas[i]);
		if(SQLITE_OK != sqlite3_exec(db, consulta, 0, 0, 0)){
			sqlite3_exec(db, create[i], 0, 0, 0);
			if(string(tablas[i]) == "meses") llenarMeses();
		}
	}
}

void sqlite::insertEmpleados(string nom, string tel){
	char consulta[100];
	sprintf(consulta, "INSERT INTO empleados (Nombre, tel) VALUES('%s', '%s');", nom.c_str(), tel.c_str());
	sqlite3_exec(db, consulta, 0, 0, 0);	
}

void sqlite::insertServicioas(string tipo, int valor){
	char consulta[100];
	sprintf(consulta, "INSERT INTO servicios (tipo, valor) VALUES('%s', %d);", tipo.c_str(), valor);
	sqlite3_exec(db, consulta, 0, 0, 0);
}

void sqlite::insertRegistro(int mes, int dia, string placa, string servicio, int empleado, int precio){
	char consulta[200];
	sprintf(consulta, "INSERT INTO registro (mes, dia, placa, servicio, empleado, precio) VALUES(%d, %d, '%s', '%s', %d, %d);", mes, dia, placa.c_str(), servicio.c_str(), empleado, precio);
	sqlite3_exec(db, consulta, 0, 0, 0);
}

void sqlite::insertMes(string mes, string abrev){
	char consulta[200];
	sprintf(consulta, "INSERT INTO meses (mes, avrev) VALUES('%s', '%s');", mes.c_str(), abrev.c_str());
	sqlite3_exec(db, consulta, 0, 0, 0);
}

void sqlite::insertRetiro(int _mes, int _dia, string _descripcion, int _monto){
	char consulta[600];
	sprintf(consulta, "INSERT INTO retiro (mes, dia, descripcion, monto) VALUES(%d, %d, '%s', %d);", _mes, _dia, _descripcion.c_str(), _monto);
	sqlite3_exec(db, consulta, 0, 0, 0);
}

void sqlite::insertCliente(string columnas, string values){
	char consulta[200];
	sprintf(consulta, "INSERT INTO clientes (%s) VALUES (%s);", columnas.c_str(), values.c_str());
	sqlite3_exec(db, consulta, 0, 0, 0);
}

void sqlite::insertContrato(string valores){
	string consulta = "INSERT INTO contratos(nombre, direccion, email, idemail, dia, tel, placa, marca, linea, precio) VALUES(";
	consulta += valores;
	consulta += ");";
	sqlite3_exec(db, consulta.c_str(), 0, 0, 0);
}

void sqlite::insertLogin(string nombre, string pass, int nivel){
	char consulta[100];
	sprintf(consulta, "INSERT INTO login(nombre, pass, nivel) VALUES('%s', '%s', %d);", nombre.c_str(), pass.c_str(), nivel);
	rc = sqlite3_exec(db, consulta, 0, 0, 0);
}

void sqlite::insertDominio(string nombre){
	char consulta[60];
	sprintf(consulta, "INSERT INTO dominios(nombre) VALUES('%s');", nombre.c_str());
	rc = sqlite3_exec(db, consulta, 0, 0, 0);
}

void sqlite::llenarMeses(){
	char mes[12][11] = {
		"Enero",
		"Febrero",
		"Marzo",
		"Abril",
		"Mayo",
		"Junio",
		"Julio",
		"Agosto",
		"Septiembre",
		"Octubre",
		"Noviembre",
		"Diciembre"
	};
	char abreb[12][6] = {
		"ene",
		"feb",
		"mar",
		"abri",
		"may",
		"jun",
		"jul",
		"agos",
		"sep",
		"oct",
		"nov",
		"dici"
	};
	
	for(int i=0; i<12; i++){
		insertMes(mes[i], abreb[i]);
	}
}

vector<empleados_> sqlite::getEmpleados(){
	char consulta[100];
	empleados_ em;
	vector<empleados_> vec;
	
	sprintf(consulta, "SELECT * FROM empleados;");
	rc = sqlite3_prepare_v2(db, consulta, -1, &ppStmt, NULL);
	if(SQLITE_OK == rc){
		while (SQLITE_ROW == sqlite3_step(ppStmt)){
			em.id = sqlite3_column_int(ppStmt, 0);
			em.nombre = std::string(reinterpret_cast<const char*>(sqlite3_column_text(ppStmt, 1)));
			em.tel = std::string(reinterpret_cast<const char*>(sqlite3_column_text(ppStmt, 2)));
			vec.push_back(em);
		}
		sqlite3_finalize(ppStmt);
	}
	
	return vec;
}

int sqlite::getIdEmpleado(string em){
	char consulta[150];
	int ret = 0;
	sprintf(consulta, "SELECT id FROM empleados WHERE Nombre LIKE '%c%s%c';", '%', em.c_str(), '%');
	rc = sqlite3_prepare_v2(db, consulta, -1, &ppStmt, NULL);
	if(SQLITE_OK == rc){
		while(SQLITE_ROW == sqlite3_step(ppStmt)){
			ret = sqlite3_column_int(ppStmt, 0);
		}
		sqlite3_finalize(ppStmt);
	}
	
	return ret;
}

string sqlite::getEmpleado(int em){
	char consulta[150];
	string ret;
	sprintf(consulta, "SELECT Nombre FROM empleados WHERE id = %d;", em);
	rc = sqlite3_prepare_v2(db, consulta, -1, &ppStmt, NULL);
	if(SQLITE_OK == rc){
		while(SQLITE_ROW == sqlite3_step(ppStmt)){
			ret = std::string(reinterpret_cast<const char*>(sqlite3_column_text(ppStmt, 0)));
		}
		sqlite3_finalize(ppStmt);
	}
	
	return ret;
}

vector<servicios_> sqlite::getServicios(){
	char consulta[100];
	servicios_ ser;
	vector<servicios_> vec;
	
	sprintf(consulta, "SELECT * FROM servicios;");
	rc = sqlite3_prepare_v2(db, consulta, -1, &ppStmt, NULL);
	if(SQLITE_OK == rc){
		while(SQLITE_ROW == sqlite3_step(ppStmt)){
			ser.id = sqlite3_column_int(ppStmt, 0);
			ser.tipo = std::string(reinterpret_cast<const char*>(sqlite3_column_text(ppStmt, 1)));
			ser.valor = sqlite3_column_int(ppStmt, 2);
			vec.push_back(ser);
		}
		sqlite3_finalize(ppStmt);
	}
	
	return vec;
}

int sqlite::getPrecioServicio(string ser){
	vector<servicios_> vec = getServicios();
	for(int i=0; i<(int)vec.size(); i++){
		if(ser == vec[i].tipo) return vec[i].valor;
	}
	return -1;
}

vector<registro_> sqlite::getRegistro(int _d, int _m){
	char consulta[200];
	registro_ reg;
	vector<registro_> vec;
	
	sprintf(consulta, "SELECT * FROM registro WHERE mes = %d AND dia = %d;", _m, _d);
	rc = sqlite3_prepare_v2(db, consulta, -1, &ppStmt, NULL);
	if(SQLITE_OK == rc){
		while(SQLITE_ROW == sqlite3_step(ppStmt)){
			reg.id = sqlite3_column_int(ppStmt, 0);
			reg.mes = sqlite3_column_int(ppStmt, 1);
			reg.dia = sqlite3_column_int(ppStmt, 2);
			reg.placa = std::string(reinterpret_cast<const char*>(sqlite3_column_text(ppStmt, 3)));
			reg.servicio = std::string(reinterpret_cast<const char*>(sqlite3_column_text(ppStmt, 4)));
			reg.empleado = sqlite3_column_int(ppStmt, 5);
			reg.precio = sqlite3_column_int(ppStmt, 6);
			vec.push_back(reg);
		}
		sqlite3_finalize(ppStmt);
	}
	
	return vec;
}

mes_ sqlite::getMes(string m){
	char consulta[200];
	mes_ me;
	
	sprintf(consulta, "SELECT * FROM meses WHERE mes = '%s' OR avrev = '%s';", m.c_str(), m.c_str());
	rc = sqlite3_prepare_v2(db, consulta, -1, &ppStmt, NULL);
	if(rc == SQLITE_OK){
		while(SQLITE_ROW == sqlite3_step(ppStmt)){
			me.id = sqlite3_column_int(ppStmt, 0);
			me.mes = std::string(reinterpret_cast<const char*>(sqlite3_column_text(ppStmt, 1)));
			me.abrev = std::string(reinterpret_cast<const char*>(sqlite3_column_text(ppStmt, 2)));
		}
		sqlite3_finalize(ppStmt);
	}
	
	return me;
}

vector<mes_> sqlite::getMeses(){
	char consulta[200];
	vector<mes_> vec;
	mes_ me;
	
	sprintf(consulta, "SELECT * FROM meses;");
	rc = sqlite3_prepare_v2(db, consulta, -1, &ppStmt, NULL);
	if(rc == SQLITE_OK){
		while(SQLITE_ROW == sqlite3_step(ppStmt)){
			me.id = sqlite3_column_int(ppStmt, 0);
			me.mes = std::string(reinterpret_cast<const char*>(sqlite3_column_text(ppStmt, 1)));
			me.abrev = std::string(reinterpret_cast<const char*>(sqlite3_column_text(ppStmt, 2)));
			vec.push_back(me);
		}
		sqlite3_finalize(ppStmt);
	}
	
	return vec;
}

vector<registro_> sqlite::consulta(string where){
	char consulta[200];
	registro_ reg;
	vector<registro_> vec;
	
	sprintf(consulta, "SELECT * FROM registro WHERE %s;", where.c_str());
	rc = sqlite3_prepare_v2(db, consulta, -1, &ppStmt, NULL);
	if(SQLITE_OK == rc){
		while(SQLITE_ROW == sqlite3_step(ppStmt)){
			reg.id = sqlite3_column_int(ppStmt, 0);
			reg.mes = sqlite3_column_int(ppStmt, 1);
			reg.dia = sqlite3_column_int(ppStmt, 2);
			reg.placa = std::string(reinterpret_cast<const char*>(sqlite3_column_text(ppStmt, 3)));
			reg.servicio = std::string(reinterpret_cast<const char*>(sqlite3_column_text(ppStmt, 4)));
			reg.empleado = sqlite3_column_int(ppStmt, 5);
			reg.precio = sqlite3_column_int(ppStmt, 6);
			vec.push_back(reg);
		}
		sqlite3_finalize(ppStmt);
	}
	
	return vec;
}

bool sqlite::ifExistEmpleado(string em, bool flag){
	vector<empleados_> vec = getEmpleados();
	vector<string> comp = palabra(em);
	
	for(int i=0; i<(int)vec.size(); i++){
		vector<string> cmp = palabra(vec[i].nombre);
		for(int j=0; j<(int)comp.size(); j++){
			if(vec[i].nombre == comp[j]) return true;
			if(flag){
				for(int x=0; x<(int)cmp.size(); x++){
					if(comp[j] == cmp[x]) return true;
				}
			}
		}
	}
	
	return false;
}

bool sqlite::ifExistServicio(string ser){
	vector<servicios_> vec = getServicios();
	
	for(int i=0; i<(int)vec.size(); i++){
		if(ser == vec[i].tipo) return true;
	}
	
	return false;
}

bool sqlite::ifExistMes(string me){
	vector<mes_> vec = getMeses();
	
	for(int i=0; i<(int)vec.size(); i++){
		if(me == vec[i].mes || me == vec[i].abrev) return true;
	}
	
	return false;
}

vector<retiro_> sqlite::getretiro(string where){
	vector<retiro_> vec;
	retiro_ re;
	char consulta[200];
	
	sprintf(consulta, "SELECT * FROM retiro WHERE %s;", where.c_str());
	rc = sqlite3_prepare_v2(db, consulta, -1, &ppStmt, NULL);
	
	if(SQLITE_OK == rc){
		while(SQLITE_ROW == sqlite3_step(ppStmt)){
			re.id = sqlite3_column_int(ppStmt, 0);
			re.mes = sqlite3_column_int(ppStmt, 1);
			re.dia = sqlite3_column_int(ppStmt, 2);
			re.descripcion = std::string(reinterpret_cast<const char*>(sqlite3_column_text(ppStmt, 3)));
			re.monto = sqlite3_column_int(ppStmt, 4);
			vec.push_back(re);
		}
		sqlite3_finalize(ppStmt);
	}
	
	return vec;
}

vector<cliente_> sqlite::getClientes(){
	vector<cliente_> vec;
	cliente_ cli;
	string consulta = "SELECT * FROM clientes;";
	rc = sqlite3_prepare_v2(db, consulta.c_str(), -1, &ppStmt, NULL);
	if(SQLITE_OK == rc){
		while(SQLITE_ROW == sqlite3_step(ppStmt)){
			cli.id = sqlite3_column_int(ppStmt, 0);
			cli.nombre = std::string(reinterpret_cast<const char*>(sqlite3_column_text(ppStmt, 1)));
			cli.tel = std::string(reinterpret_cast<const char*>(sqlite3_column_text(ppStmt, 2)));
			cli.email = std::string(reinterpret_cast<const char*>(sqlite3_column_text(ppStmt, 3)));
			cli.idemail = sqlite3_column_int(ppStmt, 4);
			vec.push_back(cli);
		}
		sqlite3_finalize(ppStmt);
	}
	
	return vec;
}

vector<contratos_> sqlite::getContrato(){
	vector<contratos_> vec;
	contratos_ contrato;
	string consulta;
	
	consulta = "SELECT * FROM contratos;";
	
	rc = sqlite3_prepare_v2(db, consulta.c_str(), -1, &ppStmt, NULL);
	if(SQLITE_OK == rc){
		while(SQLITE_ROW == sqlite3_step(ppStmt)){
			contrato.id = sqlite3_column_int(ppStmt, 0);
			contrato.cliente.nombre = std::string(reinterpret_cast<const char*>(sqlite3_column_text(ppStmt, 1)));
			contrato.direccion = std::string(reinterpret_cast<const char*>(sqlite3_column_text(ppStmt, 2)));
			contrato.cliente.email = std::string(reinterpret_cast<const char*>(sqlite3_column_text(ppStmt, 3)));
			contrato.cliente.idemail = sqlite3_column_int(ppStmt, 4);
			contrato.dia = sqlite3_column_int(ppStmt, 5);
			contrato.cliente.tel = std::string(reinterpret_cast<const char*>(sqlite3_column_text(ppStmt, 6)));
			contrato.placa = std::string(reinterpret_cast<const char*>(sqlite3_column_text(ppStmt, 7)));
			contrato.marca = std::string(reinterpret_cast<const char*>(sqlite3_column_text(ppStmt, 8)));
			contrato.linea = std::string(reinterpret_cast<const char*>(sqlite3_column_text(ppStmt, 9)));
			contrato.precio = sqlite3_column_int(ppStmt, 10);
			contrato.lavados = sqlite3_column_int(ppStmt, 11);
			vec.push_back(contrato);
		}
		sqlite3_finalize(ppStmt);
	}
	
	return vec;
}

vector<contratos_> sqlite::getClientesDay(string dia){
	vector<contratos_> vec;
	contratos_ contrato;
	string consulta = "SELECT * FROM contratos;";
	string where = "WHERE dia = '" + dia + "'";
	rc = sqlite3_prepare_v2(db, consulta.c_str(), -1, &ppStmt, NULL);
	
	if(SQLITE_OK == rc){
		while(SQLITE_ROW == sqlite3_step(ppStmt)){
			contrato.id = sqlite3_column_int(ppStmt, 0);
			contrato.cliente.nombre = std::string(reinterpret_cast<const char*>(sqlite3_column_text(ppStmt, 1)));
			contrato.direccion = std::string(reinterpret_cast<const char*>(sqlite3_column_text(ppStmt, 2)));
			contrato.cliente.email = std::string(reinterpret_cast<const char*>(sqlite3_column_text(ppStmt, 3)));
			contrato.dia = sqlite3_column_int(ppStmt, 4);
			contrato.cliente.tel = std::string(reinterpret_cast<const char*>(sqlite3_column_text(ppStmt, 5)));
			contrato.placa = std::string(reinterpret_cast<const char*>(sqlite3_column_text(ppStmt, 6)));
			contrato.marca = std::string(reinterpret_cast<const char*>(sqlite3_column_text(ppStmt, 7)));
			contrato.linea = std::string(reinterpret_cast<const char*>(sqlite3_column_text(ppStmt, 8)));
			contrato.precio = sqlite3_column_int(ppStmt, 9);
			contrato.lavados = sqlite3_column_int(ppStmt, 10);
			vec.push_back(contrato);
		}
		sqlite3_finalize(ppStmt);
	}
	
	return vec;
}

void sqlite::updateContratos(string column, string donde){
	char consulta[200];
	sprintf(consulta, "UPDATE contratos SET %s %s;", column.c_str(), donde.c_str());
	sqlite3_exec(db, consulta, 0, 0, 0);
}

vector<login_> sqlite::getLogin(){
	string consulta = "SELECT * FROM login;";
	vector<login_> vec;
	login_ log;
	rc = sqlite3_prepare_v2(db, consulta.c_str(), -1, &ppStmt, NULL);
	if(rc == SQLITE_OK){
		while(SQLITE_ROW == sqlite3_step(ppStmt)){
			log.id = sqlite3_column_int(ppStmt, 0);
			log.nombre = std::string(reinterpret_cast<const char*>(sqlite3_column_text(ppStmt, 1)));
			log.pass = std::string(reinterpret_cast<const char*>(sqlite3_column_text(ppStmt, 2)));
			log.nivel = sqlite3_column_int(ppStmt, 3);
			vec.push_back(log);
		}
	}
	
	return vec;
}

vector<dominio_> sqlite::getDominio(){
	string consulta = "SELECT * FROM dominios;";
	vector<dominio_> vec;
	dominio_ dom;
	rc = sqlite3_prepare(db, consulta.c_str(), -1, &ppStmt, NULL);
	if(rc == SQLITE_OK){
		while(SQLITE_ROW == sqlite3_step(ppStmt)){
			dom.id = sqlite3_column_int(ppStmt, 0);
			dom.nombre = std::string(reinterpret_cast<const char*>(sqlite3_column_text(ppStmt, 1)));
			vec.push_back(dom);
		}
	}
	return vec;
}

string sqlite::getNomDominio(int id){
	char consulta[60];
	string dominio = "NULL";
	sprintf(consulta, "SELECT nombre FROM dominios WHERE id = %d", id);
	rc = sqlite3_prepare_v2(db, consulta, -1, &ppStmt, NULL);
	if(rc == SQLITE_OK){
		while(SQLITE_ROW == sqlite3_step(ppStmt)){
			dominio = std::string(reinterpret_cast<const char*>(sqlite3_column_text(ppStmt, 0)));
		}
	}
	
	return dominio;
}
