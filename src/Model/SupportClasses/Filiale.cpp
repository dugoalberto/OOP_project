//
// Created by Alberto Dugo on 10/03/23.
//

#include "Filiale.h"

std::string Filiale::getCitta() const {
    return citta;
}

std::string Filiale::getProvincia() const {
    return provincia;
}

std::string Filiale::getNumeroTel() const {
    return numeroTel;
}

void Filiale::setCitta(const std::string &citta) {
    Filiale::citta = citta;
}

void Filiale::setProvincia(const std::string &provincia) {
    Filiale::provincia = provincia;
}

void Filiale::setNumeroTel(const std::string &numeroTel) {
    Filiale::numeroTel = numeroTel;
}

Filiale::Filiale(const std::string &citta, const std::string &provincia, const std::string &numeroTel): citta(citta), provincia(provincia), numeroTel(numeroTel) {}

Filiale::~Filiale() {}

std::ostream &operator<<(std::ostream &os, const Filiale &filiale) {
    os << "citta: " << filiale.citta << " provincia: " << filiale.provincia << " numeroTel: " << filiale.numeroTel;
    return os;
}

std::string Filiale::toString() const {
    return citta + "|" + provincia + "|" + numeroTel;
}

void Filiale::Accept(VisitorDialog* visitor, bool toEdit) const {
    visitor->visit(this,toEdit);
}
