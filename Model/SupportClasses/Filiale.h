//
// Created by Alberto Dugo on 10/03/23.
//

#ifndef PROJECT_FILIALE_H
#define PROJECT_FILIALE_H

#include <string>
#include <ostream>
#include "../../Librerie/json.hpp"

using namespace std;
using json = nlohmann::json;

class Filiale {

private:
    string citta; //città della filiale
    string provincia; //provincia della filiale
    string numeroTel; //telefono (assistenza) della filiale

public:
    Filiale() = default;
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

    friend ostream &operator<<(ostream &os, const Filiale &filiale);

    //json
    json objectToJson();
    static Filiale jsonToObject(const json &dati);

    std::string toString() const;

};


#endif //PROJECT_FILIALE_H
