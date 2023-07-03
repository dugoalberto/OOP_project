//
// Created by Alberto Dugo on 10/03/23.
//

#ifndef PROJECT_SPEDIZIONE_H
#define PROJECT_SPEDIZIONE_H

#include <string>
#include <ostream>
#include "../SupportClasses/Address.h"
#include "../SupportClasses/Package.h"
#include "../SupportClasses/Stato.h"
#include "../../App/widgets/Visitor/Visitor.h"
#include "../../Librerie/json.hpp"
#include "../../App/widgets/Visitor/VisitorForClassName.h"

using json = nlohmann::json;
using namespace std;

class Spedizione {
protected:
    int trakingNumber; //ID number per identificare il pacco
    Address* mittente;
    Address* destinatario;
    Package* pacco; //contenuto, valore
    Stato* stato; //tipologia(arrivato, filiale->PD, ..)
    string descrizione;
    static std::string SEPARATOR;
public:
    Spedizione() = default;
    Spedizione(int trakingNumber, Address *mittente, Address *destinatario,
               Package *pacco, Stato *stato, const string &descrizione);
    Spedizione(const Spedizione& other);
    virtual ~Spedizione();

    virtual float getCosto() const = 0;
    virtual void copy(Spedizione* spe);

    //getter
    int getTrakingNumber() const;

    Address* getMittente() const;

    Address* getDestinatario() const;

    Package* getPacco() const;

    Stato* getStato() const;

    std::string getDescrizione() const;

    //setter
    void setTrakingNumber(int trakingNumber);

    void setMittente(Address* mittente);

    void setDestinatario(Address* destinatario);

    void setPacco(Package* pacco);

    void setStato(Stato* stato);

    void setDescrizione(const string &descrizione);

    virtual std::string toSaveFormat() const;
    virtual json toSaveFormat(int) const;
    static std::vector<string> ScomposeAttribute(const std::string&);
    virtual void Accept(Visitor *visitor, bool toEdit) const = 0;
    virtual void Accept(VisitorForClassName*) const = 0;
};

#endif //PROJECT_SPEDIZIONE_H
