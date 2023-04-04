//
// Created by Alberto Dugo on 10/03/23.
//

#ifndef PROJECT_STATO_H
#define PROJECT_STATO_H

#include <string>
#include <ostream>
#include "Filiale.h"

using namespace std;

class Stato{
private:
    string descStato; //arrivato, in filiale, in partenza, ...
    Filiale filiale; // filiale != null && in filiale stato -> stampa filiale::getCitta

public:
    Stato() = default;
    Stato(const string &descStato, const Filiale &filiale);
    virtual ~Stato();

    //getter
    const string &getDescStato() const;

    const Filiale &getFiliale() const;

    //setter
    void setDescStato(const string &descStato);

    void setFiliale(const Filiale &filiale);

    friend ostream &operator<<(ostream &os, const Stato &stato);
};

#endif //PROJECT_STATO_H
