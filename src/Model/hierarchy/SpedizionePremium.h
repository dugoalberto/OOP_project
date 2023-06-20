//
// Created by Alberto Dugo on 10/03/23.
//

#ifndef PROJECT_SPEDIZIONEPREMIUM_H
#define PROJECT_SPEDIZIONEPREMIUM_H
#include "Spedizione.h"
#include <chrono>
#include <ctime>
#include <ostream>
#include <sstream>

class SpedizionePremium: public Spedizione{
private:
    // Ottieni l'orario di oggi per confronto
    std::time_t tday = std::time(nullptr);
    std::tm now_tm = *std::localtime(&tday);

    // Inizializza l'ordine con l'orario corrente
    std::time_t ordine = std::time(nullptr);
    std::tm ordine_tm = *std::localtime(&ordine);

    // Inizializza l'orario di arrivo con il valore corrente, ma il pacchetto non arriva subito
    // Il metodo setOrario permette di impostare il valore corretto
    std::time_t arrivo = std::mktime(&now_tm);
    std::tm arrivo_tm = *std::localtime(&arrivo);

    static std::string typeName;
    static float baseCost;
public:
    SpedizionePremium() = default;
    //6.creazione, modifica e cancellazione
    SpedizionePremium(int trakingNumber, Address *mittente, Address *destinatario,
                      Package *pacco, Stato *stato, const string &descrizione, int anno = -1,
                      int meseanno= -1, int giornianno= -1, int oreanno= -1, int minutianno= -1);
    ~SpedizionePremium() override;
    void setOrario(int year, int month, int day, int hours, int minuti);
    std::vector<int> getOrario() const;

    std::string getTypeName() const;
    float getCosto() const override;
    std::string toSaveFormat() const;

    void Accept(Visitor *visitor, bool toEdit) const;

    void modifica(Spedizione *spe);
};

#endif //PROJECT_SPEDIZIONEPREMIUM_H
