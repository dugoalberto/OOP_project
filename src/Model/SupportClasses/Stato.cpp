//
// Created by Alberto Dugo on 10/03/23.
//

#include "Stato.h"

const string &Stato::getDescStato() const {
    return descStato;
}

const Filiale &Stato::getFiliale() const {
    return filiale;
}

void Stato::setDescStato(const string &descStato) {
    Stato::descStato = descStato;
}

void Stato::setFiliale(const Filiale &filiale) {
    Stato::filiale = filiale;
}

Stato::Stato(const string &descStato, const Filiale &filiale): descStato(descStato), filiale(filiale) {}

Stato::~Stato() {}

ostream &operator<<(ostream &os, const Stato &stato) {
    os << "descStato: " << stato.descStato << "\nfiliale: " << stato.filiale;
    return os;
}
