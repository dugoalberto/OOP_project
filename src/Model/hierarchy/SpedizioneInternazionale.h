//
// Created by Alberto Dugo on 11/05/2023.
//

#ifndef DUGO_PROGETTO_SPEDIZIONEINTERNAZIONALE_H
#define DUGO_PROGETTO_SPEDIZIONEINTERNAZIONALE_H


#include "Spedizione.h"

class SpedizioneInternazionale : public Spedizione{
static std::string TypeName;
static float baseCost;

public:
    SpedizioneInternazionale(int trakingNumber, Address *mittente, Address *destinatario,
                             Package *pacco, Stato *stato, const string &descrizione);
    float getCosto() const override;
    std::string toSaveFormat() const override;
    json toSaveFormat(int) const override;
    void Accept(Visitor *visitor, bool toEdit) const;
    void Accept(VisitorForClassName *visitor) const;

    ~SpedizioneInternazionale() = default;
};


#endif //DUGO_PROGETTO_SPEDIZIONEINTERNAZIONALE_H
