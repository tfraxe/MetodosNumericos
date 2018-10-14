#include <iostream>
#include <vector>
#include "Polinomio.h"
#include "MetodoSecante.h"

using namespace std;

int main(int argc, char const *argv[])
{
	vector<double> coef{ 1, -5, 6, 4, -8}; //Coeficiente do polinômio. A primeira posição corresponde ao coeficiente de maior grau. 
	try{
		Polinomio teste(4, coef);
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
		unsigned short int multiplicidade = 3;

		
	

		/* 

						Método da Secante 
		*/

		
		result_secante = metodoSecante(teste,precisao,multiplicidade,xk_ant,xk_prox);
		cout << "resultado secante =" << result_secante << endl;
		cout << teste.calcular(result_secante) << endl;



		/*
						Método de Newton para multiplicidade
		*/
		

		Resultado resul = teste.calcularRaizNewtonMultiplicidade(multiplicidade, precisao, 2.15);
		cout << "==========================" << resul.getMetodo() << "==========================" << endl;
		cout << "Polinômio calculado: " << resul.getPolinomio() << endl;
		cout << "Raiz encontrada: " << resul.getRaiz() << endl;
		cout << "valor do polinômio na raiz encontrada acima: " <<  teste.calcular(resul.getRaiz()) << endl;
		cout << "Numero de iterações: " << resul.getNumIter() << endl;
		cout << "Chute Inicial: " << resul.getChuteInicial() << endl;
		cout << "Deu erro? " << (resul.getError() ? "Sim" : "Não") << endl;
		cout << "=================================================================================" << endl;





	} catch (const char* msg) {
		cerr << msg << endl;
	}


	
	return 0;
}