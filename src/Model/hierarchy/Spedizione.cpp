//
// Created by Alberto Dugo on 10/03/23.
//

#include "Spedizione.h"


int Spedizione::getTrakingNumber() const {
    return trakingNumber;
}

Address* Spedizione::getMittente() const {
    return mittente;
}

Address* Spedizione::getDestinatario() const {
    return destinatario;
}

Package* Spedizione::getPacco() const {
    return pacco;
}

Stato* Spedizione::getStato() const {
    return stato;
}

std::string Spedizione::getDescrizione() const {
    return descrizione;
}

void Spedizione::setTrakingNumber(int trakingNumber) {
    Spedizione::trakingNumber = trakingNumber;
}

void Spedizione::setMittente(Address* mittente) {
    Spedizione::mittente = mittente;
}

void Spedizione::setDestinatario(Address* destinatario) {
    Spedizione::destinatario = destinatario;
}

void Spedizione::setPacco(Package* pacco) {
    Spedizione::pacco = pacco;
}

void Spedizione::setStato(Stato* stato) {
    Spedizione::stato = stato;
}

void Spedizione::setDescrizione(const string &descrizione) {
    Spedizione::descrizione = descrizione;
}

Spedizione::Spedizione(int trakingNumber, Address *mittente, Address *destinatario,
                       Package *pacco, Stato *stato, const string &descrizione)
        : trakingNumber(trakingNumber), mittente(mittente), destinatario(destinatario), pacco(pacco), stato(stato), descrizione(descrizione) {}

Spedizione::~Spedizione() {}

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
    mittente->getNomeCognome() + SEPARATOR +
    mittente->getIndirizzo() + SEPARATOR +
    mittente->getCitta() + SEPARATOR +
    mittente->getProvincia() + SEPARATOR +
    mittente->getNazione() + SEPARATOR +
    std::to_string(mittente->getCap()) + SEPARATOR +
    destinatario->getNomeCognome() + SEPARATOR +
    destinatario->getIndirizzo() + SEPARATOR +
    destinatario->getCitta() + SEPARATOR +
    destinatario->getProvincia() + SEPARATOR +
    destinatario->getNazione() + SEPARATOR +
    std::to_string(destinatario->getCap()) + SEPARATOR +
    pacco->getContenuto() + SEPARATOR +
    std::to_string(pacco->getValore()) + SEPARATOR +
    std::to_string(pacco->getPeso()) + SEPARATOR +
    std::to_string(pacco->getVolume()) + SEPARATOR +
    stato->getDescStato() + SEPARATOR +
    stato->getFiliale().getCitta() + SEPARATOR +
    stato->getFiliale().getProvincia() + SEPARATOR +
    stato->getFiliale().getNumeroTel() + SEPARATOR +
    descrizione;
}

json Spedizione::toSaveFormat(int a) const {
    json jsonData;
    jsonData["trakingNumber"] = trakingNumber;
    jsonData["mittente"]["nomeCognome"] = mittente->getNomeCognome();
    jsonData["mittente"]["indirizzo"] = mittente->getIndirizzo();
    jsonData["mittente"]["citta"] = mittente->getCitta();
    jsonData["mittente"]["provincia"] = mittente->getProvincia();
    jsonData["mittente"]["nazione"] = mittente->getNazione();
    jsonData["mittente"]["cap"] = mittente->getCap();
    jsonData["destinatario"]["nomeCognome"] = destinatario->getNomeCognome();
    jsonData["destinatario"]["indirizzo"] = destinatario->getIndirizzo();
    jsonData["destinatario"]["citta"] = destinatario->getCitta();
    jsonData["destinatario"]["provincia"] = destinatario->getProvincia();
    jsonData["destinatario"]["nazione"] = destinatario->getNazione();
    jsonData["destinatario"]["cap"] = destinatario->getCap();
    jsonData["pacco"]["contenuto"] = pacco->getContenuto();
    jsonData["pacco"]["valore"] = pacco->getValore();
    jsonData["pacco"]["peso"] = pacco->getPeso();
    jsonData["pacco"]["volume"] = pacco->getVolume();
    jsonData["stato"]["descStato"] = stato->getDescStato();
    jsonData["stato"]["filiale"]["citta"] = stato->getFiliale().getCitta();
    jsonData["stato"]["filiale"]["provincia"] = stato->getFiliale().getProvincia();
    jsonData["stato"]["filiale"]["numeroTel"] = stato->getFiliale().getNumeroTel();
    jsonData["descrizione"] = descrizione;

    return jsonData;
}

std::vector<std::string> Spedizione::ScomposeAttribute(const std::string &str) {
    std::vector<std::string> res;

    string current = "";
    for(unsigned int i = 0; i < str.size(); i++){
        while(str[i] != SEPARATOR[0] && str[i] != '\0'){
            current += str[i];
            ++i;
        }
        res.push_back(current);
        current = "";
    }

    return res;
}

void Spedizione::copy(Spedizione *spe) {
    setMittente(spe->mittente);
    setDestinatario(spe->destinatario);
    setPacco(spe->pacco);
    setStato(spe->stato);
    setDescrizione(spe->descrizione);
}