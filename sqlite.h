#ifndef SQLITE_H
#define SQLITE_H

#include <sqlite3.h>
#include <iostream>
#include <vector>
#include <string.h>
#include "utilidades.h"

const int NTABLAS = 9;
const int ROOT    = 0;
const int ADMIN   = 1;
const int USUARIO = 2;

struct empleados_{
	int id;
	std::string nombre;
	std::string tel;
};

struct servicios_{
	int id;
	std::string tipo;
	int valor;
};

struct registro_{
	int id;
	int mes;
	int dia;
	std::string placa;
	std::string servicio;
	int empleado;
	int precio;
};

struct mes_{
	int id;
	std::string mes;
	std::string abrev;
};

struct retiro_{
	int id;
	int mes;
	int dia;
	std::string descripcion;
	int monto;
};

struct cliente_{
	int id;
	std::string nombre;
	std::string tel;
	std::string email;
	int idemail;
};

struct contratos_{
	int id;
	int precio;
	int dia;
	int lavados;
	cliente_ cliente;
	std::string direccion, placa, marca, linea;
};

struct login_{
	int id;
	std::string nombre;
	std::string pass;
	int nivel;
};

struct dominio_{
	int id;
	std::string nombre;
};

class sqlite {
	sqlite3* db;
	sqlite3_stmt* ppStmt;
	int rc;
	void llenarMeses();
public:
	sqlite(std::string nom);
	~sqlite();
	void creartablas();
	void insertEmpleados(std::string nom, std::string tel);
	void insertServicioas(std::string tipo, int valor);
	void insertRegistro(int mes, int dia, std::string placa, std::string servicio, int empleado, int precio);
	void insertMes(std::string mes, std::string abrev);
	void insertRetiro(int _mes, int _dia, std::string _descripcion, int _monto);
	void insertCliente(std::string columnas, std::string values);
	void insertContrato(std::string valores);
	void insertLogin(std::string nombre, std::string pass, int nivel);
	void insertDominio(std::string nombre);
	std::vector<empleados_> getEmpleados();
	int getIdEmpleado(std::string em);
	std::string getEmpleado(int em);
	std::vector<servicios_> getServicios();
	std::vector<registro_> getRegistro(int _d, int _m);
	mes_ getMes(std::string m);
	std::vector<mes_> getMeses();
	std::vector<registro_> consulta(std::string where);
	std::vector<retiro_> getretiro(std::string where);
	std::vector<contratos_> getContrato();
	bool ifExistEmpleado(std::string em, bool flag = false);
	bool ifExistServicio(std::string ser);
	bool ifExistMes(std::string me);
	int getPrecioServicio(std::string ser);
	std::vector<cliente_> getClientes();
	std::vector<contratos_> getClientesDay(std::string dia);
	void updateContratos(std::string column, std::string donde);
	int getRc(){return rc;};
	std::string errmsg(){return std::string(reinterpret_cast<const char*>(sqlite3_errmsg(db)));};
	std::vector<login_> getLogin();
	std::vector<dominio_> getDominio();
	std::string getNomDominio(int id);
};

#endif

