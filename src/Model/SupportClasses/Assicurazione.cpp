//
// Created by Alberto Dugo on 11/05/2023.
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

json Assicurazione::toJsonFormat() const {
    json jsonData;
    jsonData["assicurazione"] = nomeAssicurazione;
    jsonData["prezzo"] = prezzo;
    return jsonData;
}

void Assicurazione::Accept(VisitorDialog * visitor, bool toEdit) const {
    visitor->visit(this, toEdit);
}


