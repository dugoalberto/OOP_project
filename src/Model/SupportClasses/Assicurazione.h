//
// Created by Alberto Dugo on 11/05/2023.
//

#ifndef DUGO_PROGETTO_ASSICURAZIONE_H
#define DUGO_PROGETTO_ASSICURAZIONE_H
#include <iostream>
#include <vector>
#include "../../App/widgets/Visitor/VisitorDialog.h"
#include "../../Librerie/json.hpp"

using json = nlohmann::json;

class Assicurazione {
private:
    std::string nomeAssicurazione;
    float prezzo;
public:
    Assicurazione(const std::string &nomeAssicurazione, float prezzo);
    json toJsonFormat() const;
    const std::string &getNomeAssicurazione() const;
    void setNomeAssicurazione(const std::string &nomeAssicurazione);
    float getPrezzo() const;
    int getNumeroServizi() const;
    void setPrezzo(float prezzo);
    virtual ~Assicurazione() {}

    void Accept(VisitorDialog*, bool = false) const;
};


#endif //DUGO_PROGETTO_ASSICURAZIONE_H
