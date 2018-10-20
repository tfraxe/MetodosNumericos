#include <iostream>
#include <vector>
#include "Polinomio.h"

using namespace std;

int main(int argc, char const *argv[])
{
	vector<double> coef {1, -5, 6, 4, -8}; //Coeficiente do polinômio. A primeira posição corresponde ao coeficiente de maior grau. 
	try{
		Polinomio teste(4, coef);
        int n=1;
		double precisao,xk_ant,xk_prox;
		double resultado = teste.calcular(2);
		cout << resultado << endl;
		cout << "Teste:" << teste << endl;
		cout << "P(x) = " << teste << ". " << endl;
		cout << "P(2) = " << resultado << endl;

		Polinomio derivada = teste.gerarDerivada();

		cout << "Derivada de " << teste << ": \n " << derivada << endl;

		cout << "Valor de 2 na derivada: " << derivada.calcular(2) << endl;
		

		precisao = 0.0001;
		unsigned short int multiplicidade = 3;

		
	

		/* 

						Método da Secante 
		*/

		
		Resultado result = teste.calcularRaizSecanteMultiplicidade(precisao,multiplicidade);
		cout << "==========================" << result.getMetodo() << "==========================" << endl;
		cout << "Polinômio calculado: " << result.getPolinomio() << endl;
		cout << "Raiz encontrada: " << result.getRaiz() << endl;
		cout << "valor do polinômio na raiz encontrada acima: " <<  teste.calcular(result.getRaiz()) << endl;
		cout << "Numero de iterações: " << result.getNumIter() << endl;
		cout << "Chute Inicial: " << result.getChuteInicial() << endl;
		cout << "Deu erro? " << (result.getError() ? "Sim" : "Não") << endl;
		cout << "=================================================================================" << endl;


		/*
						Método de Newton para multiplicidade
		*/
		

		Resultado resul = teste.calcularRaizNewtonMultiplicidade(multiplicidade, precisao, 1.5);
		cout << "==========================" << resul.getMetodo() << "==========================" << endl;
		cout << "Polinômio calculado: " << resul.getPolinomio() << endl;
		cout << "Raiz encontrada: " << resul.getRaiz() << endl;
		cout << "valor do polinômio na raiz encontrada acima: " <<  teste.calcular(resul.getRaiz()) << endl;
		cout << "Numero de iterações: " << resul.getNumIter() << endl;
		cout << "Chute Inicial: " << resul.getChuteInicial() << endl;
		cout << "Deu erro? " << (resul.getError() ? "Sim" : "Não") << endl;
		cout << "=================================================================================" << endl;

		/*
						Método de Newton para polinomios
		*/

		Resultado resposta = teste.calcularRaizNewtonPolinomios(precisao);
		cout << "==========================" << resposta.getMetodo() << "==========================" << endl;
		cout << "Polinômio calculado: " << resposta.getPolinomio() << endl;
		cout << "Raiz encontrada: " << resposta.getRaiz() << endl;
		cout << "valor do polinômio na raiz encontrada acima: " <<  teste.calcular(resposta.getRaiz()) << endl;
		cout << "Numero de iterações: " << resposta.getNumIter() << endl;
		cout << "Chute Inicial: " << resposta.getChuteInicial() << endl;
		cout << "Deu erro? " << (resposta.getError() ? "Sim" : "Não") << endl;
		cout << "=================================================================================" << endl;

        
        //=================
        vector <Polinomio> polinomios;
        
        double *p;
        p = (double*) calloc(3,sizeof(double));
        polinomios.push_back(teste);
        int cont=0;
        
        
        
        
        /*
            Printa as linhas do quadro comparativo:
         */
        
        cout<<"          Polinomio             " << "Newnton" << " | " << "Nm" <<  " | "<< "Sec" << endl; 
        while(cont < n)
        {
            
            p = polinomios[cont].getRaizes();
            cout<< polinomios[cont]<<" | " << p[0] << " | " << p[1] << " | " << p[2] << endl;
            cont++;
        }
        free(p);
        
        /*
         * 
         */
        

	} catch (const char* msg) {
		cerr << msg << endl;
	}


	
	return 0;
}
