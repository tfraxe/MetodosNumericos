#include <iostream>
#include <vector>
#include "Polinomio.h"
#include "MetodoSecante.h"

using namespace std;

int main(int argc, char const *argv[])
{
	vector<double> coef{ 1, 0, -9, 3}; //Coeficiente do polinômio. A primeira posição corresponde ao coeficiente de maior grau. 
	try{
		Polinomio teste(3, coef);
		double result_secante, precisao,xk_ant,xk_prox;
		double resultado = teste.calcular(2);
		cout << resultado << endl;
		cout << "Teste:" << teste << endl;
		cout << "P(x) = " << teste << ". " << endl;
		cout << "P(2) = " << resultado << endl;

		Polinomio derivada = teste.gerarDerivada();

		cout << "Derivada de " << teste << ": \n " << derivada << endl;

		cout << "Valor de 2 na derivada: " << derivada.calcular(2) << endl;
		precisao = 0.0001;
		xk_ant = -5;
		xk_prox = -3;

		result_secante = metodoSecante(teste,precisao,1,xk_ant,xk_prox);
		cout << "resultado secante =" << result_secante << endl;
		cout << teste.calcular(result_secante) << endl;

	} catch (const char* msg) {
		cerr << msg << endl;
	}


	
	return 0;
}