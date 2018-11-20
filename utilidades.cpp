#include <iostream>
#include "utilidades.h"

using namespace std;

int eleva10(int expo){
	int ret = 1;
	for(int i=0; i<expo; i++){
		ret *= 10;
	}
	return ret;
}

int convertToInt(string num){
	int ret, aux;
	
	ret = (int)num[num.size()-1] - 48;
	for(int i = num.size()-2, cont = 1; i>=0; i--, cont++){
		aux = ((int)num[i] - 48) * eleva10(cont);
		ret += aux;
	}
	
	return ret;
}

string convertToString(int n){
	stringstream str;
	str << n;
	return str.str();
}

string fecha(){
	char output[11];
	time_t fecha = time(NULL);
	struct tm *tlocal = localtime(&fecha);
	strftime(output, 10, "%d/%m/%y", tlocal);
	return output;
}

int getDia(){
	string dia = fecha();
	string aux = dia.substr(0,2);
	if(aux[0] == '0') return convertToInt(aux.substr(1,1));
	else return convertToInt(aux);
}

int getMes(){
	string mes = fecha();
	string aux = mes.substr(3,2);
	if(aux[0] == '0') return convertToInt(aux.substr(1,1));
	else return convertToInt(aux);
}

bool rango(char l){
	int val = int(l);
	if((val > 47 && val < 58) || (val > 64 && val < 91) || (val > 96 && val < 123)) return true;
	return false;
}

bool cPrecio(char p){
	if(p > 47 && p < 58) return true;
	return false;
}

bool cPrecio(string p){
	bool flag = false;
	for(int i=0; i<(int)p.size(); i++){
		if(cPrecio(p[i])) flag = true;
		else return false;
	}
	
	return flag;
}

bool cPlaca(string p){
	int tamanio = p.length();
	int num = 0;
	
	if(tamanio < 7){
		for(int i=0; i<tamanio; i++){
			if(cPrecio(p[i])) num++;
			if(!rango(p[i])) return true;
		}
	}else return true;
	
	if(num > 3 || num < 3) return true;
	
	return false;
}

vector<string> palabra(string palabra){
	int cont = 0;
	vector<string> vec;
	
	for(int i=0; i<(int)palabra.size(); i++){
		if(palabra[i] != ' '){
			for(int j=i; j<(int)palabra.size(); j++){
				if(palabra[j] == ' '){
					cont = j-i;
					break;
				}
				cont++;
			}
			vec.push_back(palabra.substr(i, cont));
			i += cont;
		}
	}
	
	return vec;
}

bool isRang(string rang){
	//retorna true si el parametro rang tiene el este formato 11-88
	for(int i=0; i<(int)rang.size(); i++){
		if(cPrecio(rang[i]) || (rang[i] == '-')) continue;
		else return false;
	}
	return true;
}

int getrang(string rang, int ret){
	int one = 0, two = 0;
	string num;
	bool flag = true;
	
	for(int i=0; i<(int)rang.size(); i++){
		if(cPrecio(rang[i]) && flag){
			num.push_back(rang[i]);
		}
		
		if(rang[i] == '-'){
			flag = false;
			one = convertToInt(num);
			num.clear();
		}
		
		if(cPrecio(rang[i]) && !flag){
			num.push_back(rang[i]);
		}		
	}
	
	two = convertToInt(num);
	
	(ret == 1)?(ret = one):(ret = two);
	
	return ret;
}

bool mayor(int one, int two){
	return one > two;
}

string buscarservicio(string frace, string buscar, string remplazo){
	int pos = frace.find(buscar);
	sqlite db("data.db");
	
	while(pos != -1){
		frace.replace(pos, buscar.size(), remplazo);
		pos = frace.find(buscar, pos + remplazo.size());
	}
	
	if(db.ifExistServicio(frace)) return frace;
	else return "NULL";
}


bool ifExistDia(string dia){
	for(int i=0; i<DIAS; i++){
		if(dia == diaSemana[i]) return true;
	}
	
	return false;
}

int getIdDia(string dia){
	for(int i=0; i<DIAS; i++){
		if(dia == diaSemana[i]) return day(i);
	}
	
	return DOMINGO;
}

string wxStringToString(wxString text){
	string ret;
	ret = text.mb_str();
	return ret;
}

tm strFecha(){
	time_t now = time(nullptr);
	tm* tiempo = localtime(&now);
	tm ret;
	
	ret.tm_hour = tiempo->tm_hour;
	ret.tm_isdst = tiempo->tm_isdst;
	ret.tm_mday = tiempo->tm_mday;
	ret.tm_min = tiempo->tm_min;
	ret.tm_mon = tiempo->tm_mon;
	ret.tm_sec = tiempo->tm_sec;
	ret.tm_wday = tiempo->tm_wday;
	ret.tm_yday = tiempo->tm_yday;
	ret.tm_year = tiempo->tm_year;
	return ret;
}
