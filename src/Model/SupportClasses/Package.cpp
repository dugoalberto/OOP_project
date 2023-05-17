//
// Created by Alberto Dugo on 10/03/23.
//

#include "Package.h"

const string &Package::getContenuto() const {
    return contenuto;
}

float Package::getValore() const {
    return valore;
}

void Package::setContenuto(const string &contenuto) {
    Package::contenuto = contenuto;
}

void Package::setValore(float valore) {
    Package::valore = valore;
}

Package::Package(const string &contenuto, float valore, float vol, float pes) : contenuto(contenuto), valore(valore), volume(vol), peso(pes) {}

Package::~Package() {}

ostream &operator<<(ostream &os, const Package &aPackage) {
    os << "contenuto: " << aPackage.contenuto << " valore: " << aPackage.valore;
    return os;
}



float Package::getVolume() const {
    return volume;
}

void Package::setVolume(float volume) {
    Package::volume = volume;
}

float Package::getPeso() const {
    return peso;
}

void Package::setPeso(float peso) {
    Package::peso = peso;
}
