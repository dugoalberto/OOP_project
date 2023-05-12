//
// Created by utente on 11/05/2023.
//

#include "SpedizioneAssicurata.h"
std::string SpedizioneAssicurata::TypeName="SPEDIZIONEASSICURATA";

SpedizioneAssicurata::SpedizioneAssicurata(int trakingNumber, const Address &mittente, const Address &destinatario,
                                           const Package &pacco, const Stato &stato, const string &descrizione,
                                           const Assicurazione &ass) : Spedizione(
        trakingNumber, mittente, destinatario, pacco, stato, descrizione), assicurazione(ass) {

}

float SpedizioneAssicurata::getCosto() const {
    return 70+assicurazione.getPrezzo();
}

std::string SpedizioneAssicurata::getTypeName() const {
    return TypeName;
}

std::string SpedizioneAssicurata::toSaveFormat() const {
    return  TypeName + SEPARATOR + Spedizione::toSaveFormat() + SEPARATOR +
            assicurazione.getNomeAssicurazione() + SEPARATOR + to_string(assicurazione.getPrezzo());
}

void SpedizioneAssicurata::Accept(Visitor *visitor, bool toEdit) {
    visitor->visit(this, toEdit);
}
