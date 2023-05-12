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
#include "../../Librerie/json.hpp"
#include "../../App/widgets/Visitor/Visitor.h"

using namespace std;
using json = nlohmann::json;

class Spedizione {
protected:
    int trakingNumber; //ID number per identificare il pacco
    Address mittente;
    Address destinatario;
    Package pacco; //contenuto, valore
    Stato stato; //tipologia(arrivato, filiale->PD, ..)
    string descrizione;
    static std::string SEPARATOR;
public:
    Spedizione() = default;
    Spedizione(int trakingNumber, const Address &mittente, const Address &destinatario,
               const Package &pacco, const Stato &stato, const string &descrizione);
    Spedizione(const Spedizione& other);
    virtual ~Spedizione();

    virtual float getCosto() const = 0;

    //getter
    int getTrakingNumber() const;

    const Address &getMittente() const;

    const Address &getDestinatario() const;

    const Package &getPacco() const;

    const Stato &getStato() const;

    const string &getDescrizione() const;

    //setter
    void setTrakingNumber(int trakingNumber);

    void setMittente(const Address &mittente);

    void setDestinatario(const Address &destinatario);

    void setPacco(const Package &pacco);

    void setStato(const Stato &stato);

    void setDescrizione(const string &descrizione);

    friend ostream &operator<<(ostream &os, const Spedizione &spedizione);

    //json
    //json objectToJson();
    //virtual Spedizione* jsonToObject(const json &dati) {};

    virtual std::string getTypeName() const = 0;
    virtual std::string toSaveFormat() const;
    static std::vector<string> ScomposeAttribute(const std::string&);
    virtual void Accept(Visitor *visitor, bool toEdit) = 0;

};

#endif //PROJECT_SPEDIZIONE_H
