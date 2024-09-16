#include "Termo.h"

Termo::Termo() : termo(""), peso(0) {}

Termo::Termo(std::string t, long p) : termo(t), peso(p) {}

long Termo::getPeso() const {
    return peso;
}

int Termo::compararPeloPeso(const Termo& T1, const Termo& T2) {
    if (T1.peso > T2.peso) return 1;
    if (T1.peso == T2.peso) return 0;
    return -1;
}

int Termo::compararPeloPrefixo(const Termo& T1, const Termo& T2, int r) {
    std::string prefixo1 = T1.termo.substr(0, r);
    std::string prefixo2 = T2.termo.substr(0, r);
    if (prefixo1 > prefixo2) return 1;
    if (prefixo1 == prefixo2) return 0;
    return -1;
}

bool Termo::operator<(const Termo& T2) const {
    return this->termo < T2.termo;
}

std::ostream& operator<<(std::ostream &out, const Termo& t) {
    out << t.peso << "\t" << t.termo;
    return out;
}
