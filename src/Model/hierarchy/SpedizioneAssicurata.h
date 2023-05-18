//
// Created by utente on 11/05/2023.
//

#ifndef DUGO_PROGETTO_SPEDIZIONEASSICURATA_H
#define DUGO_PROGETTO_SPEDIZIONEASSICURATA_H


#include "Spedizione.h"
#include "../SupportClasses/Assicurazione.h"

class SpedizioneAssicurata : public Spedizione{
private:
    Assicurazione* assicurazione;
    static std::string TypeName;
    std::vector<std::string>* serviziAssicurazione;

public:
    SpedizioneAssicurata(int trakingNumber, Address *mittente, Address *destinatario, Package *pacco, Stato *stato,
                         const string &descrizione, Assicurazione *ass, std::vector<std::string> *vec);

    float getCosto() const override;
    void modifica(Spedizione* spe) override;
    std::string getTypeName() const override;
    Assicurazione* getAssicurazione() const;
    vector<std::string> *getServiziAssicurazione() const;
    void setServiziAssicurazione(vector<string> *serviziAssicurazione);
    void setAssicurazione(Assicurazione* assicurazione);
    std::string toSaveFormat() const override;
    void Accept(Visitor *visitor, bool toEdit) const;

    ~SpedizioneAssicurata() = default;
};


#endif //DUGO_PROGETTO_SPEDIZIONEASSICURATA_H
