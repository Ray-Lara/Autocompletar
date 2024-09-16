#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
class Lista {
protected:
    std::vector<T> linha;

public:
    void inserir(const T& item) {
        linha.push_back(item);
    }

    int tamanho() const {
        return linha.size();
    }

    T& operator[](int index) {
        return linha[index];
    }

    void imprimir() const {
        for (const auto& item : linha) {
            std::cout << item << std::endl;
        }
    }
};

template <typename T>
class ListaOrdenada : public Lista<T> {
public:
  
void ordenar(int (*comparar)(T, T)) {
    for (size_t i = 1; i < this->linha.size(); i++) {
        T chave = this->linha[i];
        int j = i - 1;
        while (j >= 0 && comparar(this->linha[j], chave) > 0) {
            this->linha[j + 1] = this->linha[j];
            j--;
        }
        this->linha[j + 1] = chave;
    }
}


void ordenar() {
    std::sort(this->linha.begin(), this->linha.end(), [](const T& a, const T& b) {
        return b < a;
    });
}
};

#endif