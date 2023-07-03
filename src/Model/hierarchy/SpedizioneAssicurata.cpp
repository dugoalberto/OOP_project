//
// Created by Alberto Dugo on 11/05/2023.
//

#include "SpedizioneAssicurata.h"
std::string SpedizioneAssicurata::TypeName="SPEDIZIONEASSICURATA";
float SpedizioneAssicurata::baseCost= 14.99f;

SpedizioneAssicurata::SpedizioneAssicurata(int trakingNumber, Address *mittente, Address *destinatario, Package *pacco,
                                           Stato *stato,
                                           const string &descrizione, Assicurazione *ass, std::vector<std::string> *vec)
        : Spedizione(
        trakingNumber, mittente, destinatario, pacco, stato, descrizione), assicurazione(ass), serviziAssicurazione(vec) {

}

float SpedizioneAssicurata::getCosto() const {
    return baseCost+assicurazione->getPrezzo()*assicurazione->getNomeAssicurazione().size();
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

json SpedizioneAssicurata::toSaveFormat(int) const {
    json jsonData = Spedizione::toSaveFormat(1);

    jsonData["TypeName"] = TypeName;
    jsonData["assicurazione"] = assicurazione->getNomeAssicurazione();
    jsonData["prezzo_assicurazione"] = assicurazione->getPrezzo();
    jsonData["num_servizi_assicurazione"] = serviziAssicurazione->size();

    for (unsigned int i = 0; i < serviziAssicurazione->size(); ++i) {
        jsonData["servizi_assicurazione"][i] = serviziAssicurazione->at(i);
    }

    return jsonData;
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