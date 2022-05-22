#include "Fecha.h"
#include <iostream>
#include <stdexcept>
#include <time.h>
using namespace std;

void Fecha::setFecha(int inMonth, int inDay, int inYear)
{
	month = inMonth;
	day = inDay;
	year = inYear;
}
void Fecha::mostrarFechaMesDiaAnio()
{
	cout << "mes:" << month << endl;
	cout << "dia:" << day << endl;
	cout << "anio:" << year << endl;
}
void Fecha::mostrarFechaDiaMesAnio()
{
	cout << "dia:" << day << endl;
	cout << "mes:" << month << endl;
	cout << "anio:" << year << endl;
}
void Fecha::mostrarFechasAnioDiaMes()
{
	cout << "anio:" << year << endl;
	cout << "dia:" << day << endl;
	cout << "mes:" << month << endl;
}
void Fecha::mostrarFechasAnioMesDia()
{
	cout << "anio:" << year << endl;
	cout << "mes:" << month << endl; 
	cout << "dia:" << day << endl;
}
void Fecha::mostrarFechasDiaAnioMes()
{
	cout << "dia:" << day << endl;
	cout << "anio:" << year << endl;
	cout << "mes:" << month << endl;
}
void Fecha::mostrarFechasMesAnioDia()
{
	cout << "mes:" << month << endl;
	cout << "anio:" << year << endl;
	cout << "dia:" << day << endl;
}
void Fecha::agregarFechaMesDiaAnio()
{
	int inMonth, inDay, inYear;
	cout << "Ingresa mes:" << endl;
	cin >> inMonth;
	cout << "Ingresa dia:" << endl;
	cin >> inDay;
	cout << "Ingresa anio:" << endl;
	cin >> inYear;
	try {
		validarFecha(inMonth, inDay, inYear);
	}
	catch (invalid_argument& error) {
		cerr << error.what() << endl;
	}
}
void Fecha::agregarFechaDiaMesAnio()
{
	int inMonth, inDay, inYear;
	cout << "Ingresa dia:" << endl;
	cin >> inDay;
	cout << "Ingresa mes:" << endl;
	cin >> inMonth;
	cout << "Ingresa anio:" << endl;
	cin >> inYear;
	try {
		validarFecha(inMonth, inDay, inYear);
	}
	catch (invalid_argument& error) {
		cerr << error.what() << endl;
	}
}
void Fecha::agregarFechasAnioDiaMes()
{
	int inMonth, inDay, inYear;
	cout << "Ingresa anio:" << endl;
	cin >> inYear;
	cout << "Ingresa dia:" << endl;
	cin >> inDay;
	cout << "Ingresa mes:" << endl;
	cin >> inMonth;
	try {
		validarFecha(inMonth, inDay, inYear);
	}
	catch (invalid_argument& error) {
		cerr << error.what() << endl;
	}
}
void Fecha::agregarFechasAnioMesDia()
{
	int inMonth, inDay, inYear;
	cout << "Ingresa anio:" << endl;
	cin >> inYear;
	cout << "Ingresa mes:" << endl;
	cin >> inMonth;
	cout << "Ingresa dia:" << endl;
	cin >> inDay;
	try {
		validarFecha(inMonth, inDay, inYear);
	}
	catch (invalid_argument& error) {
		cerr << error.what() << endl;
	}
}
void Fecha::agregarFechasDiaAnioMes()
{
	int inMonth, inDay, inYear;
	cout << "Ingresa dia:" << endl;
	cin >> inDay;
	cout << "Ingresa anio:" << endl;
	cin >> inYear;
	cout << "Ingresa mes:" << endl;
	cin >> inMonth;
	try {
		validarFecha(inMonth, inDay, inYear);
	}
	catch (invalid_argument& error) {
		cerr << error.what() << endl;
	}
}
void Fecha::agregarFechasMesAnioDia()
{
	int inMonth, inDay, inYear;
	cout << "Ingresa mes:" << endl;
	cin >> inMonth;
	cout << "Ingresa anio:" << endl;
	cin >> inYear;
	cout << "Ingresa dia:" << endl;
	cin >> inDay;
	try {
		validarFecha(inMonth, inDay, inYear);
	}
	catch (invalid_argument& error) {
		cerr << error.what() << endl;
	}
}
void Fecha::validarFecha(int inMonth, int inDay, int inYear)
{
	if (inMonth >= 1 && inMonth <= 12 && inDay >= 1 && inDay <= 31 && inYear >= 1 && inYear <= 2100) {
		if (inMonth == 1 || inMonth == 3 || inMonth == 5 || inMonth == 7 || inMonth == 8 || inMonth == 10 || inMonth == 12) 
			setFecha(inMonth, inDay, inYear);
		else if (inMonth == 2) {
			if (inYear % 4 == 0) {
				if (inDay <= 29)
					setFecha(inMonth, inDay, inYear);
				else
					throw invalid_argument("fecha no valida");
			}
			else
			{
				if (inDay <= 28)
					setFecha(inMonth, inDay, inYear);
				else
					throw invalid_argument("fecha no valida");
			}
		}
		else {
			if(inDay==31)
				throw invalid_argument("fecha no valida");
			else
				setFecha(inMonth, inDay, inYear);
		}
	}
	else
		throw invalid_argument("fecha no valida");
}

void Fecha::fechaSystema()
{
	time_t tiempo;
	struct tm tlocal;
	time(&tiempo);
	localtime_s(&tlocal, &tiempo);
	setFecha(tlocal.tm_mon + 1,tlocal.tm_mday,tlocal.tm_year + 1900);
}
