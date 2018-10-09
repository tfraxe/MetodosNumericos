#include <iostream>
#include <vector>
#include "Polinomio.h"

using namespace std;

int main(int argc, char const *argv[])
{
	vector<double> coef{1, 1, 2, 2.5, 4.57}; //Coeficiente do polinômio. A primeira posição corresponde ao coeficiente de maior grau. 
	try{
		Polinomio teste(4, coef);
		double resultado = teste.calcular(2);
		cout << resultado << endl;
		cout << teste;
		cout << "P(x) = " << teste << ". " << "P(2) = " << resultado << endl;

		Polinomio derivada = teste.gerarDerivada();

		cout << "Derivada de " << teste << ": " << derivada << endl;

		cout << "Valor de 2 na derivada: " << derivada.calcular(2) << endl;
	} catch (const char* msg) {
		cerr << msg << endl;
	}


	
	return 0;
}