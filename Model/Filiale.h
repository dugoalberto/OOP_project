//
// Created by Alberto Dugo on 10/03/23.
//

#ifndef PROJECT_FILIALE_H
#define PROJECT_FILIALE_H

#include <string>

using namespace std;

class Filiale {

private:
    string citta; //città della filiale
    string provincia; //provincia della filiale
    string numeroTel; //telefono (assistenza) della filiale

public:
    Filiale(const string &citta, const string &provincia, const string &numeroTel);
    virtual ~Filiale();

    //getter
    const string &getCitta() const;

    const string &getProvincia() const;

    const string &getNumeroTel() const;

    //setter
    void setCitta(const string &citta);

    void setProvincia(const string &provincia);

    void setNumeroTel(const string &numeroTel);

};


#endif //PROJECT_FILIALE_H
