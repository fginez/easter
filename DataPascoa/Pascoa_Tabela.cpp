// DataPascoa.cpp : Defines the entry point for the console application.
//

#include "Pascoa_comum.h"
#include "Pascoa_Tabela.h"

using namespace std;

// Tabela de correspondencia de datas para o numero dourado
// Valida até 2099
int lookupDatas[][2] = {{14, 4},	// 1
						{ 3, 4},	// 2
						{23, 3},	// 3
						{11, 4},	// 4
						{31, 3},	// 5
						{18, 4},	// 6
						{ 8, 4},	// 7
						{28, 3},	// 8
						{16, 4},	// 9
						{ 5, 4},	// 10
						{25, 3},	// 11
						{13, 4},	// 12
						{ 2, 4},	// 13
						{22, 3},	// 14
						{10, 4},	// 15
						{30, 3},	// 16
						{17, 4},	// 17
						{ 7, 4},	// 18
						{27, 3}};	// 19				

int calcNumDourado(int ano)
{
	return (ano%19)+1;
}


struct tm* calcPascoa_Tabela(int ano)
{
	struct tm* pascoa;
	int mes;
	int dia;
	int aureusNum = calcNumDourado(ano);
	dia = lookupDatas[aureusNum-1][0];
	mes = lookupDatas[aureusNum-1][1];
	pascoa=constroiData(dia, mes, ano);
	pascoa=proxDomingo(pascoa);		
	return pascoa;
}

