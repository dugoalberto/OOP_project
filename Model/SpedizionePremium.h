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
    /*
    std::time_t now = std::time(nullptr); //utilizzato per vedere in quanto tempo arriva il pacco
    std::tm now_tm = *std::localtime(&now);
    std::time_t orario = std::time(nullptr);
    std::tm orario_tm = *std::localtime(&orario);*/
public:
    SpedizionePremium(int trakingNumber, const Address &mittente, const Address &destinatario, const Package &pacco,
                      int peso, double volume, const Stato &stato, const string &descrizione, double costo, int year, int month, int day, int hours, int minutes);


};

#endif //PROJECT_SPEDIZIONEPREMIUM_H
