#ifndef __PASCOA_COMUM_
#define __PASCOA_COMUM_

#include <ctime>
#include <memory>
#include <iostream>
#include <sstream>
#include <locale>
#include <iomanip>

using namespace std;

void imprimeData(struct tm* data);
struct tm* constroiData(int dia, int mes, int ano);
bool isDomingo(struct tm* data);
struct tm* proxDomingo(struct tm* data);
struct tm* antDomingo(struct tm* data);

#endif
