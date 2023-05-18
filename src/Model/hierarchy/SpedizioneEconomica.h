//
// Created by utente on 11/05/2023.
//

#ifndef DUGO_PROGETTO_SPEDIZIONEECONOMICA_H
#define DUGO_PROGETTO_SPEDIZIONEECONOMICA_H


#include "Spedizione.h"

class SpedizioneEconomica : public Spedizione{
static std::string TypeName;
static float VOL_MAX;
static float PES_MAX;

public:
    SpedizioneEconomica(int trakingNumber, Address *mittente, Address *destinatario,
                        Package *pac, Stato *stato, const string &descrizione);
    float getCosto() const override;
    std::string toSaveFormat() const override;
    std::string getTypeName() const override;
    void Accept(Visitor *visitor, bool toEdit) const;

    ~SpedizioneEconomica() = default;
};


#endif //DUGO_PROGETTO_SPEDIZIONEECONOMICA_H
