#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Polinomio {

private:
	unsigned short int grau;
	vector<double> coeficientes;
public:
	Polinomio(unsigned short int g, vector<double>& c)
	{
		if (g <= 0)
			throw "Polinomio nao pode ser de grau menor do que 0!";

		if (c.size() != g+1)
			throw "Quantidade de coeficientes não corresponde ao grau do polinomio";
		coeficientes = c;
		grau = g;
	}

	friend ostream& operator << (ostream& out, const Polinomio& p)
	{

		for(int g = p.grau; g > 0; g--)
		{
			out << p.coeficientes[p.grau - g] << "x^" << g << "";

			if (g != 0)
				out << " + " << "";
		}

		out << p.coeficientes[p.grau];
		return out;
	}

	double calcular(double x) //Calcula valor do polinômio para um certo valor x
	{
		double resultado = 0;

		for (int i = 0; i < this->grau + 1; i++)
		{
			resultado *= x;
			resultado += this->coeficientes[i];
		}

		return resultado;
	}


	Polinomio gerarDerivada(void) const
	{
		vector<double> novosCoeficientes;
		unsigned short int novoGrau = this->grau - 1;

		for(int i = 0; i <= novoGrau; i++)
		{
			novosCoeficientes.push_back(this->coeficientes[i] * (this->grau - i));
		}

		return Polinomio(novoGrau, novosCoeficientes);

	}


};