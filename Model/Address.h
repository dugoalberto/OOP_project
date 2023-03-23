//
// Created by Alberto Dugo on 10/03/23.
//

#ifndef PROJECT_ADDRESS_H
#define PROJECT_ADDRESS_H

#include <string>

using namespace std;

class Address {

private:
    string nomeCognome;
    string indirizzo; // via martiri 10
    string citta;
    string provincia;
    string nazione;
    int cap;

public:
    Address(const string &nomeCognome, const string &indirizzo, const string &citta, const string &provincia, const string &nazione, int cap);
    ~Address();

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

};


#endif //PROJECT_ADDRESS_H
