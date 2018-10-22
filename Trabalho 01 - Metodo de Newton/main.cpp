#include <iostream>
#include <vector>
#include <limits>
#include "Polinomio.h"

using namespace std;

vector<Polinomio> polynomials;
vector<int> multiplicidades;
double precision = 0.0;

void input(void) 
{
	bool deuErro = false;

	do
	{
		system("clear");
		polynomials.clear();
		multiplicidades.clear();
		cout << "Digite a quantidade de reações (polinômios): ";
		int quantidadeReacoes = 0;
		cin >> quantidadeReacoes;
		
		while((!cin) || quantidadeReacoes <= 0)
		{
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
			cout << "Quantidade não está no formato correto. A quantidade deve ser um número inteiro maior ou igual a 1. Digite novamente: ";
			cin >> quantidadeReacoes;	
		}

		system("clear");

		
		vector<double> coefs;
		double c = 0;
		unsigned short int qtd = 0;
		//vector<Polinomio> polins;
		//vector<int> multiplicidades;
		int mul;
		while(qtd < quantidadeReacoes)
		{
			cout << "==== " <<  qtd+1 << "º " << "reação: " << "=====" << endl; 
			for(int i = 0; i < 5; i++)
			{
				cout << "Digite o " << i+1 << "º " << "coeficiente: ";
				cin >> c;
				while(!cin)
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Coeficiente deve ser um número! Digite novamente o " << i+1 << "º " << "coeficiente: ";
					cin >> c;
				}
				coefs.push_back(c);
			}

			cout << endl;
			cout << "Digite a multiplicidade da raiz que você quer encontrar: ";
			cin >> mul;
			while(!cin || mul < 0)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Multiplicidade deve ser um número positivo! Digite novamente: ";
				cin >> mul;
			}
			multiplicidades.push_back(mul);
			polynomials.push_back(Polinomio(4, coefs));
			coefs.clear();
			qtd++;
			system("clear");
		}

		
		cout << "Qual a precisão? (Escolha um número entre 0 e 1): ";
		cin >> precision;
		while(!cin || precision <= 0 || precision >= 1)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Precisão deve ser um número maior do que 0 e menor do que 1! Digite novamente: ";
				cin >> precision;
			}
		system("clear");

		cout << "Informações entradas: " << endl;
		for(int k = 0; k < polynomials.size(); k++)
		{
			cout << "Polinomio " << k+1 << ": " << polynomials[k] << ". Multiplicidade: " << multiplicidades[k] << endl;
		}

		cout << "Precisão: " << precision << endl;

		cout << "Está tudo correto? <s/n>: " << endl;

		char escolha;

		cin >> escolha;

		while(!cin || (escolha != 's' && escolha != 'n') )
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Entrada inválida. Digite 's' caso as informações estejam corretas; digite 'n' caso contrário: ";
			cin >> escolha;
		} 

		if (escolha == 's')
			deuErro = false;
		else
			deuErro = true;

	} while (deuErro);
	
}


vector<Resultado> resultados;

void encontrarRaizes(void)
{
	for (int j = 0; j < polynomials.size(); j++)
	{
		resultados.push_back(polynomials[j].calcularRaizNewtonPolinomios(precision));
		resultados.push_back(polynomials[j].calcularRaizNewtonMultiplicidade(multiplicidades[j], precision));
		resultados.push_back(polynomials[j].calcularRaizSecanteMultiplicidade(precision, multiplicidades[j]));
	}
}

