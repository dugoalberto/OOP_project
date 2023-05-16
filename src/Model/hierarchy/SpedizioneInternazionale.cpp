//
// Created by utente on 11/05/2023.
//

#include "SpedizioneInternazionale.h"
std::string SpedizioneInternazionale::TypeName = "SPEDIZIONEINTERNAZIONALE";

SpedizioneInternazionale::SpedizioneInternazionale(int trakingNumber, const Address &mittente,
                                                   const Address &destinatario,
                                                   const Package &pacco, const Stato &stato, const string &descrizione)
        :
        Spedizione(trakingNumber, mittente, destinatario, pacco, stato,
                   descrizione) {

}

float SpedizioneInternazionale::getCosto() const {
    return 75;
}

std::string SpedizioneInternazionale::toSaveFormat() const {
    return TypeName + SEPARATOR + Spedizione::toSaveFormat();
}

std::string SpedizioneInternazionale::getTypeName() const {
    return TypeName;
}

void SpedizioneInternazionale::Accept(Visitor *visitor, bool toEdit) {
    visitor->visit(this, toEdit);
}