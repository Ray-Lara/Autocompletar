#include "Autocompletar.h"

Autocompletar::Autocompletar(const ListaOrdenada<Termo>& t) : termos(t) {}

int Autocompletar::buscaBinaria(const std::string& prefixo) {
    int esquerda = 0;
    int direita = termos.tamanho() - 1;
    int r = prefixo.size();

    while (esquerda <= direita) {
        int meio = esquerda + ((direita - esquerda) / 2);
        int cmp = Termo::compararPeloPrefixo(termos[meio], Termo(prefixo, 0), r);
        if (cmp == 0) return meio;
        if (cmp > 0) esquerda = meio + 1;
        else direita = meio - 1;
    }
    return -1;
}

void Autocompletar::buscar(const std::string& prefixo, int k) {
    termos.ordenar();  
    int indice = buscaBinaria(prefixo);
    if (indice == -1) {
        std::cout << "Nenhum termo encontrado." << std::endl;
        return;
    }

    std::vector<Termo> encontrados;
    int r = prefixo.size();

    // Procura para a esquerda
    int i = indice;
    while (i >= 0 && Termo::compararPeloPrefixo(termos[i], Termo(prefixo, 0), r) == 0) {
        encontrados.push_back(termos[i]);
        i--;
    }

    // Procura para a direita
    i = indice + 1;
    while (i < termos.tamanho() && Termo::compararPeloPrefixo(termos[i], Termo(prefixo, 0), r) == 0) {
        encontrados.push_back(termos[i]);
        i++;
    }

    // Ordena encontrados por peso
    std::sort(encontrados.begin(), encontrados.end(), [](const Termo& t1, const Termo& t2) {
        return t1.getPeso() > t2.getPeso();
    });

    for (int j = 0; j < std::min(k, static_cast<int>(encontrados.size())); j++) {
        std::cout << encontrados[j] << std::endl;
    }
}
