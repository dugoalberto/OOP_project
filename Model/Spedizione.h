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
};

#endif //PROJECT_SPEDIZIONE_H