int main(int argc, char const *argv[])
{

	
	

 	// Nova Versão 
	//Sugestão para tabela: percorrer vector de resultados e ir exibindo as informações!
	input();
	encontrarRaizes();

	/*
	for(auto r : resultados)
	{
		cout << "================ " << r.getMetodo() << " ================" << endl;
		cout << "Polinômio calculado: " << r.getPolinomio() << endl;
		cout << "Raiz encontrada: " << r.getRaiz() << endl;
		//cout << "valor do polinômio na raiz encontrada acima: " <<  teste.calcular(result.getRaiz()) << endl;
		cout << "Numero de iterações: " << r.getNumIter() << endl;
		cout << "Chute Inicial: " << r.getChuteInicial() << endl;
		cout << "Deu erro? " << (r.getError() ? "Sim" : "Não") << endl;
		cout << "======================================================================\n" << endl;
	}
	*/


	system("clear");
	
	for (int j = 0; j < resultados.size(); j+=3)
	{
		cout<<j << "=============================================================================================" << endl;
		cout << resultados[j].getPolinomio()<< "             |   Newton p/ Polin. |  Newton p/ Multip.  |  Secante   " << endl;
		cout << "================================================================================================" << endl;
		cout << "Raiz encontrada                    |         " << resultados[j].getRaiz() << "    \t|    \t" << resultados[j+1].getRaiz() << "\t  |        " << resultados[j+2].getRaiz()  << endl;
		cout << "Deu erro?                          |         " << (resultados[j].getError() ? "Sim" : "Nao") << "    \t|    \t" << (resultados[j+1].getError() ? "Sim" : "Nao") << "\t  |        " << (resultados[j+2].getError() ? "Sim" : "Nao")  << endl;
		cout << "Número de iteracoes               |         " << resultados[j].getNumIter() << "    \t|    \t" << resultados[j+1].getNumIter() << "\t  |        " << resultados[j+2].getNumIter()  << endl;
		cout << "Valor do polin. na raiz encontrada |         " << polynomials[j/3].calcular(resultados[j].getRaiz()) << "    \t|    \t" << polynomials[j/3].calcular(resultados[j+1].getRaiz()) << "\t  |        " << polynomials[j/3].calcular(resultados[j+2].getRaiz())  << endl;
		cout << "================================================================================================\n" << endl;
	}





	// Versão Antiga 
	/*
	vector<double> coef {1, -5, 6, 4, -8}; //Coeficiente do polinômio. A primeira posição corresponde ao coeficiente de maior grau. 

	*/try{/*
		Polinomio teste(4, coef);
        	int n=1;
		double precisao,xk_ant,xk_prox;
		double resultado = teste.calcular(2);
		cout << resultado << endl;
		
		/*cout << "Teste:" << teste << endl;
		cout << "P(x) = " << teste << ". " << endl;
		cout << "P(2) = " << resultado << endl;

		Polinomio derivada = teste.gerarDerivada();
		cout << "Derivada de " << teste << ": \n " << derivada << endl;
		cout << "Valor de 2 na derivada: " << derivada.calcular(2) << endl;*
		

		precisao = 0.0001;
		unsigned short int multiplicidade = 3;

		
	

		/* 

						Método da Secante 
		*

		
		Resultado result = teste.calcularRaizSecanteMultiplicidade(precisao,multiplicidade);
		cout << "================ " << result.getMetodo() << " ================" << endl;
		cout << "Polinômio calculado: " << result.getPolinomio() << endl;
		cout << "Raiz encontrada: " << result.getRaiz() << endl;
		cout << "valor do polinômio na raiz encontrada acima: " <<  teste.calcular(result.getRaiz()) << endl;
		cout << "Numero de iterações: " << result.getNumIter() << endl;
		cout << "Chute Inicial: " << result.getChuteInicial() << endl;
		cout << "Deu erro? " << (result.getError() ? "Sim" : "Não") << endl;
		cout << "======================================================================\n" << endl;


		/*
						Método de Newton para multiplicidade
		*
		

		Resultado resul = teste.calcularRaizNewtonMultiplicidade(multiplicidade, precisao);
		cout << "=================" << resul.getMetodo() << " ================" << endl;
		cout << "Polinômio calculado: " << resul.getPolinomio() << endl;
		cout << "Raiz encontrada: " << resul.getRaiz() << endl;
		cout << "valor do polinômio na raiz encontrada acima: " <<  teste.calcular(resul.getRaiz()) << endl;
		cout << "Numero de iterações: " << resul.getNumIter() << endl;
		cout << "Chute Inicial: " << resul.getChuteInicial() << endl;
		cout << "Deu erro? " << (resul.getError() ? "Sim" : "Não") << endl;
		cout << "======================================================================\n" << endl;

		/*
						Método de Newton para polinomios
		*

		Resultado resposta = teste.calcularRaizNewtonPolinomios(precisao);
		cout << "================== " << resposta.getMetodo() << " ==================" << endl;
		cout << "Polinômio calculado: " << resposta.getPolinomio() << endl;
		cout << "Raiz encontrada: " << resposta.getRaiz() << endl;
		cout << "valor do polinômio na raiz encontrada acima: " <<  teste.calcular(resposta.getRaiz()) << endl;
		cout << "Numero de iterações: " << resposta.getNumIter() << endl;
		cout << "Chute Inicial: " << resposta.getChuteInicial() << endl;
		cout << "Deu erro? " << (resposta.getError() ? "Sim" : "Não") << endl;
		cout << "======================================================================\n" << endl;

        
		//=================
		vector <Polinomio> polinomios;
		
		double *p;
		p = (double*) calloc(3,sizeof(double));
		polinomios.push_back(teste);
		int cont=0;
        
        
        
        
		/*
		                              Printa as linhas do quadro comparativo:
		*
		cout << "==============================================================================" << endl;
		cout << "       Polinomio       |  Newnton p/ Polin. |  Newton p/ Multip.  |  Secante   " << endl;
		cout << "==============================================================================" << endl;
		while(cont < n)
		{
		    
		    p = polinomios[cont].getRaizes();
		    cout << polinomios[cont] <<" |         " << p[0] << "         |    \t" << p[1] << "\t  |  " << p[2] << endl;
		    cont++;
		}
		cout << "==============================================================================\n" << endl;
		free(p);*/
		
		/* 
		 * 
		 */
		

	} catch (const char* msg) {
		cerr << msg << endl;
	}


	
	return 0;
}
