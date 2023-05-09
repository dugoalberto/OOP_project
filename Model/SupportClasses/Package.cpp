//
// Created by Alberto Dugo on 10/03/23.
//

#include "Package.h"

const string &Package::getContenuto() const {
    return contenuto;
}

double Package::getValore() const {
    return valore;
}

void Package::setContenuto(const string &contenuto) {
    Package::contenuto = contenuto;
}

void Package::setValore(double valore) {
    Package::valore = valore;
}

Package::Package(const string &contenuto, double valore): contenuto(contenuto), valore(valore) {}

Package::~Package() {}

ostream &operator<<(ostream &os, const Package &aPackage) {
    os << "contenuto: " << aPackage.contenuto << " valore: " << aPackage.valore;
    return os;
}

json Package::objectToJson() {
    json j;
    j["contenuto"] = Package::contenuto;
    j["valore"] = Package::valore;
    return j;
}

Package Package::jsonToObject(const json &dati) {
    Package p(dati["contenuto"], dati["valore"]);
    return p;
}
