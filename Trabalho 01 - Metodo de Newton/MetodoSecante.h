#include <iostream>
#include <cmath>
//#include "Polinomio.h"

using namespace std;

double metodoSecante(Polinomio funcao, double precisao,unsigned short int p, double xk_anterior, double xk_atual)
{
	cout << xk_atual<< endl;
	double dividendo,divisor,xk_prox,condicao;

	condicao = (xk_anterior - xk_atual);

	if(condicao < 0) condicao = condicao*(-1);
	if(condicao < precisao )
	{
		return xk_atual;
	}

	xk_prox = xk_atual - ((p*funcao.calcular(xk_atual)*(xk_atual - xk_anterior))/(funcao.calcular(xk_atual) - funcao.calcular(xk_anterior)));
	metodoSecante(funcao, precisao, p, xk_atual,xk_prox);



}
