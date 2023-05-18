//
// Created by utente on 11/05/2023.
//

#include "SpedizioneEconomica.h"

class ExceptionToBig {};
class ExceptionToHeavy {};

float SpedizioneEconomica::PES_MAX = 3.0f;
float SpedizioneEconomica::VOL_MAX = 10.0f;
std::string SpedizioneEconomica::TypeName = "SPEDIZIONEECONOMICA";

SpedizioneEconomica::SpedizioneEconomica(int trakingNumber, Address *mittente, Address *destinatario,
                                         Package *pac, Stato *stato, const string &descrizione) : Spedizione(trakingNumber, mittente, destinatario,
                                                                                                             pac, stato, descrizione)
{
    pacco = pac;
    if(this->pacco->getPeso() > PES_MAX) throw ExceptionToHeavy();
    if(this->pacco->getVolume() > VOL_MAX) throw ExceptionToBig();
}

float SpedizioneEconomica::getCosto() const {
    return 20;
}

std::string SpedizioneEconomica::getTypeName() const {
    return TypeName;
}

std::string SpedizioneEconomica::toSaveFormat() const {
    return TypeName + SEPARATOR + Spedizione::toSaveFormat();
}

void SpedizioneEconomica::Accept(Visitor *visitor, bool toEdit) const {
    visitor->visit(this, toEdit);
}