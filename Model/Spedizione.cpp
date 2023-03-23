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

int Spedizione::getPeso() const {
    return peso;
}

double Spedizione::getVolume() const {
    return volume;
}

const Stato &Spedizione::getStato() const {
    return stato;
}

const string &Spedizione::getDescrizione() const {
    return descrizione;
}

double Spedizione::getCosto() const {
    return costo;
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

void Spedizione::setPeso(int peso) {
    Spedizione::peso = peso;
}

void Spedizione::setVolume(double volume) {
    Spedizione::volume = volume;
}

void Spedizione::setStato(const Stato &stato) {
    Spedizione::stato = stato;
}

void Spedizione::setDescrizione(const string &descrizione) {
    Spedizione::descrizione = descrizione;
}

void Spedizione::setCosto(double costo) {
    Spedizione::costo = costo;
}

Spedizione::Spedizione(int trakingNumber, const Address &mittente, const Address &destinatario, const Package &pacco,
                       int peso, double volume, const Stato &stato, const string &descrizione, double costo)
        : trakingNumber(trakingNumber), mittente(mittente), destinatario(destinatario), pacco(pacco), peso(peso),
          volume(volume), stato(stato), descrizione(descrizione), costo(costo) {}

Spedizione::~Spedizione() {

}
