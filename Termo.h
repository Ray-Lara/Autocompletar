#ifndef TERMO_H
#define TERMO_H

#include <iostream>
#include <string>

class Termo {
private:
    std::string termo;
    long peso;

public:
    Termo();
    Termo(std::string t, long p);

    long getPeso() const;

    static int compararPeloPeso(const Termo& T1, const Termo& T2);
    static int compararPeloPrefixo(const Termo& T1, const Termo& T2, int r);

    bool operator<(const Termo& T2) const;

    friend std::ostream& operator<<(std::ostream &out, const Termo& t);
};

#endif
