//
// Created by Alberto Dugo on 10/03/23.
//

#ifndef PROJECT_SPEDIZIONEPREMIUM_H
#define PROJECT_SPEDIZIONEPREMIUM_H
#include "Spedizione.h"
#include <chrono>
#include <ctime>

class SpedizionePremium: public Spedizione{
private:
    // ottieni l'orario corrente
    std::time_t ordine = std::time(nullptr); //utilizzato per vedere in quanto tempo arriva il pacco, ordine è l'orario nel quale è stato ordinata la spedizione
    std::tm ordine_tm = *std::localtime(&ordine);
    std::time_t arrivo = std::time(nullptr); //orario è in secondi dall'epoch
    std::tm arrivo_tm = *std::localtime(&arrivo);

public:
    SpedizionePremium(int trakingNumber, const Address &mittente, const Address &destinatario, const Package &pacco,
                      int peso, double volume, const Stato &stato, const string &descrizione, double costo,
                      int anno, int mese, int giorni, int ore, int minuti);

    void setOrario(int year, int month, int day, int hours, int minuti);
};

#endif //PROJECT_SPEDIZIONEPREMIUM_H
