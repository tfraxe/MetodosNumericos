#include <stdlib.h>
#include "sistemas.h"

Matriz SistemasEquacoes::solucaoFatoracaoLU(Matriz A, Matriz b)
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
            double m = U.getElemento(i, k) / pivo;
            L.setElemento(i, k, m);
            for(int j = k; j < colunas; j++)
            {
                double valor = U.getElemento(i, j);
                U.setElemento(i, j, valor - (m * U.getElemento(k, j)));
            }        
        }    
    }
    Matriz c = Matriz::multiplicar(P, b);
    Matriz y(3, 1);
    for(int i = 0; i < linhas; i++)
    {
        double soma = 0;
        for(int j = 0; j < i; j++)
            soma += (L.getElemento(i, j) * y.getElemento(j, 0));
        y.setElemento(i, 0, c.getElemento(i, 0) - soma);
    }
    Matriz x(3, 1);
    for(int i = linhas - 1; i >= 0; i--)
    {
        double soma = 0;
        for(int j = i + 1; j < linhas; j++)
            soma += (U.getElemento(i, j) * x.getElemento(j, 0));
        x.setElemento(i, 0, (y.getElemento(i, 0) - soma) / U.getElemento(i, i));
    }
    A.printMatriz("Matriz A");
    b.printMatriz("Matriz b");
    x.printMatriz("Matriz solucao x");
    Matriz resultado = Matriz::multiplicar(A, x);
    resultado.printMatriz("Matriz Ax");
}

Matriz SistemasEquacoes::solucaoDoolittle(Matriz A, Matriz b)
{

}