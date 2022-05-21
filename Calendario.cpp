#include "Calendario.h"
#include "Fecha.h"
#include <iostream>
using namespace std;

Calendario::Calendario()
{
	id = 1;
	ciclo = 1;
	vuelta = 0;
	opcion = 1;
}

void Calendario::mostrarCalendario()
{	
	Fecha fechaDate(5,21,2022);
	cout << "numero de calendario:" << id << endl;
	while (ciclo != 0) {
		cout << "1.-AGREGAR FECHA\n2.-MOSTRAR FECHA\n3.-AUMENTAR DIA\n4.-RESTAR DIA\n5.-FECHA DEL SISTEMA" << endl;
		cin >> opcion;
		switch (opcion) {
		case 1:
			cout << "1.-Formato DD/MM/YYYY 2.-Formato MM/DD/YYYY" << endl;
			cin >> vuelta;
			if (vuelta == 1)
				fechaDate.agregarFechaDia();
			else if (vuelta == 2)
				fechaDate.agregarFechaMes();
			else
				cout << "Formato no valido";
			break;
		case 2:
			cout << "1.-Formato DD/MM/YYYY 2.-Formato MM/DD/YYYY" << endl;
			cin>>vuelta;
			if (vuelta == 1)
				fechaDate.mostrarFechaDia();
			else if (vuelta == 2)
				fechaDate.mostrarFechaMes();
			else
				cout << "Formato no valido";
			break;
		case 3:
			++fechaDate;
			break;
		case 4:
			--fechaDate;
			break;
		case 5:
			fechaDate.fechaSystema();
			break;
		default:
			cout << "Opcion invalida" << endl;
		}
		cout << "0 Salir 1 Continuar" << endl;
		cin >> ciclo;
	}
}
