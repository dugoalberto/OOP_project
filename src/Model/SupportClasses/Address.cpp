//
// Created by Alberto Dugo on 10/03/23.
//

#include "Address.h"
#include <algorithm>

const string &Address::getNomeCognome() const {
    return nomeCognome;
}

const string &Address::getIndirizzo() const {
    return indirizzo;
}

const string &Address::getCitta() const {
    return citta;
}

const string &Address::getProvincia() const {
    return provincia;
}

const string &Address::getNazione() const {
    return nazione;
}

int Address::getCap() const {
    return cap;
}

void Address::setNomeCognome(const string &nomeCognome) {
    Address::nomeCognome = nomeCognome;
}

void Address::setIndirizzo(const string &indirizzo) {
    Address::indirizzo = indirizzo;
}

void Address::setCitta(const string &citta) {
    Address::citta = citta;
}

void Address::setProvincia(const string &provincia) {
    Address::provincia = provincia;
}

void Address::setNazione(const string &nazione) {
    Address::nazione = nazione;
}

void Address::setCap(int cap) {
    Address::cap = cap;
}

Address::Address(const string &nomeCognome, const string &indirizzo, const string &citta, const string &provincia,
                 int cap,
                 const string &nazione)
        : nomeCognome(nomeCognome), indirizzo(indirizzo), citta(citta), provincia(provincia), nazione(nazione), cap(cap) {

    std::transform(this->nazione.begin(), this->nazione.end(), this->nazione.begin(), ::toupper);

}

Address::~Address() {}

ostream &operator<<(ostream &os, const Address &address) {
    os << "nomeCognome: " << address.nomeCognome << " indirizzo: " << address.indirizzo << " citta: " << address.citta
       << " provincia: " << address.provincia << " nazione: " << address.nazione << " cap: " << address.cap;
    return os;
}
