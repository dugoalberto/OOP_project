//
// Created by utente on 11/05/2023.
//

#ifndef DUGO_PROGETTO_SPEDIZIONECARGO_H
#define DUGO_PROGETTO_SPEDIZIONECARGO_H
#include "SpedizioneInternazionale.h"

class SpedizioneCargo : public SpedizioneInternazionale{
static std::string TypeName;

public:
    enum TipologiaTrasporto{
        AEREO,
        BARCA
    };
private:
    TipologiaTrasporto tipoTrasporto;
public:
    SpedizioneCargo(int trakingNumber, const Address &mittente, const Address &destinatario,
                    const Package &pacco, const Stato &stato, const string &descrizionem,
                    const TipologiaTrasporto &tipologiaTrasporto);

    TipologiaTrasporto getTipologiaTrasporto() const;
    float getCosto() const override;
    std::string toSaveFormat() const override;
    std::string getTypeName() const override;
    void Accept(Visitor *visitor, bool toEdit);

    ~SpedizioneCargo() = default;
};


#endif //DUGO_PROGETTO_SPEDIZIONECARGO_H
