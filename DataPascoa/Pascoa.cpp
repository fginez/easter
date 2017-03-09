/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Calculo da data da Pascoa (Easter's date calculation)
// Fernando Ginez da Silva - fginez AT gmail dot com
//
// Aplicativo do momento 'having fun' - calcula a data da pascoa, de acordo com o ano, por três diferentes
// algoritmos: lookup table, Gauss e Meuss/Jones/Butcher.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "Pascoa_comum.h"
#include "Pascoa_Gauss.h"
#include "Pascoa_MeussJonesButcher.h"
#include "Pascoa_Tabela.h"

int main(int argc, char* argv[])
{
	int ano;
	if ( argc > 1 ) {
		ano = atoi(argv[1]);
		cout << "Ano: " << ano << endl;
		cout << "Tabela: ";
		imprimeData(calcPascoa_Tabela(ano));
		cout << "Gauss: ";
		imprimeData(calcPascoa_Gauss(ano));
		cout << "Meuss/Jones/Butcher: ";
		imprimeData(calcPascoa_MeussJonesButcher(ano));
	} else {
		for (ano=1970;ano<2099;ano++) {
			cout << ano << ": t=";
			imprimeData(calcPascoa_Tabela(ano));
			cout << " g=";
			imprimeData(calcPascoa_Gauss(ano));
			cout << " m=";
			imprimeData(calcPascoa_MeussJonesButcher(ano));
			cout << endl;
		}
	}

	return 0;
}