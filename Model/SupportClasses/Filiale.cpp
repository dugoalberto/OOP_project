//
// Created by Alberto Dugo on 10/03/23.
//

#include "Filiale.h"

const string &Filiale::getCitta() const {
    return citta;
}

const string &Filiale::getProvincia() const {
    return provincia;
}

const string &Filiale::getNumeroTel() const {
    return numeroTel;
}

void Filiale::setCitta(const string &citta) {
    Filiale::citta = citta;
}

void Filiale::setProvincia(const string &provincia) {
    Filiale::provincia = provincia;
}

void Filiale::setNumeroTel(const string &numeroTel) {
    Filiale::numeroTel = numeroTel;
}

Filiale::Filiale(const string &citta, const string &provincia, const string &numeroTel): citta(citta), provincia(provincia), numeroTel(numeroTel) {}

Filiale::~Filiale() {}

ostream &operator<<(ostream &os, const Filiale &filiale) {
    os << "citta: " << filiale.citta << " provincia: " << filiale.provincia << " numeroTel: " << filiale.numeroTel;
    return os;
}

json Filiale::objectToJson() {
    json j;
    j["citta"] = Filiale::citta;
    j["provincia"] = Filiale::provincia;
    j["numeroTel"] = Filiale::numeroTel;
    return j;
}

Filiale Filiale::jsonToObject(const json &dati) {
     Filiale f(dati["citta"], dati["provincia"], dati["numeroTel"]);
     return f;
}
