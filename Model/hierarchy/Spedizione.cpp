//
// Created by Alberto Dugo on 10/03/23.
//

#include "Spedizione.h"

int Spedizione::getTrakingNumber() const {
    return trakingNumber;
}

const Address &Spedizione::getMittente() const {
    return mittente;
}

const Address &Spedizione::getDestinatario() const {
    return destinatario;
}

const Package &Spedizione::getPacco() const {
    return pacco;
}

const Stato &Spedizione::getStato() const {
    return stato;
}

const string &Spedizione::getDescrizione() const {
    return descrizione;
}

void Spedizione::setTrakingNumber(int trakingNumber) {
    Spedizione::trakingNumber = trakingNumber;
}

void Spedizione::setMittente(const Address &mittente) {
    Spedizione::mittente = mittente;
}

void Spedizione::setDestinatario(const Address &destinatario) {
    Spedizione::destinatario = destinatario;
}

void Spedizione::setPacco(const Package &pacco) {
    Spedizione::pacco = pacco;
}

void Spedizione::setStato(const Stato &stato) {
    Spedizione::stato = stato;
}

void Spedizione::setDescrizione(const string &descrizione) {
    Spedizione::descrizione = descrizione;
}

Spedizione::Spedizione(int trakingNumber, const Address &mittente, const Address &destinatario,
                       const Package &pacco, const Stato &stato, const string &descrizione)
        : trakingNumber(trakingNumber), mittente(mittente), destinatario(destinatario), pacco(pacco), stato(stato), descrizione(descrizione) {}

Spedizione::~Spedizione() {}
/*
ostream &operator<<(ostream &os, const Spedizione &spedizione) {
    os << "trakingNumber: " << spedizione.trakingNumber << " \nmittente: " << spedizione.mittente << "\ndestinatario: "
       << spedizione.destinatario << "\n pacco: " << spedizione.pacco << " peso: " << spedizione.peso << " volume: "
       << spedizione.volume << " stato: " << spedizione.stato << " descrizione: " << spedizione.descrizione;
    return os;
}*/
/*
json Spedizione::objectToJson() {
    json j;
    j["trakingNumber"] = Spedizione::trakingNumber;
    j["mittente"] = Spedizione::mittente.objectToJson();
    j["destinatario"] = Spedizione::destinatario.objectToJson();
    j["pacco"] = Spedizione::pacco.objectToJson();
    j["peso"] = Spedizione::peso;
    j["volume"] = Spedizione::volume;
    j["stato"] = Spedizione::stato.objectToJson();
    j["descrizione"] = Spedizione::descrizione;
    return j;
}
*/
Spedizione::Spedizione(const Spedizione& other)
        : trakingNumber(other.trakingNumber),
          mittente(other.mittente),
          destinatario(other.destinatario),
          pacco(other.pacco),
          stato(other.stato),
          descrizione(other.descrizione)
{}

std::string Spedizione::SEPARATOR = "/";

std::string Spedizione::toSaveFormat() const{
    return
    std::to_string(trakingNumber) + SEPARATOR +
    mittente.getNomeCognome() + SEPARATOR +
    mittente.getIndirizzo() + SEPARATOR +
    mittente.getCitta() + SEPARATOR +
    mittente.getProvincia() + SEPARATOR +
    mittente.getNazione() + SEPARATOR +
    std::to_string(mittente.getCap()) + SEPARATOR +
    destinatario.getNomeCognome() + SEPARATOR +
    destinatario.getIndirizzo() + SEPARATOR +
    destinatario.getCitta() + SEPARATOR +
    destinatario.getProvincia() + SEPARATOR +
    destinatario.getNazione() + SEPARATOR +
    std::to_string(destinatario.getCap()) + SEPARATOR +
    pacco.getContenuto() + SEPARATOR +
    std::to_string(pacco.getValore()) + SEPARATOR +
    std::to_string(pacco.getPeso()) + SEPARATOR +
    std::to_string(pacco.getVolume()) + SEPARATOR +
    stato.getDescStato() + SEPARATOR +
    stato.getFiliale().getCitta() + SEPARATOR +
    stato.getFiliale().getProvincia() + SEPARATOR +
    stato.getFiliale().getNumeroTel() + SEPARATOR +
    descrizione;
}

std::vector<std::string> Spedizione::ScomposeAttribute(const std::string &str) {
    std::vector<std::string> res;

    string current = "";
    for(int i = 0; i < str.size(); i++){
        while(str[i] != SEPARATOR[0] && str[i] != '\0'){
            current += str[i];
            ++i;
        }
        res.push_back(current);
        current = "";
    }

    return res;
}
