#include "Pascoa_comum.h"
#include "Pascoa_MeussJonesButcher.h"

struct tm* calcPascoa_MeussJonesButcher(int ano)
{
	struct tm* pascoa;
	int dia, mes;
	int a = ano%19;
	int b = ano/100;
	int c = ano%100;
	int d = b / 4;
	int e = b%4;
	int f = (b + 8) / 25;
	int g = (b - f + 1) / 3;
	int h = ((19*a) + b - d - g + 15)%30;
	int i = c / 4;
	int k = c%4;
	int l = (32 + (2*e) + (2*i) - h - k)%7;
	int m = (a + (11*h) + (22*l))/451;
	mes = (h + l - (7*m) + 114)/31;
	dia = (h + l - (7*m) + 114)%31 + 1;
	pascoa = constroiData(dia, mes, ano);
	return pascoa;
}