#include <iostream>
#include "sistemas.h"

using namespace std;

void SistemasEquacoes::solucaoFatoracaoLU(Matriz A, Matriz b)
{
    int linhas = A.getQuantLinhas();
    int colunas = A.getQuantColunas();
    Matriz L(linhas, colunas);
    Matriz U(linhas, colunas);
    Matriz P(linhas, colunas);
    for(int i = 0; i < linhas; i++)
    {
        L.setElemento(i, i, 1);
        P.setElemento(i, i, 1);
    }
    for(int i = 0; i < linhas; i ++)
        for(int j = 0; j < colunas; j++)
            U.setElemento(i, j, A.getElemento(i, j));
    for(int k = 0; k < colunas; k++)
    {
        double pivo = abs(U.getElemento(k, k));
        int r = k;
        for(int i = k + 1; i < linhas; i++)
        {
            double valor = abs(U.getElemento(i, k));
            if(valor > pivo)
            {
                pivo = valor;
                r = i; 
            }
        }
        if(pivo == 0)
            break;
        if(r != k)
        {
            U.trocarLinha(k, r);
            P.trocarLinha(k, r);
        }
        for(int i = k + 1; i < linhas; i++)
        {
            double m = U.getElemento(i, k) / U.getElemento(k, k);
            L.setElemento(i, k, m);
            for(int j = k; j < colunas; j++)
            {
                double valor = U.getElemento(i, j);
                U.setElemento(i, j, valor - (m * U.getElemento(k, j)));
            }        
        }    
    }
    Matriz c = Matriz::multiplicar(P, b);
    Matriz y(linhas, 1);
    for(int i = 0; i < linhas; i++)
    {
        double soma = 0;
        for(int j = 0; j < i; j++)
            soma += (L.getElemento(i, j) * y.getElemento(j, 0));
        y.setElemento(i, 0, c.getElemento(i, 0) - soma);
    }
    Matriz x(linhas, 1);
    for(int i = linhas - 1; i >= 0; i--)
    {
        double soma = 0;
        for(int j = i + 1; j < linhas; j++)
            soma += (U.getElemento(i, j) * x.getElemento(j, 0));
        x.setElemento(i, 0, (y.getElemento(i, 0) - soma) / U.getElemento(i, i));
    }
    A.printMatriz("\nMatriz A");
    b.printMatriz("\nMatriz b");
    x.printMatriz("\nMatriz solucao x");
    Matriz resultado = Matriz::multiplicar(A, x);
    resultado.printMatriz("\nMatriz Ax");
}

void SistemasEquacoes::solucaoDoolittle(Matriz A, Matriz b)
{

    //Fatoração LU usando Redução de Doolittle

    int linhas = A.getQuantLinhas();
    int colunas = A.getQuantColunas();

    Matriz L(linhas, colunas); //Lower triangle matrix
    Matriz U(linhas, colunas); //Upper triangle matrix

    for(int i = 0; i < linhas; i++)
        L.setElemento(i, i, 1);      


    for (int k = 0; k < linhas; k++) {
        
        for(int m = k; m < linhas; m++) {

            int soma = 0;
            
            for (int j = 0; j < k; j++) {
                soma += L.getElemento(k, j) * U.getElemento(j, m); 
            }

            U.setElemento(k, m, (A.getElemento(k, m) - soma));

        }

        for(int i = k+1; i < linhas; i++) {
            
            if(i != k) {
                
                int soma2 = 0;

                for (int j = 0; j < k; j++) {
                    soma2 += L.getElemento(i, j) * U.getElemento(j, k);
                }

                if(U.getElemento(k, k) == 0) 
                {
                    cout << "Doolittle não conseguiu encontrar solução para o sistema\n";
                    exit(1);
                }

                L.setElemento(i, k, (A.getElemento(i, k) - soma2) / U.getElemento(k, k));
            }

        }
    }



    // Resolvendo sistema de equações usando substituições sucessivas e retroativas

    Matriz y(linhas, 1);
    Matriz x(linhas, 1);

    //Resolvendo Ly = b
    y.setElemento(0, 0, b.getElemento(0, 0));

    for (int l = 1; l < linhas; l++) {
        int somaAnteriores = 0;

        for (int j = 0; j < l; j++) {
            somaAnteriores += L.getElemento(l, j) * y.getElemento(j, 0);
        }

        y.setElemento(l, 0, b.getElemento(l, 0) - somaAnteriores);
    }

    
    //Resolvendo Ux = y


    if (U.getElemento(linhas - 1, colunas - 1) == 0)
    {
        cout << "Doolittle não conseguiu encontrar solução para o sistema\n";
        exit(1);
    }
    
    x.setElemento(linhas - 1, 0, y.getElemento(linhas - 1, 0) / U.getElemento (linhas - 1, colunas - 1));

    
    
    for (int l = linhas - 2; l >= 0; l--) {

        int somaPosteriores = 0;

        for (int j = l+1; j < linhas; j++) {
            somaPosteriores += U.getElemento(l, j) * x.getElemento(j, 0);
        }

        double a = y.getElemento(l, 0);

        if (U.getElemento(l, l) == 0)
        {
            cout << "Doolittle não conseguiu encontrar solução para o sistema\n";
            exit(1);
        }

        x.setElemento(l, 0, (y.getElemento(l, 0) - somaPosteriores) / U.getElemento(l, l));
        
        

    }


    x.printMatriz("Solucao Doolittle");
    Matriz resultado = Matriz::multiplicar(A, x);
    resultado.printMatriz("\nMatriz Ax Doolittle");

}