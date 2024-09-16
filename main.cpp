#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Lista.h"
#include "Termo.h"
#include "Autocompletar.h"


int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Uso: " << argv[0] << " <arquivo_dataset> <k>" << std::endl;
        return 1;
    }

    std::ifstream arquivo(argv[1]);
    int k = std::stoi(argv[2]);

    if (!arquivo) {
        std::cerr << "Erro ao abrir o arquivo" << std::endl;
        return 1;
    }

    ListaOrdenada<Termo> termos;
    std::string linha;

    while (std::getline(arquivo, linha)) {
        std::istringstream iss(linha);
        long peso;
        std::string termo;

        std::string pesoString;
        std::getline(iss, pesoString, '\t');
        peso = std::stol(pesoString);

        std::getline(iss, termo);

        if (termo.empty()) {
            std::cerr << "Erro ao ler o termo" << std::endl;
            exit(1);
        }

        termos.inserir(Termo(termo, peso));
        
    }
    
    Autocompletar autocomplete(termos);
    std::string consulta;
    while (true) {
        std::cout << "Qual o termo a ser procurado? (digite \"sair\" para encerrar o programa): ";
        std::getline(std::cin, consulta);
        if (consulta == "sair") break;

        autocomplete.buscar(consulta, k);
    }

    return 0;
}
