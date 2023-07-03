//
// Created by Alberto Dugo on 11/05/2023.
//

#include "SpedizioneCargo.h"
std::string SpedizioneCargo::TypeName = "SPEDIZIONECARGO";
float SpedizioneCargo::baseCost= 200.00f;

SpedizioneCargo::SpedizioneCargo(int trakingNumber, Address *mittente, Address *destinatario,
                                 Package *pacco, Stato *stato, const string &descrizione,
                                 const TipologiaTrasporto &tipologiaTrasporto) : SpedizioneInternazionale(
        trakingNumber, mittente, destinatario, pacco,stato,descrizione), tipoTrasporto(tipologiaTrasporto){

}

float SpedizioneCargo::getCosto() const {
    return baseCost;
}

std::string SpedizioneCargo::toSaveFormat() const {
    return  TypeName + ((tipoTrasporto == TipologiaTrasporto::AEREO)? "A":"B") +
            SEPARATOR + SpedizioneInternazionale::toSaveFormat() + SEPARATOR + std::to_string(tipoTrasporto);
}

json SpedizioneCargo::toSaveFormat(int) const {
    json jsonData = SpedizioneInternazionale::toSaveFormat(1);

    jsonData["TypeName"] =  TypeName + ((tipoTrasporto == TipologiaTrasporto::AEREO)? "A":"B");
    jsonData["tipo_trasporto"] = static_cast<int>(tipoTrasporto);

    return jsonData;
}

SpedizioneCargo::TipologiaTrasporto SpedizioneCargo::getTipologiaTrasporto() const {
    return tipoTrasporto;
}

void SpedizioneCargo::Accept(Visitor *visitor, bool toEdit) const {
    visitor->visit(this, toEdit);
}

void SpedizioneCargo::Accept(VisitorForClassName *visitor) const {
    visitor->visit(this);
}

void SpedizioneCargo::copy(Spedizione *spe) {
    Spedizione::copy(spe);
    tipoTrasporto = dynamic_cast<SpedizioneCargo*>(spe)->tipoTrasporto;
}