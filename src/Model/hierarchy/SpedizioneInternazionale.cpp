//
// Created by Alberto Dugo on 11/05/2023.
//

#include "SpedizioneInternazionale.h"
std::string SpedizioneInternazionale::TypeName = "SPEDIZIONEINTERNAZIONALE";
float SpedizioneInternazionale::baseCost = 19.99f;

SpedizioneInternazionale::SpedizioneInternazionale(int trakingNumber, Address *mittente,
                                                   Address *destinatario,
                                                   Package *pacco, Stato *stato, const string &descrizione)
        :
        Spedizione(trakingNumber, mittente, destinatario, pacco, stato,
                   descrizione) {

}

float SpedizioneInternazionale::getCosto() const {
    return baseCost;
}

std::string SpedizioneInternazionale::toSaveFormat() const {
    return TypeName + SEPARATOR + Spedizione::toSaveFormat();
}

json SpedizioneInternazionale::toSaveFormat(int) const {
    json jsonData = Spedizione::toSaveFormat(1);

    jsonData["TypeName"] = TypeName;

    return jsonData;
}

std::string SpedizioneInternazionale::getTypeName() const {
    return TypeName;
}

void SpedizioneInternazionale::Accept(Visitor *visitor, bool toEdit) const {
    visitor->visit(this, toEdit);
}