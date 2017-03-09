#include "Pascoa_comum.h"

void imprimeData(struct tm* data)
{
	cout << data->tm_mday << "/" << data->tm_mon+1 << "/" << data->tm_year+1900;
}

struct tm* constroiData(int dia, int mes, int ano)
{
	tm* t = new tm;
	memset(t, 0, sizeof(struct tm));
	string d=to_string(dia);
	string m=to_string(mes);
	string a=to_string(ano);

	istringstream ss(d+"-"+m+"-"+a);
	ss >> get_time(t, "%d-%m-%Y");
	if ( ss.fail() )
		cout << "Falha no parsing";

	time_t t2 = mktime(t);
	tm* t3 = localtime(&t2);
	delete t;
	return t3;
}

bool isDomingo(struct tm* data) 
{
	return (0 == data->tm_wday?true:false);
}

struct tm* proxDomingo(struct tm* data)
{
	time_t t = 3600 * 24; // um dia em segundos
	t = t*(7-data->tm_wday) + mktime(data);
	return localtime(&t);
}

struct tm* antDomingo(struct tm* data)
{
	time_t t = 3600 * 24; // um dia em segundos
	t = (-1)*t*(7-data->tm_wday) + mktime(data);
	return localtime(&t);
}