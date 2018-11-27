#ifndef SISTEMAS_H
#define SISTEMAS_H

#include "matriz.h"

class SistemasEquacoes
{
    public:
        static Matriz solucaoFatoracaoLU(Matriz A, Matriz b);
        static void solucaoDoolittle(Matriz A, Matriz b);
};

#endif //SISTEMAS_H