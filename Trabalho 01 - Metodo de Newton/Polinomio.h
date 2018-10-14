#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>

using namespace std;


class Resultado 
{
private:
	double raiz;
	unsigned short int numIter;
	bool error;
	double chuteInicial;
	string polinomio;
	string metodo;
public:
	Resultado()
	{
		raiz = 0.0;
		numIter = 0.0;
		error = false;
		chuteInicial = 0.0;
		polinomio = "";
		metodo = "";
	}


	void setRaiz(double r)
	{
		this->raiz = r;
	}

	void setNumIter(double n)
	{
		this->numIter = n;
	}

	void setError (bool e)
	{
		this->error = e;
	}

	void setChuteInicial (double c)
	{
		this->chuteInicial = c;
	}

	void setPolinomio (string p)
	{
		this->polinomio = p;
	}

	void setMetodo(string m)
	{
		this->metodo = m;
	}


	double getRaiz(void)
	{
		return this->raiz;
	}

	unsigned short int getNumIter(void)
	{
		return this->numIter;
	}

	bool getError (void)
	{
		return this->error;
	}

	double getChuteInicial (void)
	{
		return this->chuteInicial;
	}

	string getPolinomio (void)
	{
		return this->polinomio;
	}

	string getMetodo(void)
	{
		return this->metodo;
	}




};





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
			if(p.coeficientes[p.grau - g] != 0) {

				if(p.coeficientes[p.grau - g] != 1)
					out << p.coeficientes[p.grau - g] << "x";
				else
					out << "x";

				if(g > 1) 
					out << "^" << g << " ";
				else
					out << " ";

			}

			if (g != 0 && p.coeficientes[p.grau-g + 1] > 0)
				out << "+" << "";

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


	Resultado calcularRaizNewtonMultiplicidade(unsigned short int p, double precisao, double guess)
	{
		Resultado resultado;
		stringstream polinomio;
		polinomio << *this;
		resultado.setPolinomio(polinomio.str());
		resultado.setChuteInicial(guess);
		resultado.setMetodo("Método de Newton para Multiplicidade");
		

		unsigned short int numIter = 0;
	
		Polinomio derivada = this->gerarDerivada();

		double currentValue = guess;

		double nextValue;



		while (numIter < 1000)
		{
			
			nextValue = currentValue - p* this->calcular(currentValue)/derivada.calcular(currentValue);


			if (abs(nextValue - currentValue) < precisao){
				resultado.setRaiz(nextValue);
				resultado.setNumIter(numIter + 1);
				resultado.setError(false);

				return resultado;

			}


			currentValue = nextValue;
			numIter++;
		} 

		resultado.setRaiz(0.0);
		resultado.setNumIter(numIter + 1);
		resultado.setError(true);
		return resultado;

	}

	


};