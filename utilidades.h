#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <iostream>
#include <sstream>
#include <ctime>
#include <vector>
#include "sqlite.h"
#include <wx/string.h>

enum day{
	DOMINGO,
	LUNES,
	MARTES,
	MIERCOLES,
	JUEVES,
	VIERNES,
	SABADO
};

const char diaSemana[6][10] ={"Lun", "Mar", "Mie", "Jue", "Vie", "Sab"};
const int DIAS = 6;

int eleva10(int expo);
int convertToInt(std::string num);
std::string convertToString(int n);
std::string fecha();
int getDia();
int getMes();
bool rango(char l);
bool cPrecio(char p);
bool cPrecio(std::string p);
bool cPlaca(std::string p);
std::vector<std::string> palabra(std::string palabra);
bool isRang(std::string rang);
int getrang(std::string rang, int ret = 1); 
bool mayor(int one, int two);
std::string buscarservicio(std::string frace, std::string buscar, std::string remplazo);
bool ifExistDia(std::string dia);
int getIdDia(std::string dia);
std::string wxStringToString(wxString text);
tm strFecha();
#endif

