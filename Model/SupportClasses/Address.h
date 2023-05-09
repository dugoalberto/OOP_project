//
// Created by Alberto Dugo on 10/03/23.
//

#ifndef PROJECT_ADDRESS_H
#define PROJECT_ADDRESS_H

#include <string>
#include <ostream>
#include "../../Librerie/json.hpp"

using namespace std;
using json = nlohmann::json;

class Address {

private:
    string nomeCognome;
    string indirizzo; // via martiri 10
    string citta;
    string provincia;
    string nazione;
    int cap;
public:
    Address() = default;
    Address(const string &nomeCognome, const string &indirizzo, const string &citta, const string &provincia, const string &nazione, int cap);
    virtual ~Address();

    //getter
    const string &getNomeCognome() const;

    const string &getIndirizzo() const;

    const string &getCitta() const;

    const string &getProvincia() const;

    const string &getNazione() const;

    int getCap() const;

    //setter
    void setNomeCognome(const string &nomeCognome);

    void setIndirizzo(const string &indirizzo);

    void setCitta(const string &citta);

    void setProvincia(const string &provincia);

    void setNazione(const string &nazione);

    void setCap(int cap);

    friend ostream &operator<<(ostream &os, const Address &address);

    //json
    json objectToJson();
    static Address jsonToObject(const json &dati);
};


#endif //PROJECT_ADDRESS_H
