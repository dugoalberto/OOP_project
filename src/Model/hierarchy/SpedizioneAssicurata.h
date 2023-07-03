//
// Created by Alberto Dugo on 11/05/2023.
//

#ifndef DUGO_PROGETTO_SPEDIZIONEASSICURATA_H
#define DUGO_PROGETTO_SPEDIZIONEASSICURATA_H


#include "Spedizione.h"
#include "../SupportClasses/Assicurazione.h"

class SpedizioneAssicurata : public Spedizione{
private:
    Assicurazione* assicurazione;
    static std::string TypeName;
    static float baseCost;
    std::vector<std::string>* serviziAssicurazione;

public:
    SpedizioneAssicurata(int trakingNumber, Address *mittente, Address *destinatario, Package *pacco, Stato *stato,
                         const string &descrizione, Assicurazione *ass, std::vector<std::string> *vec);

    float getCosto() const override;
    void copy(Spedizione* spe) override;
    Assicurazione* getAssicurazione() const;
    vector<std::string> *getServiziAssicurazione() const;
    void setServiziAssicurazione(vector<string> *serviziAssicurazione);
    void setAssicurazione(Assicurazione* assicurazione);
    std::string toSaveFormat() const override;
    json toSaveFormat(int) const override;
    void Accept(Visitor *visitor, bool toEdit) const;
    void Accept(VisitorForClassName*) const override;

    ~SpedizioneAssicurata() = default;
};


#endif //DUGO_PROGETTO_SPEDIZIONEASSICURATA_H
