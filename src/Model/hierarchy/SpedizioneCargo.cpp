//
// Created by utente on 11/05/2023.
//

#include "SpedizioneCargo.h"
std::string SpedizioneCargo::TypeName = "SPEDIZIONECARGO";

SpedizioneCargo::SpedizioneCargo(int trakingNumber, const Address &mittente, const Address &destinatario,
                                 const Package &pacco, const Stato &stato, const string &descrizione,
                                 const TipologiaTrasporto &tipologiaTrasporto) : SpedizioneInternazionale(
        trakingNumber, mittente, destinatario, pacco,stato,descrizione), tipoTrasporto(tipologiaTrasporto){

}

float SpedizioneCargo::getCosto() const {
    return 100;
}

std::string SpedizioneCargo::toSaveFormat() const {
    return  TypeName + ((tipoTrasporto == TipologiaTrasporto::AEREO)? "A":"B") +
            SEPARATOR + SpedizioneInternazionale::toSaveFormat() + SEPARATOR + std::to_string(tipoTrasporto);
}

std::string SpedizioneCargo::getTypeName() const {
    return TypeName + ((tipoTrasporto == TipologiaTrasporto::AEREO)? "A":"B");
}

SpedizioneCargo::TipologiaTrasporto SpedizioneCargo::getTipologiaTrasporto() const {
    return tipoTrasporto;
}

void SpedizioneCargo::Accept(Visitor *visitor, bool toEdit) {
    visitor->visit(this, toEdit);
}