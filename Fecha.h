#pragma once
class Fecha
{
private:
	int day, month, year;
public:
	Fecha(int inMonth, int inDay, int inYear) :month(inMonth), day(inDay), year(inYear) {};
	Fecha operator ++() {
		++day;
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10) {
			if (day == 32) {
				day = 1;
				++month;
			}
		}
		else if (month == 12) {
			if (day == 32) {
				day = 1;
				month = 1;
				++year;
			}
		}
		else if (month == 2) {
			if (year % 4 == 0) {
				if (day == 29) {
					day = 1;
					++month;
				}
			}
			else
				if (day == 29) {
					day = 1;
					++month;
				}
		}
		else {
			if (day == 31) {
				day = 1;
				++month;
			}
		}
		return *this;
	}
	Fecha operator --() {
		--day;
		if (month == 4 || month == 6 || month == 9 || month == 11 ) {
			if (day == 0) {
				day = 31;
				--month;
			}
		}
		else if (month == 1) {
			if (day == 0) {
				day = 31;
				month = 12;
				--year;
			}
		}
		else if (month == 3) {
			if (year % 4 == 0) {
				if (day == 0) {
					day = 29;
					--month;
				}
			}
			else
				if (day == 0) {
					day = 28;
					--month;
				}
		}
		else {
			if (day == 0) {
				day = 31;
				--month;
			}
		}
		return *this;
	}
	void setFecha(int inMonth, int inDay, int inYear);
	void mostrarFechaMesDiaAnio();
	void mostrarFechaDiaMesAnio();
	void mostrarFechasAnioDiaMes();
	void mostrarFechasAnioMesDia();
	void mostrarFechasDiaAnioMes();
	void mostrarFechasMesAnioDia();
	void agregarFechaMesDiaAnio();
	void agregarFechaDiaMesAnio();
	void agregarFechasAnioDiaMes();
	void agregarFechasAnioMesDia();
	void agregarFechasDiaAnioMes();
	void agregarFechasMesAnioDia();
	void validarFecha(int inMonth, int inDay, int inYear);
	void fechaSystema();
};

