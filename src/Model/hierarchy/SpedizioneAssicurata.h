//
// Created by utente on 11/05/2023.
//

#ifndef DUGO_PROGETTO_SPEDIZIONEASSICURATA_H
#define DUGO_PROGETTO_SPEDIZIONEASSICURATA_H


#include "Spedizione.h"
#include "../SupportClasses/Assicurazione.h"

class SpedizioneAssicurata : public Spedizione{
private:
    Assicurazione assicurazione;
    static std::string TypeName;
public:
    SpedizioneAssicurata(int trakingNumber, const Address &mittente, const Address &destinatario,
                         const Package &pacco, const Stato &stato, const string &descrizione,
                         const Assicurazione &ass);

    float getCosto() const override;
    std::string getTypeName() const override;
    std::string toSaveFormat() const override;
    void Accept(Visitor *visitor, bool toEdit);

    ~SpedizioneAssicurata() = default;
};


#endif //DUGO_PROGETTO_SPEDIZIONEASSICURATA_H
