//
// Created by Alberto Dugo on 10/03/23.
//

#ifndef PROJECT_SPEDIZIONE_H
#define PROJECT_SPEDIZIONE_H

#include <string>
#include "Address.h"
#include "Package.h"
#include "Stato.h"

using namespace std;
class Spedizione {
private:
    int trakingNumber; //ID number per identificare il pacco
    Address mittente;
    Address destinatario;
    Package pacco; //contenuto, valore
    int peso; //grammi
    double volume; //volume occupata in m^3
    Stato stato; //tipologia(arrivato, filiale->PD, ..)
    string descrizione;
    double costo;
public:
    Spedizione(int trakingNumber, const Address &mittente, const Address &destinatario, const Package &pacco, int peso,
               double volume, const Stato &stato, const string &descrizione, double costo);
    //TODO distruttore con address, package, stato!!
    virtual ~Spedizione();

    //getter
    int getTrakingNumber() const;

    const Address &getMittente() const;

    const Address &getDestinatario() const;

    const Package &getPacco() const;

    int getPeso() const;

    double getVolume() const;

    const Stato &getStato() const;

    const string &getDescrizione() const;

    double getCosto() const;

    //setter
    void setTrakingNumber(int trakingNumber);

    void setMittente(const Address &mittente);

    void setDestinatario(const Address &destinatario);

    void setPacco(const Package &pacco);

    void setPeso(int peso);

    void setVolume(double volume);

    void setStato(const Stato &stato);

    void setDescrizione(const string &descrizione);

    void setCosto(double costo);


};

#endif //PROJECT_SPEDIZIONE_H
