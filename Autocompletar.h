#ifndef AUTOCOMPLETAR_H
#define AUTOCOMPLETAR_H

#include <iostream>
#include <vector>
#include "Lista.h"
#include "Termo.h"

class Autocompletar {
private:
    ListaOrdenada<Termo> termos;

    int buscaBinaria(const std::string& prefixo);

public:
    Autocompletar(const ListaOrdenada<Termo>& t);

    void buscar(const std::string& prefixo, int k);
};

#endif
