//
// Created by utente on 11/05/2023.
//

#ifndef DUGO_PROGETTO_ASSICURAZIONE_H
#define DUGO_PROGETTO_ASSICURAZIONE_H
#include <iostream>
#include <vector>

class Assicurazione {
private:
    std::string nomeAssicurazione;
    float prezzo;
public:
    Assicurazione(const std::string &nomeAssicurazione, float prezzo);
    std::string toString() const;
    const std::string &getNomeAssicurazione() const;
    void setNomeAssicurazione(const std::string &nomeAssicurazione);
    float getPrezzo() const;
    int getNumeroServizi() const;
    void setPrezzo(float prezzo);
    virtual ~Assicurazione() {}

};


#endif //DUGO_PROGETTO_ASSICURAZIONE_H
