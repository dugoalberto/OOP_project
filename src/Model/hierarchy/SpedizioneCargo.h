//
// Created by Alberto Dugo on 11/05/2023.
//

#ifndef DUGO_PROGETTO_SPEDIZIONECARGO_H
#define DUGO_PROGETTO_SPEDIZIONECARGO_H
#include "SpedizioneInternazionale.h"

class SpedizioneCargo : public SpedizioneInternazionale{
static std::string TypeName;
static float baseCost;

public:
    enum TipologiaTrasporto{
        AEREO,
        BARCA
    };
private:
    TipologiaTrasporto tipoTrasporto;
public:
    SpedizioneCargo(int trakingNumber, Address *mittente, Address *destinatario,
                    Package *pacco, Stato *stato, const string &descrizione,
                    const TipologiaTrasporto &tipologiaTrasporto);

    TipologiaTrasporto getTipologiaTrasporto() const;
    float getCosto() const override;
    void modifica(Spedizione*) override;
    std::string toSaveFormat() const override;
    json toSaveFormat(int) const override;
    std::string getTypeName() const override;
    void Accept(Visitor *visitor, bool toEdit) const;

    ~SpedizioneCargo() = default;
};


#endif //DUGO_PROGETTO_SPEDIZIONECARGO_H
