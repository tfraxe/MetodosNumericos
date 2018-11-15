#include <stdlib.h>
#include <iostream>
#include "matriz.h"

using namespace std;

Matriz::Matriz(int m, int n)
{
    this->m_linhas = m;
    this->n_colunas = n;
    this->elementos_matriz = (double**)calloc(m, sizeof(double*));
    for(int i = 0; i < m; i++)
        this->elementos_matriz[i] = (double*)calloc(n, sizeof(double));
}

int Matriz::getQuantLinhas()
{
    return this->m_linhas;
}

int Matriz::getQuantColunas()
{
    return this->n_colunas;
}

double Matriz::getElemento(int linha, int coluna)
{
    return this->elementos_matriz[linha][coluna];
}

void Matriz::setElemento(int linha, int coluna, double valor)
{
    this->elementos_matriz[linha][coluna] = valor;
}

void Matriz::printMatriz(const char* texto)
{
    std::cout << texto << endl;
    for(int i = 0; i < this->m_linhas; i++)
    {
        for(int j = 0; j < this->n_colunas; j++)
            std::cout << this->getElemento(i, j) << " ";
        std::cout << endl;
    }
}

void Matriz::trocarLinha(int linha_i, int linha_j)
{
    double aux;
    for(int i = 0; i < this->n_colunas; i++)
    {
        aux = this->elementos_matriz[linha_i][i];
        this->elementos_matriz[linha_i][i] = this->elementos_matriz[linha_j][i];
        this->elementos_matriz[linha_j][i] = aux;
    }
}

void Matriz::multiplicarLinha(int linha, double k)
{
    for(int i = 0; i < this->n_colunas; i++)
        this->elementos_matriz[linha][i] *= k;
}

Matriz Matriz::multiplicar(Matriz A, Matriz B)
{
    if(A.getQuantColunas() == B.getQuantLinhas())
    {
        int m_linhas = A.getQuantLinhas();
        int n_colunas = B.getQuantColunas();
        Matriz C(m_linhas, n_colunas);
        for(int i = 0; i < m_linhas; i++)
            for(int j = 0; j < n_colunas; j++)
            {
                double valor = 0;
                for(int p = 0; p < A.getQuantColunas(); p++)
                        valor += (A.getElemento(i, p) * B.getElemento(p, j));
                C.setElemento(i, j, valor);
            }
        return C;
    }
}