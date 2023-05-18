//
// Created by utente on 11/05/2023.
//

#include "Assicurazione.h"

Assicurazione::Assicurazione(const std::string &nomeAssicurazione, float prezzo)
        : nomeAssicurazione(nomeAssicurazione), prezzo(prezzo){

}

const std::string &Assicurazione::getNomeAssicurazione() const {
    return nomeAssicurazione;
}

void Assicurazione::setNomeAssicurazione(const std::string &nomeAssicurazione) {
    Assicurazione::nomeAssicurazione = nomeAssicurazione;
}

float Assicurazione::getPrezzo() const {
    return prezzo;
}

void Assicurazione::setPrezzo(float prezzo) {
    Assicurazione::prezzo = prezzo;
}

std::string Assicurazione::toString() const {
    return nomeAssicurazione + "|" + std::to_string(prezzo);
}


