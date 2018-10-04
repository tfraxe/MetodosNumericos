#include <iostream>
#include <vector>
#include "Polinomio.h"

using namespace std;

int main(int argc, char const *argv[])
{
	vector<double> coef{1, 1, 2}; //Coeficiente do polinômio. A primeira posição corresponde ao coeficiente de maior grau. 
	try{
		Polinomio teste(2, coef);
		double resultado = teste.calcular(2);
		cout << resultado << endl;
		cout << teste;
		cout << "P(x) = " << teste << ". " << "P(2) = " << resultado << endl;
	} catch (const char* msg) {
		cerr << msg << endl;
	}


	
	return 0;
}