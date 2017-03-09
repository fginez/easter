#include "Pascoa_comum.h"
#include "Pascoa_Gauss.h"

void getValores_Gauss(const unsigned int ano, unsigned int* x, unsigned int* y)
{
	if ( 1582 <= ano && 1699 >= ano ) {
		*x = 22;
		*y = 2;
	}
	else if ( 1700 <= ano && 1799 >= ano ) {
		*x = 23;
		*y = 3;
	}
	else if ( 1800 <= ano && 1899 >= ano ) {
		*x = 23;
		*y = 4;
	}
	else if ( 1900 <= ano && 2099 >= ano ) {
		*x = 24;
		*y = 5;
	}
	else if ( 2100 <= ano && 2199 >= ano ) {
		*x = 24;
		*y = 6;
	}
	else if ( 2200 <= ano && 2299 >= ano ) {
		*x = 25;
		*y = 7;
	}
	else {
		*x = 0;
		*y = 0;
	}
}

struct tm* calcPascoa_Gauss(int ano)
{
	struct tm* pascoa;
	unsigned int dia, mes, x, y;

	getValores_Gauss(ano, &x, &y);

	int a = ano % 19;
	int b = ano % 4;
	int c = ano % 7;
	int d = ((19*a)+x)%30;
	int e = ((2*b)+(4*c)+(6*d)+y)%7;
	int f = d+e;

	// Verifica excessoes
	if ((29==d) && (6==e)) {
		dia=19;
		mes=4;
	} else if ( (28==d) && (6==e) && (19 > ((11*x)+11)%30) ) {
		dia=18;
		mes=4;
	} else {
		if ( f < 10 ) { 
			dia = 22 + f;
			mes = 3;
		} else {
			dia = f - 9;
			mes = 4;
		}
	}

	pascoa = constroiData(dia, mes, ano);

	return pascoa;
}
