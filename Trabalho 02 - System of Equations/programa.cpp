#include <iostream>
#include "matriz.h"
#include "sistemas.h"

using namespace std;

int main(int argc, char* argv[])
{
    system("clear");
    int n;
    cout << "Insira a quantidade de reacoes quimicas" << endl;
    scanf("%d", &n);
    Matriz A(n, n);
    Matriz b(n, 1);
    for(int i = 0; i < n; i++)
    {
        std::cout << endl << "Insira os coeficientes da " << i + 1 << " reacao" << endl;
        for(int j = 0; j < n; j++)
        {
            double coef;
            scanf("%lf", &coef);
            A.setElemento(i, j, coef);
        }
        std::cout << "Agora o valor dessa reacao" << endl;
        double valor;
        scanf("%lf", &valor);
        b.setElemento(i, 0, valor);
    }
    system("clear");
    SistemasEquacoes::solucaoFatoracaoLU(A, b);
    SistemasEquacoes::solucaoDoolittle(A, b);
    return 0;
}