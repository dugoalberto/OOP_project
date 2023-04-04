//
// Created by Alberto Dugo on 10/03/23.
//

#ifndef PROJECT_SPEDIZIONEPREMIUM_H
#define PROJECT_SPEDIZIONEPREMIUM_H
#include "Spedizione.h"
#include <chrono>
#include <ctime>
#include <ostream>

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

public:
    SpedizionePremium() = default;
    //6.creazione, modifica e cancellazione
    SpedizionePremium(int trakingNumber, const Address &mittente, const Address &destinatario, const Package &pacco,
                      int peso, double volume, const Stato &stato, const string &descrizione, double costo,
                      int anno, int mese, int giorni, int ore, int minuti);
    ~SpedizionePremium();
    void setOrario(int year, int month, int day, int hours, int minuti);

    friend ostream &operator<<(ostream &os, const SpedizionePremium &premium);

};

#endif //PROJECT_SPEDIZIONEPREMIUM_H
