//
// Created by Alberto Dugo on 10/03/23.
//

#ifndef PROJECT_STATO_H
#define PROJECT_STATO_H
#include <string>
#include "Filiale.h"

class Stato{
    std::string stato; //arrivato, in filiale, in partenza
    Filiale filiale; // filiale != null && in filiale stato -> stampa filiale::getCitta
};

#endif //PROJECT_STATO_H
