//
// Created by utente on 11/05/2023.
//

#include "SpedizioneAssicurata.h"
std::string SpedizioneAssicurata::TypeName="SPEDIZIONEASSICURATA";

SpedizioneAssicurata::SpedizioneAssicurata(int trakingNumber, Address *mittente, Address *destinatario, Package *pacco,
                                           Stato *stato,
                                           const string &descrizione, Assicurazione *ass, std::vector<std::string> *vec)
        : Spedizione(
        trakingNumber, mittente, destinatario, pacco, stato, descrizione), assicurazione(ass), serviziAssicurazione(vec) {

}

float SpedizioneAssicurata::getCosto() const {
    return 70+assicurazione->getPrezzo()*assicurazione->getNomeAssicurazione().size();
}

std::string SpedizioneAssicurata::getTypeName() const {
    return TypeName;
}

std::string SpedizioneAssicurata::toSaveFormat() const {
    std::string res =   TypeName + SEPARATOR + Spedizione::toSaveFormat() + SEPARATOR +
                        assicurazione->getNomeAssicurazione() + SEPARATOR +
                        to_string(assicurazione->getPrezzo()) + SEPARATOR +
                        to_string(serviziAssicurazione->size());

    for(unsigned int i = 0; i < serviziAssicurazione->size(); ++i){
        res += SEPARATOR;
        res += serviziAssicurazione->at(i);
    }

    return res;
}

void SpedizioneAssicurata::Accept(Visitor *visitor, bool toEdit) const{
    visitor->visit(this, toEdit);
}

Assicurazione* SpedizioneAssicurata::getAssicurazione() const {
    return assicurazione;
}

vector<std::string> *SpedizioneAssicurata::getServiziAssicurazione() const {
    return serviziAssicurazione;
}

void SpedizioneAssicurata::setServiziAssicurazione(vector<string> *serviziAssicurazione) {
    SpedizioneAssicurata::serviziAssicurazione = serviziAssicurazione;
}

void SpedizioneAssicurata::setAssicurazione(Assicurazione* ass){
    assicurazione = ass;
}

void SpedizioneAssicurata::modifica(Spedizione *spe) {
    Spedizione::modifica(spe);
    setAssicurazione(dynamic_cast<SpedizioneAssicurata*>(spe)->getAssicurazione());
    setServiziAssicurazione(dynamic_cast<SpedizioneAssicurata*>(spe)->getServiziAssicurazione());
}