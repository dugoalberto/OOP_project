//
// Created by Alberto Dugo on 10/03/23.
//

#ifndef PROJECT_FILIALE_H
#define PROJECT_FILIALE_H

#include <string>
#include <ostream>
#include "../../App/widgets/Visitor/VisitorDialog.h"

class Filiale {

private:
    std::string citta; //città della filiale
    std::string provincia; //provincia della filiale
    std::string numeroTel; //telefono (assistenza) della filiale

public:
    Filiale() = default;
    Filiale(const std::string &citta, const std::string &provincia, const std::string &numeroTel);
    virtual ~Filiale();

    //getter
    std::string getCitta() const;

    std::string getProvincia() const;

    std::string getNumeroTel() const;

    //setter
    void setCitta(const std::string &citta);

    void setProvincia(const std::string &provincia);

    void setNumeroTel(const std::string &numeroTel);

    friend std::ostream &operator<<(std::ostream &os, const Filiale &filiale);

    std::string toString() const;

    void Accept(VisitorDialog*, bool = false) const;

    Filiale& operator=(const Filiale&) = default;
};


#endif //PROJECT_FILIALE_H
