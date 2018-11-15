#ifndef MATRIZ_H
#define MATRIZ_H

class Matriz
{
    private:
        int m_linhas;
        int n_colunas;
        double** elementos_matriz;

    public:
        Matriz(int m, int n);
        int getQuantLinhas();
        int getQuantColunas();
        double getElemento(int linha, int coluna);
        void setElemento(int linha, int coluna, double valor);
        void printMatriz(const char* texto);
        void trocarLinha(int linha_i, int linha_j);
        void multiplicarLinha(int linha, double k);
        static Matriz multiplicar(Matriz A, Matriz B); 
};

#endif //MATRIZ_H